####
# F prime CMakeLists.txt:
#
# SOURCE_FILES: combined list of source and autocoding files
# MOD_DEPS: (optional) module dependencies
####

set(SOURCE_FILES
  "${CMAKE_CURRENT_LIST_DIR}/instances.fpp"
  "${CMAKE_CURRENT_LIST_DIR}/LedBlinkerPackets.xml"
  "${CMAKE_CURRENT_LIST_DIR}/topology.fpp"
  "${CMAKE_CURRENT_LIST_DIR}/LedBlinkerTopology.cpp"
)
set(MOD_DEPS
  Fw/Logger
)

if (CMAKE_SYSTEM_NAME STREQUAL ArduinoFw)
    list(APPEND SOURCE_FILES
        "${CMAKE_CURRENT_LIST_DIR}/instances-arduino.fpp"
        "${CMAKE_CURRENT_LIST_DIR}/LedBlinkerTopology-arduino.cpp"
    )
    list(APPEND MOD_DEPS
        Arduino/ArduinoTime
    )

else()
    list(APPEND SOURCE_FILES
        "${CMAKE_CURRENT_LIST_DIR}/instances-linux.fpp"
        "${CMAKE_CURRENT_LIST_DIR}/LedBlinkerTopology-linux.cpp"
    )
    list(APPEND MOD_DEPS
            Svc/LinuxTime
            Drv/Udp
            Drv/TcpClient
    )
endif()


register_fprime_module()
