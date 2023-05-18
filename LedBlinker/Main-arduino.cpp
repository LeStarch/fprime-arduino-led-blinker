// ======================================================================
// \title  Main.cpp
// \brief main program for the F' application. Intended for CLI-based systems (Linux, macOS)
//
// ======================================================================
// Used to access topology functions
#include <FprimeArduino.hpp>
#include <Os/Baremetal/TaskRunner/TaskRunner.hpp>
#include <LedBlinker/Top/LedBlinkerTopology.hpp>
#include <Os/Log.hpp>
#include <Arduino/Os/StreamLog.hpp>

Os::TaskRunner runner; // Use the task runner


/**
 * \brief execute the program
 *
 * This F´ program is designed to run in standard environments (e.g. Linux/macOs running on a laptop). Thus it uses
 * command line inputs to specify how to connect.
 *
 * @param argc: argument count supplied to program
 * @param argv: argument values supplied to program
 * @return: 0 on success, something else on failure
 */
int main(int argc, char* argv[]) {
    Serial.begin(115200);
    delay(10000);
    Os::setArduinoStreamLogHandler(&Serial);
    Fw::Logger::logMsg("[INFO] Logging Started!\n");
    // Object for communicating state to the reference topology
    LedBlinker::TopologyState inputs;
    inputs.uartNumber = 0;
    inputs.uartBaud = 115200;

    // Setup, cycle, and teardown topology
    LedBlinker::setupTopology(inputs);
    Fw::Logger::logMsg("[INFO] Topology set up, running!\n");

    while (true) {
        runner.run();
    }
    LedBlinker::teardownTopology(inputs);
    return 0;
}
