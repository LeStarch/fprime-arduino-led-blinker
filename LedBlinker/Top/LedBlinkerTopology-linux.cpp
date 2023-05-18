// ======================================================================
// \title  LedBlinkerTopology.cpp
// \brief cpp file containing the topology instantiation code
//
// ======================================================================
// Provides access to autocoded functions
#include <LedBlinker/Top/LedBlinkerTopologyAc.hpp>
#include <LedBlinker/Top/LedBlinkerPacketsAc.hpp>
#include <LedBlinker/Top/LedBlinkerTopology.hpp>


void initializeCommunications(const TopologyState& state) {
    bool gpio_success = gpioDriver.open(13, Drv::LinuxGpioDriver::GpioDirection::GPIO_OUT);
    if (!gpio_success) {
        printf("[ERROR] Failed to open GPIO pin\n");
    }
    // Initialize socket client communication if and only if there is a valid specification
    if (state.hostname != nullptr && state.port != 0) {
        Os::TaskString name("ReceiveTask");
        // Uplink is configured for receive so a socket task is started
        comm.configure(state.hostname, state.port);
        comm.startSocketTask(name, true, 100, Default::STACK_SIZE);
    }
}

void stopCommunications(const TopologyState& state) {
    // Other task clean-up.
    comm.stopSocketTask();
    (void)comm.joinSocketTask(nullptr);
}
// Public functions for use in main program are namespaced with deployment name LedBlinker
namespace LedBlinker {

// Variables used for cycle simulation
Os::Mutex cycleLock;
volatile bool cycleFlag = true;

void startSimulatedCycle(U32 milliseconds) {
    cycleLock.lock();
    bool cycling = cycleFlag;
    cycleLock.unLock();

    // Main loop
    while (cycling) {
        LedBlinker::blockDrv.callIsr();
        Os::Task::delay(milliseconds);

        cycleLock.lock();
        cycling = cycleFlag;
        cycleLock.unLock();
    }
}

void stopSimulatedCycle() {
    cycleLock.lock();
    cycleFlag = false;
    cycleLock.unLock();
}

};  // namespace LedBlinker
