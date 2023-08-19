# Temperature-Controlled Fan Controller using ATmega16

This repository contains the source code and documentation for a temperature-controlled fan controller system implemented using the ATmega16 microcontroller. The fan controller system utilizes various libraries and hardware abstraction layers (HAL) to achieve its functionality.

## Requirements

- ATmega16 Microcontroller operating at a frequency of 1MHz.
- Libraries: `std_types`, `common_macros`
- Microcontroller Abstraction Layer (MCAL): `DIO`, `ADC`, `PWM`
- Hardware Abstraction Layer (HAL): `lcd`, `lm35`, `dc_motor`

## Project Overview

The main objective of this project is to create a temperature-controlled fan system using the ATmega16 microcontroller. The LM35 temperature sensor is used to sense the temperature and provide analog output to the ADC, which converts the analog values to digital values. The microcontroller processes these values to determine the temperature and control the fan speed accordingly.

## System Logic

1. The LM35 temperature sensor provides analog output proportional to the sensed temperature.
2. The ADC converts the analog signal to digital values.
3. The microcontroller calculates the temperature using appropriate programming logic.
4. The calculated temperature and fan state are displayed on the LCD.
5. Based on the temperature value, the fan is controlled as follows:
   - Temperature < 30°C: Fan OFF
   - 30°C ≤ Temperature < 60°C: Fan at 25% speed
   - 60°C ≤ Temperature < 90°C: Fan at 50% speed
   - 90°C ≤ Temperature < 120°C: Fan at 75% speed
   - Temperature ≥ 120°C: Fan at 100% speed
6. The DC motor rotates clockwise or stops based on the fan state.

## proteus Simulation
![Simulation](Proteus%20Simulation/sim.png)

## Project Structure

The project consists of the following components:

- `main.c`: Main application code that implements the fan control logic and temperature calculation.
- `lcd.h`, `lcd.c`: HAL for interfacing with the LCD to display temperature and fan state.
- `lm35.h`, `lm35.c`: HAL for interfacing with the LM35 temperature sensor.
- `dc_motor.h`, `dc_motor.c`: HAL for controlling the DC motor based on fan state.
- `adc.h`, `adc.c`: MCAL for interacting with the ADC module.
- `dio.h`, `dio.c`: MCAL for digital input/output control.
- `pwm.h`, `pwm.c`: MCAL for PWM generation.

## Getting Started

1. Connect the LM35 temperature sensor to the appropriate pins on the microcontroller.
2. Connect the DC motor and configure its control pins.
3. Configure the LCD connections.
4. Load the project files into your development environment.
5. Compile and upload the code to the ATmega16 microcontroller.
6. Observe the LCD display for the temperature and fan state updates.



