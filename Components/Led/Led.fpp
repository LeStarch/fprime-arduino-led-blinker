module Components {
    @ Component to blink and LED driven by a rate group
    passive component Led {
        guarded command BLINKING_ON_OFF(
            on_off: Fw.On @< Indicates whether the blinking should be on or off
        )

        @ Telemetry channel to report blinking state
        telemetry BlinkingState: Fw.On

        @ Number of LED transitions
        telemetry LedTransitions: U32

        @ Indicates we received an invalid argument.
        event InvalidBlinkArgument(badArgument: Fw.On) \
            severity warning low \
            format "Invalid Blinking Argument: {}"

        @ Reports the state we set to blinking.
        event SetBlinkingState(state: Fw.On) \
            severity activity high \
            format "Set blinking state to {}."

        @ Reports the interval parameter was set
        event BlinkIntervalSet(interval: U32) \
            severity activity high \
            format "Blink interval set to {}."

        @ Reports the LED state
        event LedState(state: Fw.On) \
            severity activity low \
            format "LED is: {}."

        @ Blinking interval in rate group ticks
        param BLINK_INTERVAL: U32

        @ Port receiving calls from the rate group
        sync input port run: Svc.Sched

        @ Port sending calls to the GPIO driver
        output port gpioSet: Drv.GpioWrite

        ###############################################################################
        # Standard AC Ports: Required for Channels, Events, Commands, and Parameters  #
        ###############################################################################
        @ Port for requesting the current time
        time get port timeCaller

        @ Port for sending command registrations
        command reg port cmdRegOut

        @ Port for receiving commands
        command recv port cmdIn

        @ Port for sending command responses
        command resp port cmdResponseOut

        @ Port for sending textual representation of events
        text event port logTextOut

        @ Port for sending events to downlink
        event port logOut

        @ Port for sending telemetry channels to downlink
        telemetry port tlmOut

        @ Port to return the value of a parameter
        param get port prmGetOut

        @Port to set the value of a parameter
        param set port prmSetOut

    }
}