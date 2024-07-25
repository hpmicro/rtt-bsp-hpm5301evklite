# Change Log

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