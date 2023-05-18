module LedBlinker {

  instance rgDriver: Arduino.HardwareRateDriver base id 0x0100

  instance comm: Arduino.SerialDriver base id 0x5000

  instance timeHandler: Svc.Time base id 0x5100 \
    type "Svc::ArduinoTimeImpl" \
    at "../../fprime-arduino/Arduino/ArduinoTime/ArduinoTimeImpl.hpp"

  instance gpioDriver: Arduino.GpioDriver base id 0x5200
}
