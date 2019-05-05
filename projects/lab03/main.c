#include <stdio.h>              // Standard I/O - required for printf() function
#include "ARMCM3.h"                     // Device header
#include "arm_math.h"                   // ARM::CMSIS:DSP


typedef union {
    uint8_t m;
    uint16_t n;
    uint32_t l;
} myUnion;

myUnion univar;

// main() function
int main(void) {
	univar.m = 0xFF;
	univar.n = 0xFFFF;
	univar.l = 0xFFFFFFFF;
  // Endless loop
	while(1);
}
