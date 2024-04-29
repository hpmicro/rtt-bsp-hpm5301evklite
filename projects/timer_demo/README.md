# 简介

本例程演示基于RT-Thread驱动框架的 hwtimer和ewdt驱动

## 演示的功能

- ewdt 复位(HPM5301支持EWDT驱动，不支持WDT驱动)
- hwtimer 周期性中断

## 支持的命令

```console
RT-Thread shell commands:
clear            - clear the terminal screen
version          - show RT-Thread version information
list             - list objects
help             - RT-Thread shell help.
ps               - List threads in the system.
free             - Show the memory usage in the system.
pin              - pin [option]
reset            - reset the board
hwtimer_sample   - hwtimer_sample
wdt_sample       - wdt sample
wdt_reset        - wdt reset
```

其中：

- hwtimer_sample 开启一个5s的周期性事件
- wdt_sample开启看门狗
- wdt_reset 停止看门狗，看门狗会在约1秒后复位
