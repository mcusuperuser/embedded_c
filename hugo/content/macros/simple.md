---
title: "Simple macros"
weight: 1
---

Macros:

- Are evaluated by the preprocessor
- Cannot be executed by themselves
- Are used to control the generation of code before the compilation process
- Provide valuable shortcuts

**Syntax**

```c
#define label text
```

{{% notice note %}}
Every instance of `label` in the current file will be replaced by `text`.  
`text` can be anything you can type into your editor.  
Arithmetic expressions are evaluated at compile time.
{{% /notice %}}

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