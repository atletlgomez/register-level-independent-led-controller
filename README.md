# Register-Level Independent LED Controller

- **Project Description**
  - This project controls three LEDs on an Arduino UNO using direct AVR register control.
  - Instead of using Arduino helper functions like `pinMode()` and `digitalWrite()`, this program uses `DDRD` and `PORTD`.
  - Each LED blinks at its own interval using `millis()`.
  - Because the project does not use `delay()`, all LEDs can run independently.

- **Hardware Used**
  - Arduino UNO
  - 3 LEDs
  - 3 resistors
  - Breadboard
  - Jumper wires

- **Pin Mapping**
  - LED 1
    - Arduino pin: 2
    - AVR port: `PORTD`
    - Bit: 2
  - LED 2
    - Arduino pin: 3
    - AVR port: `PORTD`
    - Bit: 3
  - LED 3
    - Arduino pin: 4
    - AVR port: `PORTD`
    - Bit: 4

- **Key Concepts**
  - `DDRD` controls whether pins on Port D are inputs or outputs.
  - `PORTD` controls whether output pins on Port D are HIGH or LOW.
  - Bit masks like `(1 << 2)` allow one specific pin to be controlled.
  - `millis()` allows timing without blocking the program.
  - Each LED has its own:
    - state
    - previous time
    - interval
    - bit mask
  - A `struct` groups each LED’s data together.
  - A function updates each LED by reference using `Led&`.

- **How It Works**
  - Each LED is stored as a `Led` struct.
  - The struct contains:
    - LED pin
    - bit mask
    - current state
    - previous update time
    - blink interval
  - In `setup()`, `DDRD` sets pins 2, 3, and 4 as outputs.
  - In `loop()`, `millis()` updates the current time.
  - Each LED is passed into the `ledInterval()` function.
  - If enough time has passed for that LED:
    - the LED state is toggled
    - the matching bit in `PORTD` is updated
    - the LED’s previous time is updated
  - Because each LED has its own interval and previous time, all three LEDs blink independently.

- **What I Learned**
  - I learned how to move from Arduino helper functions to lower-level register control.
  - I learned that `DDRD` controls pin direction.
  - I learned that `PORTD` controls output state.
  - I learned how to use bit masks to control individual pins without changing the rest of the register.
  - I learned how `millis()` can be used for non-blocking timing.
  - I learned how state variables help each LED remember whether it should be ON or OFF.
  - I learned how a `struct` can organize related LED data.
  - I learned why passing by reference with `Led&` lets a function update the real LED object instead of a copy.

- **Future Improvements**
  - Add a button using `PIND` to read input.
  - Add different LED modes:
    - blink mode
    - chase mode
    - all-on mode
  - Store multiple LEDs in an array of structs.
  - Use a loop to update all LEDs.
  - Add a buzzer with its own independent timing.
  - Build a small scheduler system for LEDs, buttons, and buzzer events.
