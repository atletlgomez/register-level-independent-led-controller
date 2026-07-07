# Register-Level Independent LED Controller

## Overview

This project controls multiple LEDs independently on an Arduino Uno using register-level programming. Instead of using `digitalWrite()` and `delay()`, the project directly modifies the ATmega328P GPIO registers and uses non-blocking timing with `millis()`.

## Features

- Controls LEDs using direct port manipulation
- Uses `millis()` for non-blocking timing
- Allows each LED to run on its own interval
- Avoids `delay()` so the main loop stays responsive

## Hardware

- Arduino Uno
- LEDs
- Resistors
- Breadboard
- Jumper wires

## Concepts Used

- `DDRD` for setting pin direction
- `PORTD` for controlling output states
- Bit masks
- Bit shifting
- Non-blocking timing
- Independent state tracking

## How It Works

Each LED has its own previous time and interval. Inside `loop()`, the program checks whether enough time has passed for each LED. If the interval has passed, the LED state is toggled and the previous time is updated.

This allows multiple LEDs to blink at different rates without stopping the rest of the program.

## Why Register-Level Control?

Register-level control gives more direct access to the microcontroller hardware. This project uses it to practice working closer to the ATmega328P instead of relying only on Arduino helper functions.

## Future Improvements

- Add button input to control LED states
- Add more LEDs with different timing intervals
- Convert the logic into reusable functions or classes
- Expand the project into a small cooperative task scheduler