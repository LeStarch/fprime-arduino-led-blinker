#####
# 'LedBlinker' Deployment:
#
# This sets up the build for the 'LedBlinker' Application, including custom
# components. In addition, it imports FPrime.cmake, which includes the core F Prime components.
#
#####

###
# Basic Project Setup
###
cmake_minimum_required(VERSION 3.13)
cmake_policy(SET CMP0048 NEW)
project(LedBlinker VERSION 1.0.0 LANGUAGES C CXX)

###
# F' Core Setup
# This includes all of the F prime core components, and imports the make-system.
###
include("${CMAKE_CURRENT_LIST_DIR}/../fprime/cmake/FPrime.cmake")
# NOTE: register custom targets between these two lines
include("${FPRIME_FRAMEWORK_PATH}/cmake/FPrime-Code.cmake")

###
# Components and Topology
###
add_fprime_subdirectory("${CMAKE_CURRENT_LIST_DIR}/Top/")
set(MOD_DEPS ${PROJECT_NAME}/Top)

if (CMAKE_SYSTEM_NAME STREQUAL ArduinoFw)
    set(SOURCE_FILES "${CMAKE_CURRENT_LIST_DIR}/Main-arduino.cpp")
    list(APPEND MOD_DEPS Os_Baremetal_TaskRunner)
else()
    set(SOURCE_FILES "${CMAKE_CURRENT_LIST_DIR}/Main-linux.cpp")
endif()


register_fprime_deployment()
include("${CMAKE_CURRENT_LIST_DIR}/../project.cmake")
if (CMAKE_SYSTEM_NAME STREQUAL ArduinoFw)
    finalize_arduino_executable(LedBlinker)
endif()