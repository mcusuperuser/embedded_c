---
title: "Passing a function to a function"
weight: 3
---

The following example shows the basic concept:

**Code example**

```c
int a, b;
int add(int n, int m); // Function prototype
int sub(int n, int m); // Function prototype

//Function definition with function pointer parameter
int foobar(int n, int n, int (*fp)(int, int)) {
    return fp(n, m);   // Call function passed by pointer
}

void main(void) {
    a = foobar (2, 72, &add); // Pass address of add
    b = foobar (31, 2, &sub); // Pass address of sub
}
```