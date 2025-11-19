# IoT Applications Course - M1

## Project Overview

This course requires each group to develop an innovative IoT application using the provided hardware and software stack.

### Hardware
- **Microcontrollers**: ESP32, Arduino Nano 33 IoT
- **Server**: Raspberry Pi 4 with IoTStack or PC with [IoT Stack](https://github.com/josephazar/IOT-UMLP-2026)
- **Sensors**: Temperature, humidity, accelerometer, etc.

### Communication Protocols
- **Mandatory**: MQTT
- **Required**: At least one additional protocol (HTTP, TCP, WebSocket, or BLE)

### Software Stack
- **Arduino IDE** for ESP32 and Arduino Nano 33 IoT
- **Node-RED** for automation tasks (minimum 4 tasks)
- **InfluxDB** for data storage (mandatory)
- **Grafana** for visualization (mandatory)
- **NodeJS/Express** (optional, if needed)

## Project Requirements

1. **Project Idea**: Brief description of your application/use case
2. **Data Collection**: Strategies for gathering sensor data
3. **Communication**: Implementation of multiple protocols
4. **Data Processing & Storage**: Methods for processing and storing data
5. **Visualization**: Grafana dashboards
6. **Automation Tasks**: At least 4 Node-RED automation tasks
7. **Challenges & Solutions**: Anticipated challenges and proposed solutions

## Evaluation Criteria

- **Innovation**: Originality of project idea
- **Complexity**: Effective use of hardware/software stack
- **Integration**: Seamless component integration
- **Teamwork**: Coordination and task distribution
- **Presentation**: Clarity in explaining architecture and data flow
- **GitHub Repo**: Well-documented repository

## Extra Credit Opportunities

- Additional sensors beyond DHT11 and accelerometer
- BLE communication between ESP32 and Arduino
- Google Sheets/Firebase integration
- Email alerts for abnormal conditions
- Mobile app for real-time monitoring and control
- Webcam integration with Node-RED

## Important: Dataset Creation for ML Course

**Additional Task**: Your project must generate a clean, well-structured dataset that will be used in the second semester course "Machine Learning for IoT".

### Dataset Requirements

- **Format**: CSV or JSON files with clear column headers
- **Quality**: Clean data with proper timestamps, no missing values
- **Documentation**: Include a data dictionary explaining each field
- **Volume**: Sufficient data points for ML training (aim for at least several hours/days of continuous data)
- **Labels**: If applicable, include labeled data for supervised learning tasks

### What to Prepare

1. Export your InfluxDB data to a portable format
2. Document the data collection methodology
3. Describe potential ML use cases for your dataset (e.g., anomaly detection, prediction, classification)

**Note**: You must explain your dataset and its potential ML applications during the final session presentation.

## Presentation

**Date**: Last session in December

- Prepare a clear demo of your system
- Do not leave preparation for the last minute
- Be ready to explain architecture, data flow, and all functionalities
