---
title: "Argument macros"
weight: 2
---

Argument macros create function-like macros:

**Syntax**

```c
#define label(arg1, ..., argn) code
```

{{% notice note %}}
The code must fit on a single line. For multi-line macros use '\\' to split lines
Arguments are inserted into code as text substitutions
Each instance of `label()` will be expanded into code
{{% /notice %}}

**Code example (arm_math.h)**

```c
#define __SIMD32(addr)        (*(__SIMD32_TYPE **) & (addr))
#define __SIMD32_CONST(addr)  ( (__SIMD32_TYPE * )   (addr))
#define _SIMD32_OFFSET(addr)  (*(__SIMD32_TYPE * )   (addr))
#define __SIMD64(addr)        (*(      int64_t **) & (addr))
```
