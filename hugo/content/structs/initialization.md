---
title: "Initialization of structure variables"
weight: 5
---

If `typeName` or `structName` have already been defined:

**Syntax**

```c
typeName variableName = {const1, ..., constn};
// or
struct structName variableName = {const1, ...,constn};
```

**Code example**

```c
// structure type to handle color values
typedef struct {
    int red;
    int green;
    int blue;
} rgb;
...
rgb color = {0, 145, 189};
```