---
title: "Datatypes"
date: 2020-12-23T16:42:03+01:00
weight: 3
---

C provides various data types. Normally, you would use:

- `int` for most variables and things that you can count, such as loop counts, events, and apples
- `char` for characters and strings
- `float` for measurable things that require decimal numbers, such as distance, temperature, or voltage
- `uint32_t` for bit manipulations, especially on 32-bit registers
- The appropriate `<stdint.h>`/`<arm_math.h>` types for storing and working with data explicitly meeting your needs (for example if you require that an integer has exactly N bits)

### Size and alignment of basic data types in Arm C/C++

|ANSI C Type        | stdint.h C Type  | Size in bits | Natural alignment in bytes | Range of values|
|------------------|------------------------|:------------:|:--------------------------:|:---------------|
char               | uint8_t                | 8            | 1 (byte-aligned)           | 0 to 255 (unsigned) by default.
signed char        |  int8_t                | 8            | 1 (byte-aligned)           | -128 to 127
unsigned char      | uint8_t                | 8            | 1 (byte-aligned)           | 0 to 255
signed short       |  int16_t               | 16           | 2 (halfword-aligned)       | -32,768 to 32,767
unsigned short     | uint16_t               | 16           | 2 (halfword-aligned)       | 0 to 65,535
signed int         |  int32_t               | 32           | 4 (word-aligned)           | -2,147,483,648 to 2,147,483,647
unsigned int       | uint32_t               | 32           | 4 (word-aligned)           | 0 to 4,294,967,295
signed long        |                        | 32           | 4 (word-aligned)           | -2,147,483,648 to 2,147,483,647
unsigned long      |                        | 32           | 4 (word-aligned)           | 0 to 4,294,967,295
signed long long   |  int64_t               | 64           | 8 (doubleword-aligned)     | -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807
unsigned long long | uint64_t               | 64           | 8 (doubleword-aligned)     | 0 to 18,446,744,073,709,551,615
float              | float32_t <arm_math.h> | 32           | 4 (word-aligned)           | 1.175494351e-38 to 3.40282347e+38 (normalized values)
double             | float64_t <arm_math.h> | 64           | 8 (doubleword-aligned)     | 2.22507385850720138e-308 to 1.79769313486231571e+308 (normalized values)
long double        | float64_t <arm_math.h> | 64           | 8 (doubleword-aligned)     | 2.22507385850720138e-308 to 1.79769313486231571e+308 (normalized values)
All pointers       |                        | 32           | 4 (word-aligned)           | Not applicable.
bool (C++ only)    |                        | 8            | 1 (byte-aligned)           | false or true
\_Bool (C only)    |                        | 8            | 1 (byte-aligned)           | false or true

{{% notice note %}}
Integers are represented in [two's complement](https://en.wikipedia.org/wiki/Two%27s_complement "Two´s complement on Wikipedia") form.  
Floating-point quantities are stored in [IEEE format](https://en.wikipedia.org/wiki/IEEE_754 "IEEE 754 on Wikipedia").
{{% /notice %}}
