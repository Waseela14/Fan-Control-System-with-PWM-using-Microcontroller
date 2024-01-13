# Fan Control System with PWM using Microcontroller

## Overview

This project implements a microcontroller-based application to control the speed of a fan using Pulse Width Modulation (PWM) based on input temperature. The fan speed is categorized into three ranges: fast, medium, and slow, depending on user-specified temperature ranges. The temperature input can be provided either through a temperature sensor or by the user through a keypad. The system incorporates an Analog-to-Digital Converter (ADC) when using a temperature sensor.

The project also includes the following features:

- Digital display of current temperature and fan speed using seven-segment displays or LCD.
- Use of a DC motor to control the fan speed.
- On-chip timer/counter for PWM implementation.
- Switch mechanism for manual fan control.
- LEDs for indicating the ON/OFF status of the fan.

## Hardware Components

- Microcontroller: [Specify the microcontroller model]
- Temperature Sensor: [Specify the temperature sensor model]
- DC Motor: [Specify the DC motor details]
- Display: [Specify the display type - seven-segment displays or LCD]
- Switch: [Specify the type of switch]
- LEDs: [Specify the LED details]
- Other peripherals: [Specify any other peripherals used]

## How to Use

1. **Setting up the Hardware:**
   - Connect the microcontroller with the specified peripherals following the pinout and I/O constraints.
   - Ensure proper connections for the temperature sensor, DC motor, display, switch, and LEDs.

2. **Configuring the Microcontroller:**
   - Configure the on-chip timer/counter for PWM using the appropriate Wave-form Generation (WGM) and Compare on Output Match (COM) bits in control registers.
   - Handle I/O constraints diligently while interfacing peripherals.

3. **Uploading Code:**
   - Upload the microcontroller code to the development board.

4. **Running the System:**
   - Power on the system.
   - Provide temperature input using the sensor or keypad.
   - Observe the fan speed and temperature displayed on the digital display.

5. **Manual Control:**
   - Use the switch to manually control the fan. LEDs will indicate the ON/OFF status.

## Project Enhancement

Feel free to enhance the project as per your vision. Some suggestions for enhancement include:
- Adding a real-time clock (RTC) for time-based fan speed control.
- Implementing a user-friendly menu system on the display.
- Adding remote control functionality.

## Handling Incorrect/Invalid Inputs

The project is designed to handle incorrect or invalid temperature ranges gracefully. The system will not crash or malfunction due to unexpected inputs.
