---
title: "Block comment"
date: 2020-12-23T16:25:49+01:00
weight: 2
---

**Syntax**

```c
/* This is a block comment. */
```

- Block comments begin with `/*` and end with `*/`.
- They can span multiple lines.

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
