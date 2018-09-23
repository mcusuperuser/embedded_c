#include <stdio.h>              // Standard I/O - required for printf() function

// Constants
#define   CONST1 0x42
const int CONST2 = 0xAB;

// Variables
int myVar1 = CONST1;
int myVar2;

// main() function
int main(void) {
	// Initialize variables
	myVar2 = CONST2;

  // Print value of each variable
	printf("The first constant is 0x%X\n", CONST1);
	printf("The second constant is 0x%X\n", CONST2);

  // Endless loop
	while(1);
}
