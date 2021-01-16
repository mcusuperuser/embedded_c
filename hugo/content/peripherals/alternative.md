---
title: "Alternative mechanism"
weight: 3
---

Using the CMSIS macros `_VAL2FLD(field, value)` and `_FLD2VAL(field, value)` you can access bit fields more easily.

**Code example**

```c
id = _FLD2VAL(SCB_CPUID_REVISION, SCB->CPUID); // uses the #define's _Pos and _Msk of the related bit field to extract the value of a bit field from a register.

SCB->CPUID = _VAL2FLD(SCB_CPUID_REVISION, 0x3) | _VAL2FLD(SCB_CPUID_VARIANT, 0x3); // uses the #define's _Pos and _Msk of the related bit field to shift bit-field values for assigning to a register.
```