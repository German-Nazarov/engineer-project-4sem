#ifndef SQUARE_MAX_70_AT_16384_2048INT8_H_
#define SQUARE_MAX_70_AT_16384_2048INT8_H_

#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif
#include "mozzi_pgmspace.h"


#define SQUARE_MAX_70_AT_16384_2048_NUM_CELLS 2048
#define SQUARE_MAX_70_AT_16384_2048_SAMPLERATE 2048

CONSTTABLE_STORAGE(int8_t) SQUARE_MAX_70_AT_16384_2048_DATA [] = 
{
0, 24, 48, 70, 88, 104, 115, 123, 126, 127, 125, 121, 116, 110, 105, 101, 99, 97, 98, 99, 101, 105, 108, 111, 113, 114, 115, 115, 113, 111, 109, 107, 105, 
103, 103, 102, 103, 104, 106, 107, 109, 111, 112, 112, 112, 111, 110, 109, 108, 106, 105, 104, 104, 104, 105, 106, 107, 108, 109, 110, 111, 111, 111, 110, 109, 
108, 107, 106, 105, 105, 105, 105, 106, 107, 108, 109, 110, 110, 110, 110, 110, 109, 108, 107, 107, 106, 106, 106, 106, 106, 107, 108, 108, 109, 110, 110, 110, 
109, 109, 108, 108, 107, 106, 106, 106, 106, 106, 107, 107, 108, 109, 109, 109, 109, 109, 109, 108, 108, 107, 107, 106, 106, 106, 106, 107, 107, 108, 108, 109, 
109, 109, 109, 109, 109, 108, 108, 107, 107, 106, 106, 106, 107, 107, 108, 108, 109, 109, 109, 109, 109, 109, 108, 108, 107, 107, 107, 107, 107, 107, 107, 108, 
108, 108, 109, 109, 109, 109, 109, 108, 108, 107, 107, 107, 107, 107, 107, 107, 107, 108, 108, 109, 109, 109, 109, 109, 108, 108, 108, 107, 107, 107, 107, 107, 
107, 107, 108, 108, 108, 109, 109, 109, 109, 108, 108, 108, 107, 107, 107, 107, 107, 107, 107, 108, 108, 108, 108, 109, 109, 109, 108, 108, 108, 108, 107, 107, 
107, 107, 107, 107, 107, 108, 108, 108, 109, 109, 109, 108, 108, 108, 108, 107, 107, 107, 107, 107, 107, 107, 108, 108, 108, 108, 109, 109, 109, 108, 108, 108, 
107, 107, 107, 107, 107, 107, 107, 108, 108, 108, 108, 109, 109, 109, 108, 108, 108, 108, 107, 107, 107, 107, 107, 107, 107, 108, 108, 108, 108, 109, 109, 108, 
108, 108, 108, 107, 107, 107, 107, 107, 107, 107, 108, 108, 108, 108, 108, 108, 108, 108, 108, 108, 108, 107, 107, 107, 107, 107, 107, 108, 108, 108, 108, 108, 
108, 108, 108, 108, 108, 108, 107, 107, 107, 107, 107, 107, 107, 108, 108, 108, 108, 108, 108, 108, 108, 108, 108, 107, 107, 107, 107, 107, 107, 107, 108, 108, 
108, 108, 108, 108, 108, 108, 108, 108, 108, 107, 107, 107, 107, 107, 107, 108, 108, 108, 108, 108, 108, 108, 108, 108, 108, 108, 107, 107, 107, 107, 107, 107, 
108, 108, 108, 108, 108, 108, 108, 108, 108, 108, 108, 108, 107, 107, 107, 107, 107, 107, 108, 108, 108, 108, 108, 108, 108, 108, 108, 108, 108, 107, 107, 107, 
107, 107, 107, 108, 108, 108, 108, 108, 108, 108, 108, 108, 108, 108, 107, 107, 107, 107, 107, 107, 108, 108, 108, 108, 108, 108, 108, 108, 108, 108, 108, 108, 
107, 107, 107, 107, 107, 107, 108, 108, 108, 108, 108, 108, 108, 108, 108, 108, 108, 107, 107, 107, 107, 107, 107, 108, 108, 108, 108, 108, 108, 108, 108, 108, 
108, 108, 107, 107, 107, 107, 107, 107, 107, 108, 108, 108, 108, 108, 108, 108, 108, 108, 108, 108, 107, 107, 107, 107, 107, 107, 108, 108, 108, 108, 108, 108, 
108, 108, 108, 108, 108, 107, 107, 107, 107, 107, 107, 108, 108, 108, 108, 108, 108, 108, 108, 108, 108, 108, 107, 107, 107, 107, 107, 107, 107, 108, 108, 108, 
108, 108, 108, 108, 108, 108, 108, 108, 107, 107, 107, 107, 107, 107, 108, 108, 108, 108, 108, 108, 108, 108, 108, 108, 108, 107, 107, 107, 107, 107, 107, 108, 
108, 108, 108, 108, 108, 108, 108, 108, 108, 108, 108, 107, 107, 107, 107, 107, 107, 108, 108, 108, 108, 108, 108, 108, 108, 108, 108, 108, 107, 107, 107, 107, 
107, 107, 108, 108, 108, 108, 108, 108, 108, 108, 108, 108, 108, 107, 107, 107, 107, 107, 107, 108, 108, 108, 108, 108, 108, 108, 108, 108, 108, 108, 108, 107, 
107, 107, 107, 107, 107, 108, 108, 108, 108, 108, 108, 108, 108, 108, 108, 108, 107, 107, 107, 107, 107, 107, 108, 108, 108, 108, 108, 108, 108, 108, 108, 108, 
108, 107, 107, 107, 107, 107, 107, 107, 108, 108, 108, 108, 108, 108, 108, 108, 108, 108, 107, 107, 107, 107, 107, 107, 107, 108, 108, 108, 108, 108, 108, 108, 
108, 108, 108, 108, 107, 107, 107, 107, 107, 107, 108, 108, 108, 108, 108, 108, 108, 108, 108, 108, 108, 107, 107, 107, 107, 107, 107, 107, 108, 108, 108, 108, 
109, 109, 108, 108, 108, 108, 107, 107, 107, 107, 107, 107, 107, 108, 108, 108, 108, 109, 109, 109, 108, 108, 108, 108, 107, 107, 107, 107, 107, 107, 107, 108, 
108, 108, 109, 109, 109, 108, 108, 108, 108, 107, 107, 107, 107, 107, 107, 107, 108, 108, 108, 108, 109, 109, 109, 108, 108, 108, 107, 107, 107, 107, 107, 107, 
107, 108, 108, 108, 108, 109, 109, 109, 108, 108, 108, 108, 107, 107, 107, 107, 107, 107, 107, 108, 108, 108, 109, 109, 109, 109, 108, 108, 108, 107, 107, 107, 
107, 107, 107, 107, 108, 108, 108, 109, 109, 109, 109, 109, 108, 108, 107, 107, 107, 107, 107, 107, 107, 107, 108, 108, 109, 109, 109, 109, 109, 108, 108, 108, 
107, 107, 107, 107, 107, 107, 107, 108, 108, 109, 109, 109, 109, 109, 109, 108, 108, 107, 107, 106, 106, 106, 107, 107, 108, 108, 109, 109, 109, 109, 109, 109, 
108, 108, 107, 107, 106, 106, 106, 106, 107, 107, 108, 108, 109, 109, 109, 109, 109, 109, 108, 107, 107, 106, 106, 106, 106, 106, 107, 108, 108, 109, 109, 110, 
110, 110, 109, 108, 108, 107, 106, 106, 106, 106, 106, 107, 107, 108, 109, 110, 110, 110, 110, 110, 109, 108, 107, 106, 105, 105, 105, 105, 106, 107, 108, 109, 
110, 111, 111, 111, 110, 109, 108, 107, 106, 105, 104, 104, 104, 105, 106, 108, 109, 110, 111, 112, 112, 112, 111, 109, 107, 106, 104, 103, 102, 103, 103, 105, 
107, 109, 111, 113, 115, 115, 114, 113, 111, 108, 105, 101, 99, 98, 97, 99, 101, 105, 110, 116, 121, 125, 127, 126, 123, 115, 104, 88, 70, 48, 24, 0, 
-24, -48, -70, -88, -104, -115, -123, -126, -127, -125, -121, -116, -110, -105, -101, -99, -97, -98, -99, -101, -105, -108, -111, -113, -114, -115, -115, -113, -111, -109, -107, -105, 
-103, -103, -102, -103, -104, -106, -107, -109, -111, -112, -112, -112, -111, -110, -109, -108, -106, -105, -104, -104, -104, -105, -106, -107, -108, -109, -110, -111, -111, -111, -110, -109, 
-108, -107, -106, -105, -105, -105, -105, -106, -107, -108, -109, -110, -110, -110, -110, -110, -109, -108, -107, -107, -106, -106, -106, -106, -106, -107, -108, -108, -109, -110, -110, -110, 
-109, -109, -108, -108, -107, -106, -106, -106, -106, -106, -107, -107, -108, -109, -109, -109, -109, -109, -109, -108, -108, -107, -107, -106, -106, -106, -106, -107, -107, -108, -108, -109, 
-109, -109, -109, -109, -109, -108, -108, -107, -107, -106, -106, -106, -107, -107, -108, -108, -109, -109, -109, -109, -109, -109, -108, -108, -107, -107, -107, -107, -107, -107, -107, -108, 
-108, -108, -109, -109, -109, -109, -109, -108, -108, -107, -107, -107, -107, -107, -107, -107, -107, -108, -108, -109, -109, -109, -109, -109, -108, -108, -108, -107, -107, -107, -107, -107, 
-107, -107, -108, -108, -108, -109, -109, -109, -109, -108, -108, -108, -107, -107, -107, -107, -107, -107, -107, -108, -108, -108, -108, -109, -109, -109, -108, -108, -108, -108, -107, -107, 
-107, -107, -107, -107, -107, -108, -108, -108, -109, -109, -109, -108, -108, -108, -108, -107, -107, -107, -107, -107, -107, -107, -108, -108, -108, -108, -109, -109, -109, -108, -108, -108, 
-107, -107, -107, -107, -107, -107, -107, -108, -108, -108, -108, -109, -109, -109, -108, -108, -108, -108, -107, -107, -107, -107, -107, -107, -107, -108, -108, -108, -108, -109, -109, -108, 
-108, -108, -108, -107, -107, -107, -107, -107, -107, -107, -108, -108, -108, -108, -108, -108, -108, -108, -108, -108, -108, -107, -107, -107, -107, -107, -107, -108, -108, -108, -108, -108, 
-108, -108, -108, -108, -108, -108, -107, -107, -107, -107, -107, -107, -107, -108, -108, -108, -108, -108, -108, -108, -108, -108, -108, -107, -107, -107, -107, -107, -107, -107, -108, -108, 
-108, -108, -108, -108, -108, -108, -108, -108, -108, -107, -107, -107, -107, -107, -107, -108, -108, -108, -108, -108, -108, -108, -108, -108, -108, -108, -107, -107, -107, -107, -107, -107, 
-108, -108, -108, -108, -108, -108, -108, -108, -108, -108, -108, -108, -107, -107, -107, -107, -107, -107, -108, -108, -108, -108, -108, -108, -108, -108, -108, -108, -108, -107, -107, -107, 
-107, -107, -107, -108, -108, -108, -108, -108, -108, -108, -108, -108, -108, -108, -107, -107, -107, -107, -107, -107, -108, -108, -108, -108, -108, -108, -108, -108, -108, -108, -108, -108, 
-107, -107, -107, -107, -107, -107, -108, -108, -108, -108, -108, -108, -108, -108, -108, -108, -108, -107, -107, -107, -107, -107, -107, -108, -108, -108, -108, -108, -108, -108, -108, -108, 
-108, -108, -107, -107, -107, -107, -107, -107, -107, -108, -108, -108, -108, -108, -108, -108, -108, -108, -108, -108, -107, -107, -107, -107, -107, -107, -108, -108, -108, -108, -108, -108, 
-108, -108, -108, -108, -108, -107, -107, -107, -107, -107, -107, -108, -108, -108, -108, -108, -108, -108, -108, -108, -108, -108, -107, -107, -107, -107, -107, -107, -107, -108, -108, -108, 
-108, -108, -108, -108, -108, -108, -108, -108, -107, -107, -107, -107, -107, -107, -108, -108, -108, -108, -108, -108, -108, -108, -108, -108, -108, -107, -107, -107, -107, -107, -107, -108, 
-108, -108, -108, -108, -108, -108, -108, -108, -108, -108, -108, -107, -107, -107, -107, -107, -107, -108, -108, -108, -108, -108, -108, -108, -108, -108, -108, -108, -107, -107, -107, -107, 
-107, -107, -108, -108, -108, -108, -108, -108, -108, -108, -108, -108, -108, -107, -107, -107, -107, -107, -107, -108, -108, -108, -108, -108, -108, -108, -108, -108, -108, -108, -108, -107, 
-107, -107, -107, -107, -107, -108, -108, -108, -108, -108, -108, -108, -108, -108, -108, -108, -107, -107, -107, -107, -107, -107, -108, -108, -108, -108, -108, -108, -108, -108, -108, -108, 
-108, -107, -107, -107, -107, -107, -107, -107, -108, -108, -108, -108, -108, -108, -108, -108, -108, -108, -107, -107, -107, -107, -107, -107, -107, -108, -108, -108, -108, -108, -108, -108, 
-108, -108, -108, -108, -107, -107, -107, -107, -107, -107, -108, -108, -108, -108, -108, -108, -108, -108, -108, -108, -108, -107, -107, -107, -107, -107, -107, -107, -108, -108, -108, -108, 
-109, -109, -108, -108, -108, -108, -107, -107, -107, -107, -107, -107, -107, -108, -108, -108, -108, -109, -109, -109, -108, -108, -108, -108, -107, -107, -107, -107, -107, -107, -107, -108, 
-108, -108, -109, -109, -109, -108, -108, -108, -108, -107, -107, -107, -107, -107, -107, -107, -108, -108, -108, -108, -109, -109, -109, -108, -108, -108, -107, -107, -107, -107, -107, -107, 
-107, -108, -108, -108, -108, -109, -109, -109, -108, -108, -108, -108, -107, -107, -107, -107, -107, -107, -107, -108, -108, -108, -109, -109, -109, -109, -108, -108, -108, -107, -107, -107, 
-107, -107, -107, -107, -108, -108, -108, -109, -109, -109, -109, -109, -108, -108, -107, -107, -107, -107, -107, -107, -107, -107, -108, -108, -109, -109, -109, -109, -109, -108, -108, -108, 
-107, -107, -107, -107, -107, -107, -107, -108, -108, -109, -109, -109, -109, -109, -109, -108, -108, -107, -107, -106, -106, -106, -107, -107, -108, -108, -109, -109, -109, -109, -109, -109, 
-108, -108, -107, -107, -106, -106, -106, -106, -107, -107, -108, -108, -109, -109, -109, -109, -109, -109, -108, -107, -107, -106, -106, -106, -106, -106, -107, -108, -108, -109, -109, -110, 
-110, -110, -109, -108, -108, -107, -106, -106, -106, -106, -106, -107, -107, -108, -109, -110, -110, -110, -110, -110, -109, -108, -107, -106, -105, -105, -105, -105, -106, -107, -108, -109, 
-110, -111, -111, -111, -110, -109, -108, -107, -106, -105, -104, -104, -104, -105, -106, -108, -109, -110, -111, -112, -112, -112, -111, -109, -107, -106, -104, -103, -102, -103, -103, -105, 
-107, -109, -111, -113, -115, -115, -114, -113, -111, -108, -105, -101, -99, -98, -97, -99, -101, -105, -110, -116, -121, -125, -127, -126, -123, -115, -104, -88, -70, -48, -24, 
 };

#endif