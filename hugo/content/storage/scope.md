---
title: "Scope of functions"
date: 2020-12-23T22:28:53+01:00
weight: 7
---

The scope of a function depends on it storage class, which can be either `static` or `external`. The scope of a function is either local to the
file where it is defined - in case of a `static` function - or globally available to any file in a project - in case of an `external` function.

By default, functions have a global scope within a project. The `extern` keyword is not required, but a function prototype in the calling file (or a header file).

**Code example main.c**

```c
int foo (void);

int main (void) {
    ..
    a = foo();
    ..
}
```

**Code example someOtherProjectFile.c**

```c
int foo (void) {
    ..
}
```

### Library and header files

Include a header file of you library in a source file. The header file contains the variable and function declarations, while the related source file contains the variable and function definitions. 

**Code example main.c**

```c
#include someOtherProjectFile.h // include the library header file

int a; 

int main (void) {
    ..
    a = foo(); // using the function from the library
    myVar = a; // using the variable from the library
    ..
}
```

**Code example someOtherProjectFile.h**

```c
extern int myVar;

int foo (void);
```

**Code example someOtherProjectFile.c**

```c
int myVar;

int foo (void) {
    ..
}
```