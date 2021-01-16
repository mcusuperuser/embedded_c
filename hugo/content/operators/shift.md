---
title: "Shift operators"
weight: 6
---

| Operator | Operation           | Example  | Result |
|:--------:|:--------------------|:--------:|--------|
| `<<`     | Bitwise left shift  | `a << b` | Shift `a` by `b` bits to the left
| `>>`     | Bitwise right shift | `a >> b` | Shift `a` by `b` bits to the right

{{% notice note %}}
Bits that are shifted out are lost (in both cases).  
For shift left, 0's are shifted in (zero fill).
{{% /notice %}}

**Code example**

```c
// Logical shift right (zero fill)
// If a is unsigned:
unsigned char a;
a = 250;    // a = 0b11111010 = 250
b = a >> 2; // b = 0b00111110 = 62

// Arithmetic shift right (sign extend)
// If a is signed:
char a;
a = -6;     // a = 0b11111010 = -6
b = a >> 2; // b = 0b11111110 = -2
```

**Power of 2 integer divide vs. shift right**

{{% notice tip %}}
Generally, it is more efficient to use a shift right instead of dividing by a power of 2. This means that `b = a / 2^n` is equal to `b = a >> n`. This trick works for integer and fixed point values.
{{% /notice %}}
