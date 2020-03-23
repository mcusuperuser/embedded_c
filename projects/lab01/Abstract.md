# Lab 01

This lab shows how to declare and use constants and how to use the `printf()`
function to print messages on the **Debug printf() Viewer** window in µVision.

The example runs in simulation on an Arm Cortex-M3 device. It is fully CMSIS
compliant.

## Instructions

- **Build (F7)** the project
- **Start a debug session (F5)**
- Observe the output on the **Debug printf() Viewer** window
- Check the value of the variables in the **Watch1** window

## Details

This project uses the following software components:
- ::CMSIS:Core to give access to the Arm Cortex-M3 core and peripherals
- ::Compiler:I/O:STDOUT - ITM variant to redirect the `printf()` output to the **Debug printf() Viewer** window
- ::Device:Startup for system and startup purposes