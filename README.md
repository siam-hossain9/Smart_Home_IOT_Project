# Smart Home Automation System Using Arduino

This project is a simple smart home system built using Arduino. It features an automatic door that opens when someone is nearby and a rain detection system that pulls back clothes when rain is detected.

## Features

- 🚪 **Automatic Door System**:  
  Uses an ultrasonic sensor and servo motor to open the door when a person is within 30 cm. A buzzer alerts during the opening.

- 🌧️ **Rain Detection System**:  
  Uses a rain sensor to detect rainfall and pulls back clothes using another servo motor.

## Components Used

- Arduino UNO  
- Ultrasonic Sensor (HC-SR04)  
- Raindrop Sensor  
- 2x Servo Motors  
- Buzzer  
- Jumper Wires, Breadboard  

## Pin Connections

| Component           | Arduino Pin |
|--------------------|-------------|
| Trig (Ultrasonic)  | 2           |
| Echo (Ultrasonic)  | 3           |
| Buzzer             | 4           |
| Door Servo         | 5           |
| Rain Sensor (D0)   | 6           |
| Clothes Servo      | 7           |

## How to Use

1. Upload the code to your Arduino UNO.
2. Connect the components as per the pin connections.
3. The door opens automatically when someone is close.
4. If it rains, the clothes servo motor will pull clothes back.

---

