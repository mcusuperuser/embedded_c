---
title: "Using an enumeration type variable"
weight: 5
---

If the enumeration and the variable have already been defined:

**Syntax**

```c
varName = labeln;
```

{{% notice note %}}
Use the labels just like any other symbolic constant.  
Enumeration type variables must only use the type’s labels or equivalent integer.
{{% /notice %}}

**Code example**

```c
enum color {red, green, blue};
enum color myCar;

myCar = red;
myCar = 3;

if (myCar == 2) {
    // do something
}
```
