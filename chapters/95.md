# Macros

What are macros?

> Macros allow for complex text replacements created with `#define` that insert code into your program. While macros may take parameters like a function, the macro code and parameters are always inserted into code by text substitution (this means that data types are not taken care of).

Macros:
- Are evaluated by the preprocessor
- Cannot be executed by themselves
- Are used to control the generation of code before the compilation process
- Provide valuable shortcuts

## Simple macros

**Syntax**
```c
#define label text
```

*Note*

- Every instance of `label` in the current file will be replaced by `text`
- `text` can be anything you can type into your editor
- Arithmetic expressions are evaluated at compile time

**Code example (system_ARMCM3.c)**
```c
/*----------------------------------------------------------------------------
  Define clocks
 *----------------------------------------------------------------------------*/
#define  XTAL            (50000000UL)     /* Oscillator frequency */
#define  SYSTEM_CLOCK    (XTAL / 2U)

/*----------------------------------------------------------------------------
  System Core Clock Variable
 *----------------------------------------------------------------------------*/
uint32_t SystemCoreClock = SYSTEM_CLOCK;  /* System Core Clock Frequency */
```

## Argument macros

Argument macros create function-like macros:

**Syntax**
```c
#define label(arg1, ..., argn) code
```

*Note*

- The code must fit on a single line. For multi-line macros use '\\' to split lines
- Arguments are inserted into code as text substitutions
- Each instance of `label()` will be expanded into code

**Code example (arm_math.h)**
```c
#define __SIMD32(addr)        (*(__SIMD32_TYPE **) & (addr))
#define __SIMD32_CONST(addr)  ( (__SIMD32_TYPE * )   (addr))
#define _SIMD32_OFFSET(addr)  (*(__SIMD32_TYPE * )   (addr))
#define __SIMD64(addr)        (*(      int64_t **) & (addr))
```
