# Servo-Controlled Plant Watering System

This project is a simple automated plant watering system that uses an ultrasonic sensor to detect the distance of an object (representing a plant) and a resistance sensor to measure soil moisture. Based on these readings, the system controls two servos to either water the plant or take an alternate action.

## Components

- 2x Servo Motors
- 1x Ultrasonic Sensor (HC-SR04)
- 2x Soil Moisture Sensors (resistance-based)
- Arduino (or compatible board)

## Pin Connections

- **Servo Motors**:
  - `Servo 1` connected to pin `9`
  - `Servo 2` connected to pin `8`
  
- **Ultrasonic Sensor**:
  - `Trig` pin connected to `7`
  - `Echo` pin connected to `6`
  
- **Soil Moisture Sensors**:
  - `Resistance_signal` connected to `A0`
  - `Resistance_signalt` connected to `A1`

## Working

1. **Distance Measurement**: 
   The ultrasonic sensor measures the distance to an object (representing the plant). If the object is detected within 20 cm, the system activates the servos to perform a watering action.

2. **Soil Moisture Measurement**:
   Two resistance-based soil moisture sensors measure the resistance in the soil. 
   - If the resistance is low (indicating moist soil), the system performs a watering action.
   - If the resistance is high (indicating dry soil), the system performs an alternate action.

3. **Servo Control**: 
   Based on the readings of the ultrasonic sensor and soil moisture sensors, the servos are controlled:
   - If the distance is within 20 cm and the soil is moist (low resistance), Servo 1 and Servo 2 perform a watering action.
   - If the distance is within 20 cm and the soil is dry (high resistance), Servo 1 and Servo 2 perform an alternate action (e.g., watering at a different speed or angle).
   - If no condition is met, the servos reset to default positions.

## Code Explanation

### Setup:
- Initializes the servo motors and sensor pins.
- Starts serial communication for debugging and data logging.

### Loop:
- Measures distance using the ultrasonic sensor.
- Measures soil resistance using the analog inputs connected to the soil moisture sensors.
- Based on the distance and resistance values, the system controls the servo motors to either water the plant or take alternate actions.
  
### Servo Control:
- When an object is detected within 20 cm and the soil is moist, the system activates the watering action by rotating the servos to specific positions.
- When the soil is dry, a different servo movement is used to simulate an alternate watering behavior.

### Delay:
- Introduces delays between actions to allow servos to complete their movements and to ensure stable sensor readings.

## Requirements

- Arduino IDE
- Servo Library (`#include <Servo.h>`)
- An Arduino-compatible board (e.g., Arduino Uno)

## Setup Instructions

1. Connect the components as per the pin connections mentioned above.
2. Open the Arduino IDE and paste the code into a new sketch.
3. Upload the code to your Arduino board.
4. Open the Serial Monitor to view the sensor readings (distance and soil moisture).
5. The system will start controlling the servos based on the detected distance and soil moisture levels.

## Future Improvements

- Add more sensors for better soil detection.
- Include a water pump controlled by a relay for automated watering.
- Implement more sophisticated watering patterns based on sensor thresholds.

## License

This project is open-source and free to use. Feel free to modify and adapt it to your needs.
