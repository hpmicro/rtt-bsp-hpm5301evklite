# Change Log

## v1.11.0

- Integrated hpm_sdk v1.11.0
- Upgraded RT-Thread to v5.2.2
- Added RT-Thread standard dynamic interrupt registration mechanism, supporting flexible switching between static binding and dynamic management modes
- Added support for generic startup files, while maintaining compatibility with existing startup methods

- Updated:
  - Switched CherryUSB stack from package support to RT-Thread component driver support
  - Enhanced UART V2 driver
  - Enhanced MCAN driver
  - Enhanced CAN driver

- Added:
  - Added Software I2C driver
  - Added Software SPI driver
  - UART V2 driver added PUART support
  - TMR driver added PTMR support

## v1.10.0

- Integrated hpm_sdk v1.10.0

- Updated:
  - Upgrade `CherryUSB` stack to 1.5.0

- Added:
  - Support zcc compiler
  - Support SEGGER Embedded Studio IDE, version 8.24

- Fixed:
  - Fix the issue that the vectored interrupt mode may not work properly in some conditions
  - Fix the issue that WDOG reset failed to work after executing `reset` command in shell

## v1.9.0

- Integrated hpm_sdk v1.9.0

- Updated:
  - Upgrade `CherryUSB` stack to 1.4.3
  - `uart/uart_v2` driver supports configurable IRQ priority
  - `spi` driver supports for configurable IRQ priority for
  - `i2c` driver support for configurable IRQ priority
  - `gpio` driver support for configurable IRQ priority
  - `mcan` driver supports configurable IRQ priority

- Added:
  - DSPI/QSPI mode added for `spi` driver

## v1.6.0

- Integrated hpm_sdk v1.6.0
- Updated:
  - Optimized the control of `BRS` bit in CANFD frame
  - Upgraded the `cherryUSB` stack to v1.3.1
  - Added USB descriptor for Full-speed mode to USB examples
  - Upgraded the SoC Datasheet
- Fixed:
  - Macro definition errors related to  TX DMA for UART7 & UART7
  - Memory leakage issue in uart_v2 driver
- Added:
  - SPI CS pin control option
  - Adapted RT-Thread Cache API

## v1.5.0

- Integrated hpm_sdk v1.5.0
- Updated:
  - usb stack switched to cherryUSB for usb samples
- Added:
  - added interrupt vector mode and preemptive mode
  - systemView component

## 1.4.1

- Fixed:
  - Transmission error while enabling DMA in I2C driver
  - Failed to create template project

## v1.4.0

- Integrated hpm_sdk v1.4.0
- Upgraded RT-Thread to v5.0.2
- Added examples:
  - adc_example
  - blink_led
  - timer_demo
  - flashdb_demo
  - uart_dma_demo
  - usb_device_generic_hid
  - usb_host_msc_udisk
