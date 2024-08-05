add_library(second_core STATIC
  second_core.cpp
)
target_include_directories(second_core PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/../inc
)

add_library(functions STATIC 
  functions.cpp
)

target_include_directories(functions PUBLIC 
${CMAKE_CURRENT_SOURCE_DIR}/../inc
)

add_library(CircularBuffer STATIC
  CircularBuffer.cpp
)

target_include_directories(CircularBuffer PUBLIC 
${CMAKE_CURRENT_SOURCE_DIR}/../inc
)

target_link_libraries(second_core
  pico_stdlib
  pico_multicore
  pico_sync  
  functions
  CircularBuffer
)