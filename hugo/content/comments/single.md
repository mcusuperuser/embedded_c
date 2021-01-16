---
title: "Single line comment"
date: 2020-12-23T16:25:54+01:00
weight: 3
---

**Syntax**

```c
// This is a single line comment.
```

- Single line comments begin with `//` and run until the end of the current line.
- They can *not* span multiple lines.

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
