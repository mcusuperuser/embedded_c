---
title: "Introduction"
weight: 1
---

A `union` allows the same memory location to be used for different data types. The amount of memory that is allocated for the union is determined by its largest member. This saves space, especially for large structures where the programmer can be sure that the same members never occur at the same time.

Unions:
- may contain any number of members which may be of any data type.
- are as large as their largest member.
- use exactly the same syntax as structures except `struct` is replaced with `union`.

**Syntax**
```c
union unionName {
    type1 memberName1;
    ...
    typen memberNamen;
}
```

**Code example**
```c
union mixedPickles {
    char c;
    int i;
    float f;
}
```
