# (WIP) ESP32 Accelerometer-Based Sensor with Wireless Display Integration
## Overview

This project involves the development of a compact, low-power sensor unit using an ESP32 microcontroller integrated with an accelerometer and powered by a 3.7V LiPo cell, which can be charged using solar energy. The sensor unit wirelessly transmits data over BLE. The system is designed for measuring the cadence when riding a bicycle for live telemetry, with low energy consumption and a tiny form factor.

## Features

- ESP32-Based Sensor Unit: Equipped with an accelerometer to capture motion data.
- Power Options: 3.7V LiPo.
- Charging Options: USB or Solar
- Wireless Data Transmission: Utilizes Bluetooth Low Energy (BLE) for communication between the sensor unit and the display unit.
- Low Power Consumption: Optimized for energy efficiency, suitable for long-term operation on minimal power. The device will go into sleep mode in case of inactivity.

## Components

- ESP32-S3-WROOM-1 Microcontroller: The core of the system, handling both sensor data collection and wireless communication.
- ICM-42670-P Accelerometer: Detects and measures acceleration in three axes.
- BQ25570 BMS: For voltage regulation for the circuit and battery charging.

## Setup and Installation

- Hardware Setup
  - Assemble the ESP32 with the accelerometer and choose either the button cell or solar cell for power.
  - Connect to ESP32 with Bluetooth.

- Software Setup
  - Flash the ESP32 with the provided codebase.
  - The sensor unit will continuously monitor the accelerometer data and send it via BLE to the display unit.
  - The display unit will process and visualize the received data.

## Usage

- The sensor unit will send data, and the display unit will show the live accelerometer readings.

## PCB Design

Below is the image of the PCB design, showcasing the layout of the components for the sensor unit.

![kicad svg](https://github.com/user-attachments/assets/401d53cf-95a8-4a6a-aca1-311d3592edb3)

## Future Improvements

- Integration of additional sensors (e.g., gyroscope).
- Enhanced power management strategies for longer battery life.
- Expansion to support multiple sensor units communicating with a single display.
