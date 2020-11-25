# Exercise 02

In this exercise, you will use variables to do some calculations with different
operators and make decisions based on the values of the variables.

The final exercise runs in simulation on an Arm Cortex-M3 device. It is fully
[**CMSIS**](https://github.com/arm-software/CMSIS_5) compliant.

# Instructions

## Do the exercise

All variables have been declared in the 'Variables' section. Use them to do the
following operations:

### Basic math

1. Add cVar1 to cVar2 and store the result in cVar2. Use two different ways to
   accomplish this.
2. Use two different ways to increment cVar1.
3. Use two different ways to subtract iVar2 from iVar1 and store the result in
   iVar1.
4. Use two different ways to decrement iVar2.
5. Use two different ways to multiply uVar2 by uVar1 and store the results in
   uVar2.
6. Use two different ways to divide fVar1 by fVar2 and store the results in
   fVar1.

### Bit-level operations

1. Shift uVar2 one bit to the right using a compound assignment operator.
2. Perform the bitwise AND operation (`uVar1 AND CONST1`) and store the result
   in uVar1.
3. Perform the bitwise (exclusive) OR operation (`uVar2 ^ CONST2`) and store
   the result in uVar2.
4. Perform the bitwise (inclusive) OR operation (`uVar2 | CONST2`) and store
   the result in uVar2.

### Making decisions

1. Use the conditional operator to set uVar1 equal to iVar1 if cVar1 is less
   than cVar2. Otherwise, set uVar1 equal to iVar2.
2. Use the comma operator to increment cVar1, then increment cVar2 and finally
   assign the new value of cVar2 to uVar2.
   
### Making decisions using if, else if, else statements and comparison operators

1. Increment uVar1 if both of the following conditions are true. iVar2 is
   greater than or equal to iVar1 AND fVar2 is greater than or equal to fVar1.
   To accomplish this, you need to use parentheses to group logical
   operations.
2. If the above is not true, and cVar1 is greater than 42, then decrement uVar2.
3. If neither of the above is true, set fVar2 equal to 1.11.

## Run the exercise

- **Build (F7)** the project
- **Start a debug session (F5)**
- Check the value of the variables in the [**Watch1**](http://www.keil.com/support/man/docs/uv4/uv4_db_dbg_watchwin.htm)
  window

*Note*

- If you have difficulties with the exercise, use the
  [**project target**](http://www.keil.com/support/man/docs/uv4/uv4_ca_projtargfilegr.htm)
  "Finished" to build and run a fully functional version.

# Details

This project uses the following software components:
- ::CMSIS:Core to give access to the Arm Cortex-M3 core and peripherals
- ::Device:Startup for system and startup purposes