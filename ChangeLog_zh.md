# 更新

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