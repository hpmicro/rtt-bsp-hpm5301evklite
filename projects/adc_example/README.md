# 简介

本示例演示了基于RT-Thread ADC驱动框架的ADC数据的读取。

## 示例展示的功能

- ADC单次转换

## 准备工作

- 该运行前需要给ADC0.INA11引脚（PB08,J3-5）一个输入电压，adc demo会通过控制台打印采样到的电压值
  -注意: 
    - 输入电压范围为0-3.3v,超出范围可能会损坏芯片
    - 3.3V 测量可使用J3-1
    - GND 测量可使用J3-6
    - 参考 HPM5300EVKlite_RevB
  

## 运行示例
编译程序并下载，若程序被正确的执行，则调试串口会输出如下信息：
```console
 \ | /
- RT -     Thread Operating System
 / | \     5.0.1 build Jul 28 2023 17:17:20
 2006 - 2022 Copyright by RT-Thread team
msh >
```

按 `TAB` 键会输出如下命令：

### RT-Thread命令

```console
RT-Thread shell commands:
clear            - clear the terminal screen
version          - show RT-Thread version information
list             - list objects
help             - RT-Thread shell help.
ps               - List threads in the system.
free             - Show the memory usage in the system.
adc              - adc [option]
pin              - pin [option]
reset            - reset the board
monitor_voltage  - Monitor Pin volatge

```
测试时请使用 `monitor_voltage` 命令。当命令被正确执行后，例程会循环演示：
- ADC 单次转换
