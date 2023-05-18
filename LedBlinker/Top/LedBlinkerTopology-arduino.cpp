// ======================================================================
// \title  LedBlinkerTopology.cpp
// \brief cpp file containing the topology instantiation code
//
// ======================================================================
// Provides access to autocoded functions
#include <LedBlinker/Top/LedBlinkerTopologyAc.hpp>
#include <LedBlinker/Top/LedBlinkerPacketsAc.hpp>
#include <LedBlinker/Top/LedBlinkerTopology.hpp>
#include <Fw/Logger/Logger.hpp>

void initializeSpecifics(const TopologyState& state) {
    Fw::Logger::logMsg("[INFO] Opening serial port %u with baud %u\n", state.uartNumber, state.uartBaud);
    rgDriver.configure(10);
    comm.configure(state.uartNumber, state.uartBaud);
    rgDriver.start();
}

void stopSpecifics(const TopologyState& state) {
}
// Public functions for use in main program are namespaced with deployment name LedBlinker
namespace LedBlinker {
};  // namespace LedBlinker
