---
title: "Extern variables"
date: 2020-12-23T22:28:42+01:00
weight: 4
---

 The `extern` storage class keyword tells the compiler that the variable is defined elsewhere and will be used in the current scope. Thus, it still needs to be declared within the current scope. 
 
 A variable declared as `extern` outside of any function is used to indicate that the variable is defined in another source file. Memory is only allocated for it when it's defined.

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
