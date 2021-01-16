---
title: "Using bit fields"
weight: 1
---

**Syntax**
```c
struct structName {
    unsigned int memberName1: bitWidth;
    ...
    unsigned int memberNamen: bitWidth;
}
```

**Code example**
```c
// bit field struct may be celared normally or as a typedef
typedef struct {
    unsigned int x:10;
    unsigned int y:20;
} myBits;
```

## Using bit fields

**Code example**

```c
struct myByteBits {
    unsigned int volts: 1;
    unsigned int amps: 1;
    unsigned int ohm: 1;
    unsigned int humid: 3;
    unsigned int temp: 2;
} a;

int main (void) {
    a.volts = 1;    //may contain values from 0 to 1
    a.amps  = 0;    //may contain values from 0 to 1
    a.ohm   = 0;    //may contain values from 0 to 1
    a.humid = 0b10; //may contain values from 0 to 7
    a.temp  = 0x0;  //may contain values from 0 to 3
}
```

{{% notice note %}}
Bit fields:
- are ordinary members of a structure.
- have a specified bit width.
- are often used in conjunction with unions to provide bit access to a variable without masking operations.
{{% /notice %}}
