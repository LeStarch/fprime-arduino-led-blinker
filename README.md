# `arduino-led-blinker`: an LED Blinker Example F´ Arduino Implementations

This project is an implementation of the [F´ LED Blinker Tutorial](https://github.com/fprime-community/fprime-workshop-led-blinker.git). This implementation changes the component to be `passive` as Arduinos are fundamentally baremetal implementations. Additionally, this implementation uses the [`fprime-arduino` toolchain](https://github.com/fprime-community/fprime-arduino.git) instead of `fprime-arm-linux`. 

The `LedTransitions` channel was downgraded to `U32` for smaller platform support.

The LedBlinker deployment has also been updated to use F´ Arduino components.