---
title: "Declaring variables"
date: 2020-12-23T16:49:55+01:00
weight: 4
---

**Syntax**

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

## Declaring variables separately

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

main.h header file:
```c
int   n, m, p;
float myFloat;
```

main.c source file:
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
