---
title: "Nesting comments"
date: 2020-12-23T16:26:02+01:00
weight: 4
---

- Block comments *must not* be nested within other comments.
- Single line comments *may* be nested.

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
