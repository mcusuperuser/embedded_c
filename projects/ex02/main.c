/*----------------------------------------------------------------------------
 * Header files
 *---------------------------------------------------------------------------*/
 
#include "RTE_Components.h"     // Component selection
#include CMSIS_device_header    // Device header file (actually not required in this project)
#include <stdio.h>              // Required for printf() function

/*----------------------------------------------------------------------------
 * Constants
 *---------------------------------------------------------------------------*/
 
#define   CONST1   0x42
const int CONST2 = 0x42;

/*----------------------------------------------------------------------------
 * Variables
 *---------------------------------------------------------------------------*/
 
uint8_t   cVar1 = 48;      // stdint.h type for unsigned char
uint8_t   cVar2 = 72;      // stdint.h type for unsigned char
float     fVar1 = 3.14159;
float     fVar2 = 8.85418;
int32_t   iVar1 = 200;     // stdint.h type for int
int32_t   iVar2 = 2000;    // stdint.h type for int
uint32_t  uVar1 = 4000;    // stdint.h type for unsigned int
uint32_t  uVar2 = 8000;    // stdint.h type for unsigned int

/*-----------------------------------------------------------------------------
 *  Function prototypes
 *---------------------------------------------------------------------------*/
int main(void);

/*----------------------------------------------------------------------------
 * main() function
 *---------------------------------------------------------------------------*/

int main(void) {
  // Basic math
  // 1. Add cVars
	cVar2 = cVar1 + cVar2;  // Addition operator
      
	cVar2 += cVar1;         // Compound assignment operator
  
  // 2. Increment cVar1
  cVar1 = cVar1 + 1;      // Addition operator
  
	cVar1++;                // Compound assignment operator

  // 3. Subtract iVars
	iVar1 = iVar1 - iVar2;  // Subtraction operator
  
  // 4. Decrement iVar2
  iVar2 = iVar2 - 1;      // Subtraction operator

	iVar2--;                // Compound assignment operator
  
  // 5. Multiplication
	uVar2 = uVar1 * uVar2;  // Multiplication operator

  uVar2 *= uVar1;         // Compound assignment operator

  // 6. Division
	fVar1 = fVar1 / fVar2;  // Division operator

	fVar1 /= fVar2;         // Compound assignment operator

  // Bit-level operations
  // 1. Shift one bit
	uVar2 >>= 1;            // Compound assignment operator
  
  // 2. Bitwise AND
 	uVar1 &= CONST1;        // Bitwise AND operation

  // 3. Bitwise AND
	uVar2 ^= CONST2;        // Bitwise exclusive OR operation

  // 4. Bitwise AND
	uVar2 |= CONST2;        // Bitwise inclusive OR operation

  // Making decisions
  // 1. Conditional operator
	uVar1 = (cVar1 < cVar2) ? iVar1 : iVar2;

  // 2. Comma operator
	uVar2 = (cVar1++ , cVar2++);

  // Endless loop
  while(1) {
    uVar2++;                       // Increment uVar2
//    printf("Variable uVar2 is %d\n", uVar2);
  }
}
