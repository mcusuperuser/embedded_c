---
title: "Unions in memory"
weight: 3
---

Union variables may be declared exactly like structure variables. The big difference is that only memory is allocated to accommodate the union’s largest member. For a structure, memory is allocated to accommodate for the whole structure.

**Code example**

```c
typedef union {
    uint8_t m;
    uint16_t n;
    uint32_t l;
} myUnion;

myUnion univar;
```

![Unions in memory](../../img/unions_in_memory.png)
