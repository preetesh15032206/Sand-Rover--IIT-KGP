# Sand Rover – Bluetooth Controlled 4WD Robot

## Project Description
The Sand Rover is a four-wheel drive robotic system designed for navigation over sandy and uneven terrain. It uses an Arduino-based control unit, dual L298N motor drivers, and a differential drive mechanism for precise movement, including zero-radius turning. The rover supports real-time command execution and variable speed control via Bluetooth.

## Project Demo
- Demo Video 1:
https://drive.google.com/file/d/16UF5yHHpZey8Y7N1IxHJIu9uE1eP83sS/view?usp=sharing

- Demo Video 2:
https://drive.google.com/file/d/1XiHO2b232I3Vcm_BwpqPtpTxU2mndn8a/view?usp=sharing

## Features
- Four-wheel independent drive system  
- Zero-radius turning using differential motor control  
- Bluetooth-based wireless control (HC-05)  
- Real-time command execution  
- Variable speed control  
- Expandable support for lights and auxiliary outputs  

## Hardware Components
- Arduino Uno  
- HC-05 Bluetooth Module  
- 2 × L298N Motor Drivers  
- 4 × High Torque DC Motors (300 RPM)  
- Off-road wheels  
- LiPo Battery  

## System Architecture
Mobile Application → Bluetooth (HC-05) → Arduino → Motor Drivers → Motors

## Control Commands
F: Forward  
B: Backward  
L: Left  
R: Right  
G: Forward Left  
I: Forward Right  
H: Back Left  
J: Back Right  
S: Stop  
D: Emergency Stop  

Speed: 0–9, q  

## Circuit Connections

### HC-05
- VCC → 5V  
- GND → GND  
- TX → Arduino RX  
- RX → Arduino TX (via voltage divider)

### Motor Drivers
Driver 1 (Left Motors):
- IN1 → Pin 2  
- IN2 → Pin 3  
- IN3 → Pin 4  
- IN4 → Pin 5  
- ENA → Pin 6  
- ENB → Pin 9  

Driver 2 (Right Motors):
- IN1 → Pin 7  
- IN2 → Pin 8  
- IN3 → Pin 12  
- IN4 → Pin 13  

