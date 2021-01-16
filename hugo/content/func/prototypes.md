---
title: "Function prototypes"
date: 2020-12-23T22:17:36+01:00
weight: 5
---

Just like a variable, a function must be declared before it may be used. This declaration must occur before `main()` or any other function that uses it. The declaration may have two forms:

- The entire function definition.
- Just a function prototype – the function definition itself may then be placed anywhere in the program.

**Code example 1**

In this example, the function is declared *and* defined before it is used in `main()`.

```c
int n = 5, m = 10, res;
int minimum (int a, int b) {
    return ((a <= b) ? a : b);
}

int main (void) {
    res = minimum (n, m);
    printf("The minimum is %d\n", res);
}
```

**Code example 2**

In this example, the function is declared before it is used in `main()`, but only defined after it is used in `main()`.
 
```c
int n = 5, m = 10, res;
int minimum (int a, int b);

int main (void) {
    res = minimum (n, m);
    printf("The minimum is %d\n", res);
}

int minimum (int a, int b) {
    return ((a <= b) ? a : b);
}
```

## Function prototype formats

**Code example**

```c
// Function prototype 1:
int minimum (int x, int y);  // exact copy of the function header

// Function prototype 2:
int minimum (int, int);      // contains only the parameter data types
```
