# Storage classes

Storage classes describe the features of a variable/function. These features basically include the scope, visibility
and lifetime. They are used to trace the existence of a certain variable during the runtime of a program.

*Scope* refers to where in a program a variable may be accessed. *Lifetime* refers to how long a variable will exist
or retain its value.

In C, four storage classes are available:

- [Automatic](#auto-variables)
- [Static](#static-variables)
- [External](#extern-variables)
- [Register](#register-variables)

**Syntax**

```c
storage_class type identifier;
```

## Auto variables

The default storage class for all variables declared inside a function or a block is `auto`. Auto variables can be only
accessed within the block/function they have been declared and not outside them. To access them outside their scope,
use a pointer to the very exact memory location where the variables resides. They are assigned a garbage value by
default whenever they are declared. As `auto` is the default, the keyword `auto` is rarely used. Typically, `auto`
variables are created on the stack.

**Code example**

```c
int foo (char n, float m) {  // n, m are auto variables
    int j, k;                // j, k are auto variables
}
```

## Static variables

Variables declared as `static` preserve their value even after they are out of their scope, as they are given a
permanent address in memory. They are created/initialized once when the program starts and are only destroyed when the
program ends! Their scope is local to the function to which they were defined. Global static variables can be accessed
anywhere in the program. By default, they are assigned the value 0 by the compiler.

**Code example**

```c
int a; // global variable is static

int main (void) {
    a = 23;
    ..
}
```

**Code example main.c**

```c
float foo (float f) {
    static float a = 3.141;
    ..
    a -= f;
    return a;
}
```

!!! Note
    - A variable declared as static inside a function retains its value between consecutive function calls.
    - If given an initial value, a `static` variable is only initialized when first created – not during each function
    call.

## Extern variables

The `extern` storage class keyword tells the compiler that the variable is defined elsewhere and will be used in the
current scope. Thus, it still needs to be declared within the current scope. 

A variable declared as `extern` outside of any function is used to indicate that the variable is defined in another
source file. Memory is only allocated for it when it's defined.

**Code example main.c**

```c
extern int a;

int main (void) {
    a = 23;
    ..
}
```

**Code example someOtherProjectFile.c**

```c
int a;

int foo (void) {
    ..
}
```

## Register variables

This storage class declares `register` variables which have the same functionality as `auto` variables. Arm Compiler v6 ignores this keyword.

## Scope of functions

The scope of a function depends on it storage class, which can be either `static` or `external`. The scope of a
function is either local to the
file where it is defined - in case of a `static` function - or globally available to any file in a project - in case of
an `external` function.

By default, functions have a global scope within a project. The `extern` keyword is not required, but a function
prototype in the calling file (or a header file).

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

Include a header file of you library in a source file. The header file contains the variable and function declarations
while the related source file contains the variable and function definitions.

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
