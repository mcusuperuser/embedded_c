---
title: "Calling a function via a function pointer"
weight: 2
---

The following two calls to the function are equivalent: 

**Code example**

```c
m = fp(a);  // call via function pointer
m = foo(a); // direct call to foo
```