# Comments

What is a comment?

!!! Important
    Comments are used to document a program's functionality. They explain what a particular block or line of code doess.
    Comments are always ignored by the compiler.

There are two kinds of comments:

### Block comment

```c
/* This is a block comment. */
```

- Block comments begin with `/*` and end with `*/`
- They can span multiple lines

**Code example**

```c
/*-----------------------------------------------
 * CMSIS-RTOS 'main' function template
 *---------------------------------------------*/

#include "cmsis_os2.h"

/*
 * main: initialize and start the system
 */
int main (void) {
  osKernelInitialize (); /* initialize RTOS */
  
  LED_Initialize();      /* initialize LEDs */
  /* create 'thread' functions that
     start executing. Example:
     tid_name=osThreadCreate (osThread(name), NULL);
  */

  osKernelStart (); /* start thread execution */
}
```

### Single line comment

```c
// This is a single line comment.
```

- Single line comments begin with `//` and run until the end of the current line 
- They can *not* span multiple lines

**Code example**

```c
//-----------------------------------------------
// CMSIS-RTOS 'main' function template
//-----------------------------------------------

#include "cmsis_os2.h"

// main: initialize and start the system

int main (void) {
  osKernelInitialize (); // initialize RTOS
  
  LED_Initialize();      // initialize LEDs
  // create 'thread' functions that start executing
  // Example:
  // tid_name=osThreadCreate (osThread(name), NULL);

  osKernelStart (); // start thread execution
}
```

### Nesting comments

- Block comments must not be nested within other comments
- Single line comments may be nested

**Code example**

```c
/*-----------------------------------------------
 * CMSIS-RTOS 'main' function template
 * // comment within a comment
 *---------------------------------------------*/

#include "cmsis_os2.h"

/*
 * main: initialize and start the system
 */
int main (void) {
  osKernelInitialize (); /* initialize RTOS */
  
  LED_Initialize();      /* initialize LEDs */
  /* create 'thread' functions that start
     executing,
     /* another comment which doesn't work  */
     example:
     tid_name=osThreadCreate (osThread(name), NULL);
  */

  osKernelStart (); /* start thread execution */
}
```
