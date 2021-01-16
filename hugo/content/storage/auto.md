---
title: "Auto variables"
date: 2020-12-23T22:28:32+01:00
weight: 2
---

The default storage class for all variables declared inside a function or a block is `auto`. Auto variables can be only accessed within the block/function they have been declared and not outside them. To access them outside their scope, use a pointer to the very exact memory location where the variables resides. They are assigned a garbage value by default whenever they are declared. As `auto` is the default, the keyword `auto` is rarely used. Typically, `auto` variables are created on the stack.

**Code example**

```c
int foo (char n, float m) {  // n, m are auto variables
    int j, k;                // j, k are auto variables
}
```