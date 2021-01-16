---
title: "Pointers to structures"
weight: 7
---

There are two ways to declare a pointer to a structure. If the `typeName` or the `structName` have already been defined:

**Syntax**

```c
typeName *pointerName;
// or
struct structName *pointerName;
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
rgb *pColor;
```

**Code example**

```c
// structure type to handle color values
struct rgb {
    int red;
    int green;
    int blue;
}
...
struct rgb *pColor;
```

## Accessing structure members using a pointer

If a `pointerName` has already been defined:

**Syntax**

```c
pointerName -> memberName;
```

{{% notice note %}}
First, the pointer must be initialized to point to the address of the structure itself: `pointerName = &structVariable;`
{{% /notice %}}

**Code example**

```c
// structure type to handle color values
typedef struct {
    int red;
    int green;
    int blue;
} rgb;
...
rgb color;   // rgb variable
rgb *pColor; // pointer to color

int  main (void) {
    pColor        = color;
    pColor->red   = 0;     // Set   red using pColor
    pColor->green = 145;   // Set green using pColor
    pColor->blue  = 189;   // Set  blue using pColor
}
```

{{% notice note %}}
We will later see in an example how CMSIS uses this to access core peripherals of a Cortex-M based device.
{{% /notice %}}
