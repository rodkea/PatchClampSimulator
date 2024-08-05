#include "functions.h"

// Constants for waveform calculations
const float SIN_F = (2.0 * M_PI) / 1000; // Factor for sine wave calculation
const float COS_F = (2.0 * M_PI) / 1000; // Factor for cosine wave calculation
const float SQUARE_F = (2.0f * M_PI) *400; // Factor for square wave calculation
const uint32_t TRIANGULAR_T = 500; // Period for triangular wave
const float TRIANGULAR_F = TRIANGULAR_T / 2.0f; // Frequency factor for triangular wave


float sine_wave(uint32_t t)
{
  return sinf(SIN_F * t);
}

float cosine_wave(uint32_t t) 
{
  return cosf(COS_F * t);  
}


float square_wave(uint32_t t)
{
  return ((sinf(SQUARE_F * t)   > 0 ) ? 1.0f : -1.0f);
}


float triangular_wave(uint32_t t)
{
  return (t % TRIANGULAR_T) / TRIANGULAR_F  -1.0f;
}