---
title: "Static variables"
date: 2020-12-23T22:28:37+01:00
weight: 3
---

Variables declared as `static` preserve their value even after they are out of their scope, as they are given a permanent address in memory. They are created/initialized once when the program starts and are only destroyed when the program ends! Their scope is local to the function to which they were defined. Global static variables can be accessed anywhere in the program. By default, they are assigned the value 0 by the compiler.

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

{{% notice note %}}
A variable declared as static inside a function retains its value between consecutive function calls.  
If given an initial value, a `static` variable is only initialized when first created – not during each function call.
{{% /notice %}}
