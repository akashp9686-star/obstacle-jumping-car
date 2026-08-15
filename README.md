# Obstacle-Avoiding Car (Arduino)

An autonomous car built with an Arduino Uno R3 that detects obstacles using an ultrasonic sensor mounted on a servo, and automatically steers around them.

## Components Used

- Arduino Uno R3
- L298N motor driver shield
- HC-05 Bluetooth module
- 4x DC motors
- HC-SR04 ultrasonic distance sensor
- SG90 (or similar) servo motor
- Chassis, wheels, battery pack, jumper wires

## How It Works

1. The servo holds the ultrasonic sensor facing forward and continuously measures the distance to any obstacle ahead.
2. If the distance drops below 15 cm, the car stops.
3. The servo sweeps to 45° to check the left side for a clear path.
4. Based on that reading, the car turns left or right to avoid the obstacle, then resumes.
5. If the path ahead is clear, the car keeps moving forward.

## Pin Connections

| Component          | Arduino Pin |
| ------------------- | ------------ |
| Ultrasonic Trig      | 9            |
| Ultrasonic Echo      | 10           |
| Motor Driver IN1     | 2            |
| Motor Driver IN2     | 3            |
| Motor Driver IN3     | 4            |
| Motor Driver IN4     | 5            |
| Servo signal          | 6            |

> **Note:** The current sketch runs the car fully autonomously — it doesn't yet read commands from the HC-05 module. If you want Bluetooth remote control (e.g. via an Android app) alongside or instead of the obstacle-avoidance logic, that part still needs to be added (reading `Serial` data from HC-05 and mapping commands to `moveForward()`, `turnLeft()`, etc.).

## Getting Started

1. Install the [Arduino IDE](https://www.arduino.cc/en/software).
2. Install the **Servo** library (usually bundled by default; if not, install via Library Manager).
3. Open `obstacle_avoiding_car.ino` in the Arduino IDE.
4. Select **Board: Arduino Uno** and the correct COM port.
5. Upload the sketch.
6. Open the Serial Monitor at 9600 baud to view live distance readings.

## Wiring Diagram

*(Add a photo or diagram of your wiring here — drag an image into this README on GitHub, or add it to an `images/` folder and reference it, e.g. `![wiring](images/wiring.jpg)`)*

## Possible Improvements

- Add HC-05 Bluetooth control to switch between autonomous and manual modes
- Use a PID-based or weighted turning decision instead of a simple threshold
- Add a rear ultrasonic sensor for reverse-obstacle detection
- Tune `delay()` values for smoother turns based on your motor/battery specs

## Author

Built by [your GitHub username here].
