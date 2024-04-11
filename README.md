# 基于STM32 HAL库使用 Wit C SDK 读取 JY901x 姿态传感器数据

## 简介

在这个示例中，我们将使用 Wit C SDK 以及 JY901x 姿态传感器，通过 I2C 接口读取传感器的原始数据，并将其解析为姿态数据。

## 准备工作

在开始之前，确保你已经准备好以下环境和材料：

- JY901x 姿态传感器
- STM32 开发板（或其他支持的设备）
- 连接线
- 一台电脑

## 步骤

1. **硬件连接**

   将 JY901x 姿态传感器通过 I2C 连接到你的 STM32 开发板上。
   代码中使用的为IIC2，
   ```
    PF0     ------> I2C2_SDA
    PF1     ------> I2C2_SCL
    ```
2. **下载 Wit C SDK**

   从 [Wit Motion 官方网站](https://github.com/WITMOTION/WitIIC_JY901) 下载最新的 Wit C SDK，并将其集成到你的项目中。

3. **初始化 Wit SDK**

   在你的代码中，初始化 Wit SDK，并设置协议类型和设备地址为 JY901x 姿态传感器的地址。

4. **读取传感器数据**

   使用 Wit SDK 提供的函数，通过 I2C 接口读取 JY901x 姿态传感器的原始数据。可以读取加速度、角速度等数据。

5. **解析数据**

   解析从传感器读取的原始数据，获取姿态数据，如俯仰角、横滚角、偏航角等。

6. **使用姿态数据**

   将解析得到的姿态数据用于你的应用程序，如姿态控制、导航等。

## 结论

提供基于HAL库的Wit JY901x 姿态传感器读取姿态示例。希望这个示例能够帮助你在自己的项目中成功应用姿态传感器！

## Reference ：

[Wit Motion 私有协议](https://github.com/WITMOTION/WitIIC_JY901)

[Wit JY901B 姿态传感器文档](https://wit-motion.yuque.com/wumwnr/docs/sozgn8?singleDoc#%20%E3%80%8AJY901B%E4%BA%A7%E5%93%81%E8%B5%84%E6%96%99%E3%80%8B)

