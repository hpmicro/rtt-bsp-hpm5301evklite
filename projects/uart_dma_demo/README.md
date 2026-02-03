# 简介

本示例演示了基于RT-Thread 串口V2驱动框架的串口的的数据发送和接收。

## 提示
- 该例程中的串口波特率使用rtthread默认115200
- 本示例使用DMA + RX空闲检测进行数据收发
  - **架构**: DMA自动搬运数据,RX空闲中断触发数据处理
  - **发送**: DMA直接从发送缓冲区搬运到UART,CPU仅处理完成中断
  - **接收**: MA循环模式 + Ping-Pong缓冲 + RX空闲检测,支持不定长接收

## 示例展示的功能

- 串口的发送和接收，串口接收到的PC串口助手的数据会返回给PC串口助手。

## 硬件设置
* 使用USB转TTL模块连接到开发板对应的串口引脚

| 功能       | 位置   |  引脚  |
| ----------| ------ | ------ |
| UART3.TXD | J3[8]  | PB[15] |
| UART3.RXD | J3[10] | PB[14] |

### RT-Thread命令

```console
RT-Thread shell commands:
uart_dma_sample  - uart device dma sample
reset            - reset the board
clear            - clear the terminal screen
version          - show RT-Thread version information
list             - list objects
help             - RT-Thread shell help.
ps               - List threads in the system.
free             - Show the memory usage in the system.
pin              - pin [option]
```
测试时请使用 `uart_dma_sample` 命令

## 运行现象
```console
 \ | /
- RT -     Thread Operating System
 / | \     5.0.1 build Jul 28 2023 10:58:35
 2006 - 2022 Copyright by RT-Thread team
msh >
msh >
msh >
msh >uart_dma_sample
msh >
msh >hello RT-Thread!
hello RT-Thread!
```




