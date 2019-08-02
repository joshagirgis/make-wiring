#ifndef avr_f64_h_included
#define avr_f64_h_included


#define USE_AVR

#ifdef USE_AVR
	#include <inttypes.h>
	#include "dprintf.h"
#else
	typedef unsigned char    uint8_t;
	typedef signed char      int8_t;
	typedef unsigned short   uint16_t;
	typedef signed short     int16_t;
	typedef unsigned int     uint32_t;
	typedef signed int       int32_t;
	typedef unsigned __int64 uint64_t;
	typedef signed __int64   int64_t;

    #define DebugPrintf printf
#endif

#ifdef USE_AVR
#define LANGEEINS (1ull)
#else
#define LANGEEINS (1l)
#endif

typedef uint64_t float64_t;
typedef float    float32_t;

float64_t f_sd(float32_t fx);
float32_t f_ds(float64_t fx);
float64_t f_add     (float64_t a, float64_t b   );
float64_t f_sub     (float64_t a, float64_t b   );
float64_t f_mult    (float64_t fa, float64_t fb );
float64_t f_inverse (float64_t fa               );
float64_t f_div     (float64_t fa, float64_t fb );
void      f_showlong(uint64_t i64);

#endif //#ifndef avr_f64_h_included
