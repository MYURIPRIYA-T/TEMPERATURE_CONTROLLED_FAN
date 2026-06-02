# TEMPERATURE_CONTROLLED_FAN
📌 Description

This project is a temperature controlled fan system using Arduino and DHT11 sensor. The fan speed is automatically controlled using PWM based on real-time temperature readings. It helps in efficient energy usage and smart cooling applications.

⚙️ Features
Real-time temperature monitoring
Automatic fan speed control using PWM
Low, medium, and high speed modes
Simple and efficient embedded system
🛠️ Components Used
Arduino UNO / Nano
DHT11 Temperature & Humidity Sensor
DC Fan
MOSFET / Transistor
Jumper wires
Breadboard
🔌 Working Principle

The DHT11 sensor measures temperature and sends data to Arduino. Based on temperature value, Arduino generates PWM signals to control fan speed automatically.

📊 Temperature Logic
Below 25°C → Fan OFF / LOW speed
25°C – 30°C → Medium speed
Above 30°C → High speed
💻 Technologies Used
Arduino IDE
Embedded C
PWM Control
Sensor Interfacing
🚀 How It Works
Read temperature from DHT11 sensor
Process temperature value in Arduino
Generate PWM signal based on temperature range
Control fan speed automatically
📁 Project Structure
FAN-PWM-DHT11/
 ├── code/
 ├── circuit_diagram/
 ├── README.md
📌 Applications
Smart home cooling system
Electronic device cooling
Energy-efficient fan systems
IoT based automation projects
⭐ Output

Fan speed changes automatically according to temperature variation.

📜 License

This project is for educational purposes.
