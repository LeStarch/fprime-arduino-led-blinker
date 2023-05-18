module LedBlinker {

  instance rgDriver: Drv.BlockDriver base id 0x0100 \
    queue size Default.QUEUE_SIZE \
    stack size Default.STACK_SIZE \
    priority 140

  instance comm: Drv.ByteStreamDriverModel base id 0x4500 \
    type "Drv::TcpClient" \ # type specified to select implementor of ByteStreamDriverModel
    at "../../Drv/TcpClient/TcpClient.hpp" # location of above implementor must also be specified

  instance timeHandler: Svc.Time base id 0x5100 \
    type "Svc::LinuxTime" \
    at "../../Svc/LinuxTime/LinuxTime.hpp"

  instance gpioDriver: Drv.LinuxGpioDriver base id 0x5200
}
