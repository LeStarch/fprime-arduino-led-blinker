// ======================================================================
// \title  LedBlinkerTopology.hpp
// \brief header file containing the topology instantiation definitions
//
// ======================================================================
#ifndef LEDBLINKER_LEDBLINKERTOPOLOGY_LINUX_HPP
#define LEDBLINKER_LEDBLINKERTOPOLOGY_LINUX_HPP
#include <FpConfig.hpp>

namespace LedBlinker {
/**
 * \brief cycle the rate group driver at a crude rate
 *
 * The reference topology does not have a true 1Hz input clock for the rate group driver because it is designed to
 * operate across various computing endpoints (e.g. laptops) where a clear 1Hz source may not be easily and generically
 * achieved. This function mimics the cycling via a Task::delay(milliseconds) loop that manually invokes the ISR call
 * to the example block driver.
 *
 * This loop is stopped via a startSimulatedCycle call.
 *
 * Note: projects should replace this with a component that produces an output port call at the appropriate frequency.
 *
 * \param milliseconds: milliseconds to delay for each cycle. Default: 1000 or 1Hz.
 */
    void startSimulatedCycle(U32 milliseconds = 1000);

/**
 * \brief stop the simulated cycle started by startSimulatedCycle
 *
 * This stops the cycle started by startSimulatedCycle.
 */
    void stopSimulatedCycle();


} // namespace LedBlinker
#endif
