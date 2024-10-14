# Smart Home Temperature Monitoring System

## Overview
This is a simple **Smart Home Temperature Monitoring System** that monitors room temperature using an Arduino, a DHT11 sensor, and a WiFi Shield. The system captures temperature and humidity data and sends it to the **ThingSpeak** cloud platform for real-time monitoring.

## Project Details

### Components:
- **Arduino Uno**: Main microcontroller to process data.
- **DHT11 Sensor**: Used to measure temperature and humidity.
- **OSOYOO Uart WiFi Shield v1.3**: Facilitates Wi-Fi communication for sending data to the cloud.
  
### Key Features:
- **Temperature and Humidity Monitoring**: The system reads real-time temperature and humidity levels.
- **Cloud Integration with ThingSpeak**: Data is uploaded to ThingSpeak every 20 seconds for live visualization.
- **Real-time Dashboard**: Allows users to monitor changes in room conditions via the ThingSpeak dashboard.

## Hardware Setup
![temp](https://github.com/user-attachments/assets/d4667e92-852d-4d09-a390-c6f17402c99e)

The hardware setup consists of:
- **Arduino Uno** connected to the **OSOYOO WiFi Shield**.
- The **DHT11 sensor** is connected to the Arduino to measure temperature and humidity.
  - GND of sensor is connected to the **ground** pin of the Arduino.
  - VCC of sensor is connected to the **power** pin of Arduino.
  - S of sensor is connected to **Digital Pin 2** of Arduino for data collection.

## Cloud Integration
After compiling and uploading the code to the Arduino board, it reads temperature data and sends it to the cloud, where real-time data is shown on my ThingSpeak dashboard.
![tempcloud](https://github.com/user-attachments/assets/7bf70823-6f25-449f-9650-1822b39a5c41)
