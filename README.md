# Smart-Attendance-System-IoT-based-
This Smart Attendance System leverages RFID technology to automate attendance tracking in various environments. Using a NodeMCU microcontroller and an RC522 RFID reader, the system efficiently registers attendance via RFID cards and tags.

## Table of Contents

- [Introduction](#introduction)
- [Scope of Project](#scopeofproject)
- [About the project](#abouttheproject)
- [Components Required](#componentsrequired)
- [Circuit Diagram](#circuitdiagram)
- [Connecting DHT11 with Arduino UNO](#connectingDHT11witharduinoUNO)
- [Working of Project](#WorkingofProject)
- [Installation](#installation)
- [Contact](#contact)

## Introduction

The Smart Attendance System is a robust and automated solution designed to streamline attendance tracking using RFID technology. Built on the NodeMCU ESP8266 platform and integrated with Firebase, this system enables seamless attendance logging by scanning RFID cards or tags. The project features a real-time display of attendance status on an I2C LCD, making it user friendly and efficient for various environments such as offices, labs and educational institutions. By leveraging cloud based storage, it ensures secure and reliable data management, allowing for easy retrieval and analysis of attendance records.

This project serves as a scalable, modern solution that eliminates the need for manual attendance management, providing a highly efficient system for real-time tracking.


## Features

- **Real-Time Attendance Monitoring:** Automatically logs attendance when an RFID card is scanned.
- **Instant Feedback:** Displays the attendance status on an I2C LCD display.
- **Cloud Storage:** Attendance data is stored in Firebase for easy retrieval and analysis.
- **Scalable Design:** The system can be adapted for various environments like offices, libraries, and labs.

## Components Required

- NodeMCU (ESP8266)
- RC522 RFID Reader
- RFID Cards and Tags
- I2C LCD Display (16x2)
- Jumper Wires
- Breadboard
- USB to type C cable
- Firebase Account

## Circuit Diagram

![circuit](https://github.com/user-attachments/assets/2ef07c8b-809c-4945-bb97-77c68fcb2296)


## Connecting NodeMCU with RC522

To set up the NodeMCU with the RC522 RFID reader, make the following connections:

| RC522 Pins  | NodeMCU Pins  |
|-------------|---------------|
| VCC         | 3V3           |
| GND         | GND           |
| RST         | D3 (GPIO 0)   |
| IRQ         | Not Connected |
| MISO        | D6 (GPIO 12)  |
| MOSI        | D7 (GPIO 13)  |
| SCK         | D5 (GPIO 14)  |
| SDA         | D4 (GPIO 2)   |

For the **I2C LCD Display**, make the following connections:

| I2C LCD Pins | NodeMCU Pins  |
|--------------|---------------|
| VCC          | 3V3           |
| GND          | GND           |
| SDA          | D2 (GPIO 4)   |
| SCL          | D1 (GPIO 5)   |


## Working of Project

1. **RFID Scanning:** When an RFID card or tag is scanned by the RC522 reader, the system identifies the unique ID of the card.
2. **Attendance Logging:** The NodeMCU processes the card's ID and logs the corresponding attendance entry in Firebase.
3. **LCD Display:** The I2C LCD display and website shows a message confirming the success or failure of the scan.
4. **Cloud Sync:** Data is sent and stored in Firebase for further analysis and retrieval.

## Installation

To get started with the project, follow these steps:

1. Clone the repository:
   
   ```bash
   git clone https://github.com/yourusername/smart-attendance-system.git
   cd smart-attendance-system
 
2. Install Arduino IDE:

- Download and install the Arduino IDE.

3. Install Required Libraries:

- Open the Arduino IDE.
- Go to **'Sketch'** > **'Include Library'** > **'Manage Libraries'**.
- Search for and install the following libraries:
  - **MFRC522** (for RFID communication)
  - **ESP8266WiFi** (for connecting to WiFi)
  - **FirebaseESP8266** (for Firebase integration)
  - **LiquidCrystal_I2C** (for controlling the LCD display)
  
4. Configure Firebase:

- Create a Firebase account and set up a project.
- Get the API key and Database URL from Firebase.
- Update the code with your Firebase credentials.
  
5. Upload Code to NodeMCU:

- Connect your NodeMCU to your computer using a USB cable.
- Select the correct board (NodeMCU 1.0) and port from **'Tools'** > **'Board'** and **'Tools'** > **'Port'**.
- Click on the **'Upload'** button to upload the code to the NodeMCU.
   
## Contact
If you have any questions or suggestions, feel free to open an issue or contact:
Dhrishita Parve: dhrishitap18@gmail.com
