# Line Follower Bot

## Abstract
The Line Follower Bot is an autonomous robot designed to follow a line track using IR sensors and DC motors. The bot reads inputs from four infrared sensors placed at the front and controls two motors to navigate the track by adjusting motor speed and direction based on sensor input.

## Keywords
Arduino, Line Follower, IR Sensors, DC Motors, Robotics, Autonomous Navigation

## Introduction
Line following robots are widely used in industrial and research applications for automation. This project uses four infrared sensors to detect the line path and controls two motors accordingly to keep the robot on track.

## Hardware Components
- Arduino Uno (Microcontroller)
- 2 DC motors (left and right wheels)
- 4 IR sensors (two on left and two on right side)
- Motor driver circuit
- Power supply (battery or adapter)

## Software Description
- IR sensors are connected to analog pins A1 to A4 for detecting line presence.
- Motor control pins are defined for left and right motors.
- Sensor readings determine the motor speeds and directions:
  - When no line is detected, motors stop.
  - When the line is detected by specific sensors, the bot adjusts direction by speeding up or slowing down motors on either side.
- eadsensors() function reads the digital values of the IR sensors.
- loop() contains logic to handle motor actions based on sensor input combinations.

## Working Logic
- Sensor values are inverted digital reads.
- Different combinations of sensor inputs control motor speed using PWM.
- The bot tries to stay centered on the line by adjusting the left and right motors dynamically.

## Future Scope
- Add PID control for smoother navigation.
- Integrate Bluetooth or remote control.
- Include obstacle detection sensors.
- Expand to more complex track patterns.

---

This project demonstrates basic line-following logic for autonomous robots using simple IR sensors and motor control.
