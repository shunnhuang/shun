Tentacle Control Project

This project involves creating an interactive tentacle device controlled by servos, pressure sensors, and a distance sensor. The system features multiple operational modes, mimicking lifelike behaviors such as contraction, twitching, and centering based on sensor inputs.

Features

Silent Mode: Tentacles remain at rest when no pressure is detected and no object is nearby.

Hunting Mode: Tentacles contract when an object is detected within a certain range.

Motion Mode: Tentacles twitch in alternating patterns when both pressure and proximity are detected.

Centering Mode: Tentacles move toward the center when the pressure sensor is held for over one minute.

Components

Hardware

4 x Servo motors

1 x Pressure sensor (digital input)

1 x Distance sensor (analog input, e.g., ultrasonic or infrared)

Microcontroller (e.g., Arduino or ESP32)

Power supply

Soft ropes to simulate tentacle movement

Software

Arduino IDE

Servo library for motor control

Setup

Hardware Connections:

Connect the servos to PWM-capable pins (e.g., pins 3, 5, 6, 9 on an Arduino).

Attach the pressure sensor to digital pin 13.

Attach the distance sensor to analog pin A0.

Ensure a proper power supply for the servos.

Mechanically attach soft ropes to the servo motors to drive tentacle movement.

Software:

Upload the provided Arduino code to the microcontroller.

Adjust pin configurations in the code if necessary to match your hardware setup.

How It Works

Silent Mode:

When the pressure sensor is not pressed and the distance sensor does not detect a nearby object, the servos remain at position 0°.

Hunting Mode:

When the distance sensor detects an object, the servos alternate between contracted (90°) and semi-relaxed (45°) positions.

Motion Mode:

When both the pressure sensor is pressed and an object is nearby, the servos alternate between specific positions (90°/0° and 0°/90°) to create a twitching effect.

Centering Mode:

If the pressure sensor is held for more than 60 seconds, the servos move to positions (45° and 135°) to bring the tentacles toward the center.


Future Improvements

Integrate additional sensors for more advanced behaviors.

Add a wireless control module (e.g., Bluetooth or Wi-Fi).

Enhance the mechanical design for smoother tentacle movement.

License

This project is open-source and licensed under the MIT License.
