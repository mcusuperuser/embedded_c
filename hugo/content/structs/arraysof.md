---
title: "Creating arrays of structures"
weight: 8
---

There are two ways to create arrays of structures. If the `typeName` or the `structName` have already been defined:

**Syntax**

```c
typeName arrayName[n];
// or
struct structName arrayName[n];
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
rgb aColor[2];
```