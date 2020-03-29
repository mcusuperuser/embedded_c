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
 
int    iVar;
char   cVar;
double dVar;
float  fVar = CONST2;
long   lVar = CONST2;           // Same as "long int"
short  sVar = CONST2;           // Same as "short int"

/*-----------------------------------------------------------------------------
 *  Function prototypes
 *---------------------------------------------------------------------------*/
int main(void);

/*----------------------------------------------------------------------------
 * main() function
 *---------------------------------------------------------------------------*/

int main(void) {
  // Initialize variables
  iVar = CONST1;
  cVar = CONST1;
  dVar = CONST1;

  // Print value of each variable and the size it requires in memory
  printf("The content of cVar is %c and it requires %d byte\n",   cVar, sizeof(char));
  printf("The content of sVar is %d and it requires %d bytes\n",  sVar, sizeof(short));
  printf("The content of iVar is %d and it requires %d bytes\n",  iVar, sizeof(int));
  printf("The content of lVar is %ld and it requires %d bytes\n", lVar, sizeof(long));
  printf("The content of fVar is %f and it requires %d bytes\n",  fVar, sizeof(float));
  printf("The content of dVar is %e and it requires %d bytes\n",  dVar, sizeof(double));

  // Use format specifiers to print variables
  printf("Print 42 as (d)ecimal: %d\n", 42);                         //%d = decimal int
  printf("Print 'a' as (c)haracter: %c\n", 'a');                     //%c = character
  printf("Print 'a' as (d)ecimal: %d\n", 'a');                       //%d = decimal int
  printf("Print 3.14 as (f)loat: %f\n", 3.14);                       //%f = float
  printf("Print 3.14 as (d)ecimal: %d\n", 3.14);                     //%d = decimal int; compiler will issue a warning
  printf("Print 1.44e17 as (e)xponent: %e\n", 1.44e17);              //%e = float exp
  printf("Print 1.44e17 as (d)ecimal: %d\n", 1.44e17);               //%d = decimal int; compiler will issue a warning
  printf("Print 'Arm Cortex-M' as (s)tring: %s\n", "Arm Cortex-M");  //%s = string
  printf("Print 'Arm Cortex-M' as (d)ecimal: %d\n", "Arm Cortex-M"); //%d = decimal int; compiler will issue a warning
  
  // Endless loop
  while(1);
}
