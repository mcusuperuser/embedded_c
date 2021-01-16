---
title: "Initializing arrays of structures at declaration"
weight: 9
---

If the `typeName` or the `structName` have already been defined:

**Syntax**

```c
typeName arrayName[n] = {{list1}, ..., {listn}};
// or
struct structName arrayName[n] = {{list1}, ..., {listn}};
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
rgb aColor[2] = {{0, 0, 0}, {255, 255, 255}};
```
