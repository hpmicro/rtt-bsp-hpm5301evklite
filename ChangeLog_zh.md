# 更新

## v1.9.0

- 整合了 hpm_sdk v1.9.0

- 更新：
    - 升级CherryUSB协议栈到1.4.3
    - `uart/uart_v2`驱动支持可配置的IRQ优先级
    - `spi`驱动支持可配置的IRQ优先级
    - `i2c`驱动支持可配置的IRQ优先级
    - `gpio`驱动支持可配置的IRQ优先级
    - `mcan`驱动支持可配置的IRQ优先级

- 新增:
    - `spi`驱动增加DSPI/QSPI模式

## v1.6.0

- 整合了hpm_sdk v1.6.0
- 修复:
    - UART7 和 UART8 TX DMA 相关的宏定义错误问题
    - uart_v2中的内存泄露问题
- 更新：
    - 优化CANFD帧的BRS位控制
    - 升级CherryUSB协议栈到1.3.1
    - 为USB例程增加了全速模式相关的描述符
    - 芯片的数据手册
- 新增:
    - SPI 的CS引脚控制选项
    - 适配了RT-Thread Cache 驱动

## v1.5.0

- 整合了hpm_sdk v1.5.0
- 更新:
    - USB相关sample协议栈切换为cherryUSB
- 新增:
    - 增加中断向量模式和可抢占模式
    - systemView组件

## v1.4.1
- 修复：
  - I2C开启DMA后传输出错的问题
  - 默认模板工程创建出错的问题

## v1.4.0
- 整合了hpm_sdk v1.4.0
- RT-Thread升级到v5.0.2
- 增加了如下示例:
  - adc_example
  - blink_led
  - timer_demo
  - flashdb_demo
  - uart_dma_demo
  - usb_device_generic_hid
  - usb_host_msc_udisk