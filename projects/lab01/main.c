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
const int CONST2 = 0xAB;

/*----------------------------------------------------------------------------
 * Variables
 *---------------------------------------------------------------------------*/
 
int myVar1 = CONST1;
int myVar2;

/*----------------------------------------------------------------------------
 * main() function
 *---------------------------------------------------------------------------*/

int main(void) {
	// Initialize variables
	myVar2 = CONST2;

  // Print value of each variable
	printf("The 1st constant is 0x%X\n", myVar1);
	printf("The 2nd constant is 0x%X\n", myVar2);

  // Endless loop
	while(1);
}
