# Variables, identifiers and data types

What is a variable?

!!! Important
    A variable is a name that represents one or more memory locations used to hold program data.

A variable is a kind of bucket that you can use to hold program data.

**Code example**

```c
int myVar;
myVar = 42;
```

- Variable declarations consist of a **data type** and a unique **identifier (name)**

```c
int   myVar;
char  myLetter;
float myFLoat,
```

- The data type determines the size of the memory location that is used to store the variable and determines how the value of the variable is interpreted.

## Identifiers

What are identifiers?

!!! Important
    Identifiers are names that are given to program elements, such as variables, functions, arrays, or any other named
    element.

- Valid characters in identifiers are '_', 'a' to 'z', 'A' to 'Z', and '0' to '9' (not allowed for the first character).
- Identifiers are case sensitive, so `myVar` is not the same as `myvar`!
- You *must not use* keywords of the C language as identifiers.
- The Arm compiler provides additional keywords that are extensions to the C/C++ standards and *must also not be used* as identifiers.

### ANSI C keywords

| | | | | |
|---|---|---|---|---|
| auto | break | case | char | const |
| continue | default | do | double | else |
| enum | extern | float | for | goto |
| if | int | long | register | return |
| short | signed | sizeof | static | struct |
| switch | typedef | union | unsigned | void |
| volatile | while ||||

### Arm compiler 6 (armclang) keywords and operators

| | | | |
|---|---|---|---|
| \_\_alignof\_\_ | \_\_asm | \_\_declspec | \_\_inline |

## Data types

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

!!! Note
    - Integers are represented in [two's complement](https://en.wikipedia.org/wiki/Two%27s_complement "Two´s complement on Wikipedia") form.
    - Floating-point quantities are stored in [IEEE format](https://en.wikipedia.org/wiki/IEEE_754 "IEEE 754 on Wikipedia").

### How to declare a variable

```c
type identifier1, identifier2, ..., identifiern;
```

- Variables must be declared before they can be used
- The type is important! It tells the compiler how much memory space to allocate and how handle the values

```c
char   myFirstLetter;
int    a, b, c;
float  currentSpeed;
double sensorValue;
```

There are multiple ways to declare a variable:

**Declaration on a single line**

```c
type name;
```

**Declaration on a single line with an initial value**

```c
type name = initialValue;
```

**Multiple declarations of the same type on a single line**
```c
type name1, name2, name3;
```

**Multiple declarations of the same type on a single line with initial values**

```c
type name1 = value1, name2 = value2, name3;
```

**Code example**

```c
unsigned int myVar;
signed int   answer = 42;
char         myFirstLetter = 'a', mySecondLetter, myLastLetter = 'z';
float        hugeNumber = 5.12e+21
```

## Using typedefs

**Syntax**

```c
typedef type typeName;
```

- Typedefs are an alternative way to name types and create an alias name for the type.
- The *typeName* is now the same as the type

**Code example**

```c
typedef unsigned int uint32_t;

uint32_t a, b;    // alias for unsigned int a, b;
```

### Declaring variables

*Header* files are used to declare variables and other program elements in a separate file. Usually, header files have the filename extension *.h*. To use a header file in your C code, associate it with the `#include` directive.

The `#include` directive can be used in three different ways. You can:

1. Look for a header file in the compiler include path, which contains the compiler's directory and all of its sub-directories:

```c
#include <stdio.h>
```

2. Look for a file in the project directory:

```c
#include "myHeader.h"
```

3. Look for a file using an absolute or relative path:

```c
#include "..\..\myHeader2.h"
#include "C:\projects\myProject\inc\myHeader3.h"
```

**Code example**

`main.h` header file:

```c
int   n, m, p;
float myFloat;
```

`main.c` source file:

```c
#include "main.h"

int main (void) {
    n = 3;
    m = 1;
    p = n - m;
    myFLoat = 1 / p;
}
```

Using the `#include` directive, the contents of the main.h header file are pasted into the main.c source file, starting at the `#include` directive’s line.

After the preprocessor runs, the compiler sees the main.c source file as follows:

```c
int n, m, p;
float myFloat;

int main (void) {
    n = 3;
    m = 1;
    p = n - m;
    myFloat = 1 / p;
}
```
