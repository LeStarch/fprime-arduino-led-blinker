// ======================================================================
// \title  Led.hpp
// \author starchmd
// \brief  hpp file for Led component implementation class
// ======================================================================

#ifndef Led_HPP
#define Led_HPP

#include "Components/Led/LedComponentAc.hpp"
#include "Fw/Types/OnEnumAc.hpp"

namespace Components {

  class Led :
    public LedComponentBase
  {

    public:

      // ----------------------------------------------------------------------
      // Construction, initialization, and destruction
      // ----------------------------------------------------------------------

      //! Construct object Led
      //!
      Led(
          const char *const compName /*!< The component name*/
      );

      //! Destroy object Led
      //!
      ~Led();

  PRIVATE:
      void parameterUpdated(FwPrmIdType id);

      // ----------------------------------------------------------------------
      // Command handler implementations
      // ----------------------------------------------------------------------

      //! Implementation for BLINKING_ON_OFF command handler
      //!
      void BLINKING_ON_OFF_cmdHandler(
              const FwOpcodeType opCode, /*!< The opcode*/
              const U32 cmdSeq, /*!< The command sequence number*/
              Fw::On on_off /*!<
          Indicates whether the blinking should be on or off
          */
      );

  PRIVATE:

      // ----------------------------------------------------------------------
      // Handler implementations for user-defined typed input ports
      // ----------------------------------------------------------------------

      //! Handler implementation for run
      //!
      void run_handler(
              const NATIVE_INT_TYPE portNum, /*!< The port number*/
              NATIVE_UINT_TYPE context /*!<
      The call order
      */
      );

      Fw::On state; // Led state
      U32 transitions; // Number of LED transitions
      U32 count; // Cycle count
      bool blinking; // Led is blinking or not
    };

} // end namespace Components

#endif
