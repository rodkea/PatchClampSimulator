# Set minimum required version of CMake
cmake_minimum_required(VERSION 3.13)

# Include build function from Pico SDK 
include ($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)

# Set name of project (as PROJECT_NAME) and C/C++ standards
project(PatchClampSimulator C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

 

# Creates a pico-sdk subdirectory in our project for the libraries
pico_sdk_init()

add_subdirectory(src)


add_executable(${PROJECT_NAME}
  main.cpp
)

pico_add_extra_outputs(${PROJECT_NAME})

target_link_libraries(${PROJECT_NAME}
  pico_stdlib
  pico_multicore
  hardware_clocks
  second_core
  CircularBuffer
)
# Habilitar la salida USB estándar (opcional)
pico_enable_stdio_usb(${PROJECT_NAME} 0)
pico_enable_stdio_uart(${PROJECT_NAME} 1)





