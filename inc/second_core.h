#ifndef SECOND_CORE_H
#define SECOND_CORE_H

#include "pico/stdlib.h"
#include "pico/multicore.h"
#include "pico/sync.h"
#include "FloatBytes.h"
#include "CircularBuffer.h"
#include <iostream>
#include "functions.h"
#include <cstring> 
#include <array>

using namespace std;

void second_core_main();

/**
* @brief Processes incoming commands to start or stop the timer.
* 
* @param command The command received.
* @param isTimerStarted Reference to the flag indicating if the timer is started.
* @param timer Reference to the repeating timer structure.
*/
void read_command(uint32_t command,bool& isTimerStarted, struct repeating_timer& timer);

/**
* @brief Callback function for the repeating timer.
* 
* Generates function values, queues them, and sends them.
* 
* @param t Pointer to the repeating timer structure.
* @return true to continue the timer, false to stop it.
*/
bool repeating_timer_callback(struct repeating_timer *t);

/**
* @brief Generates function values and stores them in the `funcs` array.
* 
* @param funcs Array to store function values.
* @param t The current time in milliseconds.
*/
void generate_functions(array<FloatBytes,4>& funcs, uint32_t t);

/**
* @brief Queues a package into the circular buffer.
* 
* @param funcs Array of FloatBytes to be queued.
* @param package_number The package number.
*/
void package_queue(array<FloatBytes,4>& funcs, char package_number);

#endif // SECOND_CORE_H
