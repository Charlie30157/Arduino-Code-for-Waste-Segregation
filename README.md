# Smart Waste Segregation System

This project aims to create a smart waste segregation system that detects incoming waste, classifies it as wet or dry based on moisture levels, and uses servo motors to sort the waste into appropriate compartments. The system utilizes an ultrasonic sensor to detect the proximity of the waste, moisture sensors to determine the wetness or dryness, and servo motors to move the waste into designated bins.

## Components

- 2x Servo Motors
- 1x Ultrasonic Sensor (HC-SR04)
- 2x Soil Moisture Sensors (resistance-based, used to detect wet or dry waste)
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

1. **Waste Detection**: 
   The ultrasonic sensor measures the distance to an incoming waste item. If an object is detected within a certain range, the system triggers the sorting process.

2. **Waste Classification**:
   The system uses two soil moisture sensors to classify the waste as wet or dry:
   - Low resistance indicates wet waste (moist).
   - High resistance indicates dry waste.

3. **Waste Sorting**:
   Based on the waste classification:
   - If the waste is wet (moist), Servo 1 and Servo 2 will move the waste into the wet waste compartment.
   - If the waste is dry, the servos will place it in the dry waste compartment.

4. **Servo Control**:
   The servos move based on the waste classification to position the waste in the appropriate bin:
   - Wet waste (low resistance) triggers one set of servo movements.
   - Dry waste (high resistance) triggers an alternate set of movements.

5. **Delay**:
   After sorting, the system waits for a short time before checking for new incoming waste.

## Code Explanation

### Setup:
- Initializes the servo motors and sensor pins.
- Starts serial communication to print sensor readings for debugging.

### Loop:
- Measures the distance to an object using the ultrasonic sensor.
- Measures soil resistance using analog sensors to determine whether the waste is wet or dry.
- Based on the measurements, the system controls the servo motors to direct the waste into the corresponding compartment.

### Servo Control:
- Wet waste (low resistance) results in the servos moving to the wet waste compartment.
- Dry waste (high resistance) results in the servos moving to the dry waste compartment.
  
### Delay:
- Introduces short delays to allow servos to complete movements and stabilize sensor readings.

## Requirements

- Arduino IDE
- Servo Library (`#include <Servo.h>`)
- Arduino-compatible board (e.g., Arduino Uno)

## Setup Instructions

1. Connect the components as per the pin connections described above.
2. Open the Arduino IDE and paste the code into a new sketch.
3. Upload the code to your Arduino board.
4. Open the Serial Monitor to view the sensor readings (distance and moisture levels).
5. The system will detect incoming waste and sort it into wet or dry waste compartments using the servo motors.

## Future Improvements

- Add more sensors to detect different types of waste (e.g., recyclable or non-recyclable).
- Integrate a camera or more sophisticated waste recognition system.
- Automate the waste bin collection process using motors or actuators.

## License

This project is open-source and free to use. Feel free to modify and adapt it to your needs.
