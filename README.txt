奔腾激光基础平台（Rayray-RT版）说明书
Penta Laser Base Platform (Rayray-RT)
=

1. 平台组成
- TOPPERS/ASP3 3.5
- TECS 1.7.0
- LWIP 2.1.2 (ETH & WIFI)
- FatFs R0.07a
- TLSF 2.4.6
- TMC-API
- ESP32 WIFI Firmware

2. 开发环境
- Windows 10 + Cygwin
- Ubuntu 18.04
- Atollic TrueSTUDIO® for STM32
详见SetupGuide.txt。

3. 平台接口
- ITRON
- stdio
- posix file library
- dynamic memory
- posix socket library
- motor library
- task monitor
- device command

4. 开发指南
4.1 开发流程
a) 输入系统设计需求
b) BSP Driver开发
c) task monitor调试
d) device command调试
e) 与设备相关的tecs设计
f) 与业务相关的tecs设计
g) 任务设计
h) 单元测试tecs设计

4.2 开发文档
a) 电子与软件设计（方案）
b) 控制软件开发计划（概要）
c) 控制软件需求
d) 控制软件测试用例
f) 控制软件组件图

5. 应用实例
5.1 奔腾激光切割头
5.2 ...


