#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#include <stdint.h>


// these are all signed because they have to accomodate the -constant to indicate no value pattern
typedef int16_t resistance_t;
typedef int8_t peloton_t;
typedef int16_t power_t;
typedef int16_t cadence_t;
typedef double inclination_t;

#endif // DEFINITIONS_H
