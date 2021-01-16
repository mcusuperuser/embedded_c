---
title: "Using structure variables"
weight: 3
---

**Syntax**

```c
structVariableName.memberName;
```

**Code example**

```c
// structure to handle color values
struct rgb {
    int red;
    int green;
    int blue;
} color;

int main (void){
    color.red   = 0;   // set   red portion of color
    color.green = 145; // set green portion of color
    blue        = 189; // set  blue portion of color
}
```