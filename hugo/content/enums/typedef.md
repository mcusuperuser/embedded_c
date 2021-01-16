---
title: "Declare an enumeration type with `typedef`"
weight: 4
---

As always, variables can be declared as type `typeName` without requiring the keyword `enum`:

**Syntax**

```c
typedef enum {list_of_constants} typeName;
```

The enumeration can now be used as an ordinary data type, such as `int` or `float`.

**Code example**

```c
typedef enum {JAN, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC} month;
month current_month; // Variable of type month
```
