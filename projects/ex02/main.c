/*----------------------------------------------------------------------------
 * Header files
 *---------------------------------------------------------------------------*/
 
#include "RTE_Components.h"     // Component selection
#include CMSIS_device_header    // Device header file (actually not required in this project)

/*----------------------------------------------------------------------------
 * Constants
 *---------------------------------------------------------------------------*/
 
#define   CONST1   0x42
const int CONST2 = 0x42;

/*----------------------------------------------------------------------------
 * Variables
 *---------------------------------------------------------------------------*/
 
volatile uint8_t   cVar1 = 48;      // stdint.h type for unsigned char
volatile uint8_t   cVar2 = 72;      // stdint.h type for unsigned char
volatile float     fVar1 = 3.14159;
volatile float     fVar2 = 8.85418;
volatile int32_t   iVar1 = 200;     // stdint.h type for int
volatile int32_t   iVar2 = 2000;    // stdint.h type for int
volatile uint32_t  uVar1 = 4000;    // stdint.h type for unsigned int
volatile uint32_t  uVar2 = 8000;    // stdint.h type for unsigned int

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
  
  iVar1 -= iVar2;         // Compound assignment operator
  
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

  // 3. Bitwise exclusive OR
	uVar2 ^= CONST2;        // Bitwise exclusive OR operation

  // 4. Bitwise inclusive OR
	uVar2 |= CONST2;        // Bitwise inclusive OR operation

  // Making decisions
  // 1. Conditional operator
	uVar1 = (cVar1 < cVar2) ? iVar1 : iVar2;

  // 2. Comma operator
	uVar2 = (cVar1++ , cVar2++);

  // Making decisions using if, else if, else...
  // 1. Evaluating two conditions
	if((iVar2 >= iVar1) && (fVar2 >= fVar1)) {
    uVar1++;              // Increment uVar1
	}
  
  // 2. Continue
	else if (cVar1 > 42) {
		uVar2--;              // Decrement uVar2
	}

  // 3. Continue
	else {
		fVar2 = 1.11;         // Set fVar2 equal to 1.11
	}

  // Endless loop
  while(1);
}
