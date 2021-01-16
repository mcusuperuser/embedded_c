+++
title = "The printf() C library function"
date = 2020-12-23T16:06:38+01:00
weight = 4
chapter = true
pre = "<b>4. </b>"
+++

### Chapter 4

# The printf() C library function

One of the most commonly used C library function is the `printf()` function which allows to write text to the "standard output" (normally a monitor or line printer). In embedded systems, often a UART is used. In Arm Cortex-M based systems you can redirect the standard output to the ITM debug channel which saves resources (the UART) and is much faster. In µVision, you can use the ["Debug printf() Viewer"](https://www.keil.com/support/man/docs/uv4/uv4_db_dbg_printf_viewer.htm) window to observe `printf()` messages delivered via ITM.