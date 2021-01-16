---
title: "Creating unions with typedefs"
weight: 2
---

**Syntax**

```c
typedef union unionTag {
    type1 memberName1;
    ...
    typen memberNamen;
} typeName;
```

**Code example**

```c
// Union type to access the Application Program Status Register (APSR).
typedef union
{
  struct
  {
    uint32_t _reserved0:27;    // bit:  0..26  Reserved
    uint32_t Q:1;              // bit:     27  Saturation condition flag
    uint32_t V:1;              // bit:     28  Overflow condition code flag
    uint32_t C:1;              // bit:     29  Carry condition code flag
    uint32_t Z:1;              // bit:     30  Zero condition code flag
    uint32_t N:1;              // bit:     31  Negative condition code flag
  } b;                         // Structure used for bit  access
  uint32_t w;                  // Type      used for word access
} APSR_Type;
```