# Exercise 01

This exercise shows how to declare and use constants and variables and how to
use the `printf()` function to print messages (with various format specifiers)
on the **Debug printf() Viewer** window in µVision.

The example runs in simulation on an Arm Cortex-M3 device. It is fully CMSIS
compliant.

# Instructions

## Do the exercise

- In the `Constants` section, declare two constants ("CONST1" and "CONST2")
- using a `#define` and a `const` statement.
- In the `Variables` section, initialize the variables "fVar", "lVar", and
- "sVar" with the value of "CONST2".
- In `main()`, initialize the variables "iVar", "cVar", and "dVar" with the
- value of "CONST2".
- Use the code snippet `printf("\n",   variable, sizeof(char));` to do the
- following for each variable. Print the sentence "The content of \<variable\>
- is \<print the value\> and it requires \<print the size of the variable\>".
- Test the different format specifiers with `printf`.

## Run the exercise

- **Build (F7)** the project
- **Start a debug session (F5)**
- Observe the output on the **Debug printf() Viewer** window
- Check the value of the variables in the **Watch1** window
- Play with the variable display in the **Watch1** window (right-click the
  variable and use different formats, for example disable "Hexadecimal
  display")

*Note*

- If you have difficulties with the exercise, use the project target "Finished"
  to build and run a fully functional version.

# Details

This project uses the following software components:
- ::CMSIS:Core to give access to the Arm Cortex-M3 core and peripherals
- ::Compiler:I/O:STDOUT - ITM variant to redirect the `printf()` output to the
  **Debug printf() Viewer** window
- ::Device:Startup for system and startup purposes