---
title: "Using arrays of structures"
weight: 10
---

If the `arrayName` has already been defined:

**Syntax**

```c
arrayName[n].memberName
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

int main (void) {
    aColor[0].red   = 0;
    aColor[0].green = 145;
    aColor[0].blue  = 189;
    ...
}
```