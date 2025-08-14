# esp32

### ESP-IDF
https://docs.espressif.com/projects/esp-idf/zh_CN/stable/esp32/get-started/index.html

### demo1
https://www.nmking.io/index.php/2022/09/13/112/

### To AWS-IOT
https://github.com/espressif/esp-aws-iot

### setup
https://docs.espressif.com/projects/esp-techpedia/zh_CN/latest/esp-friends/get-started/environment-setup.html

### code framework
https://docs.espressif.com/projects/esp-techpedia/zh_CN/latest/esp-friends/get-started/code-development.html

### JTAG
https://docs.espressif.com/projects/esp-idf/zh_CN/latest/esp32/api-guides/jtag-debugging/index.html#jtag








## Other
ESP32 是一款由乐鑫（Espressif）开发的低成本、低功耗的微控制器平台，集成了 Wi-Fi 和蓝牙功能，广泛用于物联网（IoT）项目。与 ESP32 相似的平台有以下几种，具备类似的功能（如 Wi-Fi、蓝牙、双核处理器等）或适用于类似的应用场景：

### 1. **乐鑫系列的其他芯片**
   - **ESP8266**  
     - 简介：ESP32 的前身，乐鑫早期推出的低成本 Wi-Fi 微控制器。
     - 相似点：支持 Wi-Fi，适用于 IoT 项目，价格低廉。
     - 不同点：无蓝牙功能，单核处理器，性能低于 ESP32，内存和 GPIO 较少。
     - 适用场景：简单的 Wi-Fi 连接项目，如智能家居设备。
   - **ESP32-S2 / ESP32-S3 / ESP32-C3**  
     - 简介：ESP32 的变种，针对不同需求优化。
     - 相似点：支持 Wi-Fi，部分型号支持蓝牙，开发环境与 ESP32 类似（基于 ESP-IDF 或 Arduino）。
     - 不同点：
       - ESP32-S2：单核，无蓝牙，增强了 USB 支持。
       - ESP32-S3：双核，支持 AI 加速，适合需要高性能的项目。
       - ESP32-C3：单核 RISC-V 架构，成本更低，适合小型 IoT 设备。
     - 适用场景：根据具体需求选择，如低功耗（C3）或高性能（S3）。

### 2. **Raspberry Pi Pico W**
   - 简介：Raspberry Pi 基金会的微控制器，配备 Wi-Fi（基于 RP2040 芯片）。
   - 相似点：支持 Wi-Fi，价格低廉，适合 IoT 和嵌入式开发。
   - 不同点：无蓝牙（基础版 Pico 无 Wi-Fi 和蓝牙），RP2040 是双核 Cortex-M0+ 架构，性能和 ESP32 略有差异，GPIO 数量较少。
   - 适用场景：简单的 IoT 项目，教育用途，MicroPython 开发。

### 3. **Arduino Nano 33 IoT / Arduino MKR 系列**
   - 简介：Arduino 推出的支持 Wi-Fi 和蓝牙的开发板，基于 SAMD21 或其他芯片。
   - 相似点：支持 Wi-Fi 和蓝牙，易于使用 Arduino IDE 开发，适合 IoT 项目。
   - 不同点：处理器性能低于 ESP32，价格较高，功耗稍高。
   - 适用场景：需要 Arduino 生态系统支持的项目，快速原型开发。

### 4. **STM32 系列 + 无线模块**
   - 简介：STMicroelectronics 的 STM32 微控制器（如 STM32F4、STM32L4）搭配 Wi-Fi/蓝牙模块（如 ESP-01 或外部蓝牙模块）。
   - 相似点：高性能处理器，支持复杂应用，可通过外接模块实现 Wi-Fi 和蓝牙。
   - 不同点：需要额外模块实现无线功能，开发复杂度和成本高于 ESP32。
   - 适用场景：需要高性能计算的工业或嵌入式系统。

### 5. **Nordic nRF52 系列**
   - 简介：Nordic Semiconductor 的微控制器，专注于低功耗蓝牙（BLE），如 nRF52840。
   - 相似点：支持蓝牙 5.0，部分型号支持 Thread/Zigbee，适合低功耗 IoT 应用。
   - 不同点：Wi-Fi 需外接模块，处理器性能和 ESP32 相当，但开发生态不如 ESP32 广泛。
   - 适用场景：低功耗蓝牙设备，如可穿戴设备、传感器网络。

### 6. **Texas Instruments CC32xx 系列**
   - 简介：TI 的 CC3220 或 CC3235，集成了 Wi-Fi 和蓝牙（部分型号）。
   - 相似点：支持 Wi-Fi 和蓝牙，低功耗设计，适合 IoT 应用。
   - 不同点：价格较高，开发工具链不如 ESP32 友好，社区支持较少。
   - 适用场景：需要高安全性的 IoT 设备（如智能电表）。

### 7. **Microchip AVR-IoT / PIC-IoT**
   - 简介：Microchip 推出的支持 Wi-Fi 的开发板，基于 AVR 或 PIC 架构。
   - 相似点：支持 Wi-Fi，适合小型 IoT 项目，开发工具链成熟。
   - 不同点：蓝牙支持较弱，性能和 ESP32 相比稍逊，价格较高。
   - 适用场景：Microchip 生态系统的用户，工业控制。

### 总结比较
| 平台              | Wi-Fi | 蓝牙 | 处理器        | 价格 | 开发难度 | 社区支持 |
|-------------------|-------|------|---------------|------|----------|----------|
| ESP32             | 是    | 是   | 双核 Xtensa   | 低   | 低       | 强       |
| ESP8266           | 是    | 否   | 单核 Xtensa   | 极低 | 低       | 强       |
| Raspberry Pi Pico W | 是  | 否   | 双核 RP2040   | 低   | 低       | 强       |
| Arduino Nano 33 IoT | 是  | 是   | SAMD21       | 中   | 低       | 强       |
| Nordic nRF52840   | 否    | 是   | Cortex-M4     | 中   | 中       | 中       |
| TI CC32xx         | 是    | 部分 | Cortex-M4     | 高   | 中       | 弱       |
| STM32 + 模块      | 需模块 | 需模块 | Cortex-M 系列 | 中高 | 高       | 中       |

### 选择建议
- **预算有限、需要 Wi-Fi 和蓝牙**：ESP32 是首选，性价比高，社区支持广泛。
- **仅需 Wi-Fi、超低成本**：ESP8266 适合简单项目。
- **低功耗蓝牙应用**：Nordic nRF52 系列更适合。
- **高性能计算**：STM32 搭配无线模块，或 ESP32-S3。
- **Arduino 生态**：Arduino Nano 33 IoT 或 MKR 系列。
- **教育用途或 MicroPython**：Raspberry Pi Pico W。

如果你有具体的项目需求（如低功耗、特定协议支持、开发语言偏好等），可以提供更多细节，我可以帮你进一步筛选合适的平台！