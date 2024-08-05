#include "FloatBytes.h"
#include <stdint.h>
#include <cmath>


/**
* @brief Calculates the sine wave value at a given time t.
*
* @param t The time at which to calculate the sine wave.
* @return The sine wave value at time t.
*/
float sine_wave(uint32_t t );

/**
* @brief Calculates the cosine wave value at a given time t.
*
* @param t The time at which to calculate the cosine wave.
* @return The cosine wave value at time t.
*/
float cosine_wave(uint32_t t);

/**
* @brief Calculates the square wave value at a given time t.
*
* @param t The time at which to calculate the square wave.
* @return The square wave value at time t. The value is 1.0f if the sine value is positive, otherwise -1.0f.
*/
float triangular_wave(uint32_t t);

/**
* @brief Calculates the triangular wave value at a given time t.
*
* @param t The time at which to calculate the triangular wave.
* @return The triangular wave value at time t. The value ranges between -1.0f and 1.0f.
*/
float square_wave(uint32_t t);