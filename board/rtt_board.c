/*
 * Copyright (c) 2021 - 2022 hpmicro
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "board.h"
#include "rtt_board.h"
#include "hpm_uart_drv.h"
#include "hpm_gpio_drv.h"
#include "hpm_pmp_drv.h"
#include "assert.h"
#include "hpm_clock_drv.h"
#include "hpm_sysctl_drv.h"
#include <rthw.h>
#include <rtthread.h>
#include "hpm_dma_mgr.h"
#include "hpm_rtt_os_tick.h"
#include "hpm_l1c_drv.h"

extern int rt_hw_uart_init(void);

void rtt_os_tick_clock(void)
{
#ifdef HPM_USING_VECTOR_PREEMPTED_MODE
    clock_add_to_group(BOARD_OS_TIMER_CLK_NAME, 0);
#else
    clock_add_to_group(clock_mchtmr0, 0);
#endif
}

void rtt_board_init(void)
{
    rtt_os_tick_clock();
    board_init_clock();
    board_init_console();
    board_init_pmp();

    dma_mgr_init();

    /* initialize memory system */
    rt_system_heap_init(RT_HW_HEAP_BEGIN, RT_HW_HEAP_END);

    /* Configure the OS Tick */
    os_tick_config();

    /* Configure the USB pins*/
    board_init_usb(HPM_USB0);

    /* Initialize the UART driver first, because later driver initialization may require the rt_kprintf */
    rt_hw_uart_init();

    /* Set console device */
    rt_console_set_device(RT_CONSOLE_DEVICE_NAME);
}

void app_init_led_pins(void)
{
    gpio_set_pin_output(BOARD_LED_GPIO_CTRL, BOARD_LED_GPIO_INDEX, BOARD_LED_GPIO_PIN);
    gpio_write_pin(BOARD_LED_GPIO_CTRL, BOARD_LED_GPIO_INDEX, BOARD_LED_GPIO_PIN, BOARD_LED_OFF_LEVEL);
}

void app_led_write(uint32_t index, bool state)
{
   gpio_write_pin(BOARD_LED_GPIO_CTRL, BOARD_LED_GPIO_INDEX, BOARD_LED_GPIO_PIN, state);
}


void BOARD_LED_write(uint32_t index, bool state)
{
    switch (index)
    {
    case 0:
        gpio_write_pin(BOARD_LED_GPIO_CTRL, BOARD_LED_GPIO_INDEX, BOARD_LED_GPIO_PIN, state);
        break;
    default:
        /* Suppress the toolchain warnings */
        break;
    }
}

void rt_hw_console_output(const char *str)
{
    while (*str != '\0')
    {
        uart_send_byte(BOARD_APP_UART_BASE, *str++);
    }
}

void app_init_usb_pins(void)
{
    board_init_usb(HPM_USB0);
}

void rt_hw_cpu_reset(void)
{
    HPM_PPOR->RESET_ENABLE = (1UL << 31);

    HPM_PPOR->SOFTWARE_RESET = 1000U;
    while(1) {

    }
}

MSH_CMD_EXPORT_ALIAS(rt_hw_cpu_reset, reset, reset the board);

#ifdef RT_USING_CACHE
void rt_hw_cpu_dcache_ops(int ops, void *addr, int size)
{
    if (ops == RT_HW_CACHE_FLUSH) {
        l1c_dc_flush((uint32_t)addr, size);
    } else {
        l1c_dc_invalidate((uint32_t)addr, size);
    }
}
#endif

uint32_t rtt_board_init_adc16_clock(ADC16_Type *ptr, bool clk_src_ahb)
{
    uint32_t freq = 0;

    if (ptr == HPM_ADC0) {
        if (clk_src_ahb) {
            /* Configure the ADC clock from AHB (@200MHz by default)*/
            clock_set_adc_source(clock_adc0, clk_adc_src_ahb0);
        } else {
            /* Configure the ADC clock from pll0_clk0 divided by 2 (@200MHz by default) */
            clock_set_adc_source(clock_adc0, clk_adc_src_ana0);
            clock_set_source_divider(clock_ana0, clk_src_pll0_clk2, 2U);
        }
        clock_add_to_group(clock_adc0, 0);
        freq = clock_get_frequency(clock_adc0);
    }

    return freq;
}

