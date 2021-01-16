---
title: "Passing parameters by value"
date: 2020-12-23T22:17:44+01:00
weight: 6
---

Parameters are passed to a function *by value*. These values are copied into the local parameter variables. This means, that the original variable that is passed to a function cannot be modified by the function, since only a copy of its value was passed.

**Code example**

```c
int n = 5, m = 10, res;
int minimum (int a, int b);

int main (void) {
    res = minimum (n, m);  // the value of n is copied into a
                           // the value of m is copied into b
    printf("The minimum is %d\n", res);
}

int minimum (int a, int b) {
    return ((a <= b) ? a : b);
}
```
