# PATCH CLAMP SIMULATOR

  This project simulates data transmission via UART on a Raspberry Pi Pico. It emulates a device that samples four channels of an ADC and transmits the data through UART. The data is sent in a structured format using a custom protocol, and can be controlled via UART commands.

**Commands**:
   - **Start Timer**: Send command `12` to start the timer and begin data transmission.
   - **Stop Timer**: Send command `13` to stop the timer and halt data transmission.

## Dependencies

- Raspberry Pi Pico SDK
- C++ Standard Library