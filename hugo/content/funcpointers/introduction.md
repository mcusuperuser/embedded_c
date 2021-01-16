---
title: "Introduction"
weight: 1
---

A function pointer is declared much like a function prototype:

**Syntax**

```c
int (*fp) (int a);
```

{{% notice note %}}
This is the declaration of a function pointer called `fp`.  
The function it points to must take one `int` parameter and must return an `int`.
{{% /notice %}}

## Initialization

Initialize a function pointer by setting the pointer name equal to the function name:

**Code example**

```c
int (*fp) (int a); // Function pointer
int   foo (int a); // Function prototype

// Initialization:
fp = foo;          // fp points to foo
```
