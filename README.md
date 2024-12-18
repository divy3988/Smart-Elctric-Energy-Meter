# Smart-Elctric-Energy-Meter
This Smart Energy Meter project uses ESP32 for IoT-based monitoring. It integrates ACS712 and ZMPT101B sensors for current and voltage measurement, providing real-time data via Wi-Fi. The document includes components, connection diagrams, code, flowcharts, and results, showcasing efficient energy tracking and control.
This project demonstrates an IoT-based Smart Energy Meter using the ESP32 microcontroller. It measures current, voltage, and power consumption and provides real-time monitoring through a Wi-Fi-enabled web interface.

Features
Measures AC current and voltage using ACS712 and ZMPT101B sensors.
Calculates power consumption.
Real-time data monitoring via a web interface.
Lightweight and cost-effective IoT solution.
Components
ESP32: Microcontroller with built-in Wi-Fi and Bluetooth.
ACS712 Sensor: Current measurement.
ZMPT101B Sensor: Voltage measurement.
Setup
Hardware: Connect ESP32 to ACS712 and ZMPT101B sensors as per the provided connection diagram.
Software:
Install the Arduino IDE.
Install ESP32 board package and required libraries like ACS712.
Code:
Update the Wi-Fi credentials in the code.
Upload the code to the ESP32.
Usage
Power on the setup and connect to the specified Wi-Fi network.
Access the web interface via the ESP32's IP address.
View real-time current, voltage, and power readings on the webpage.
Flowchart
Refer to the flowchart in the documentation for an overview of the operational process.

Results
The system accurately displays current, voltage, and power consumption on the web interface, demonstrating its effectiveness in energy monitoring.

References
ESP32 Tutorials
ACS712 Datasheet
ZMPT101B Datasheet
License
This project is for educational purposes. Please refer to the respective licenses of the libraries used.

