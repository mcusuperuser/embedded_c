---
title: "Arrays of pointers"
weight: 5
---

An array of pointers is an array variable whose elements are all be pointers.

**Code example**

```c
char *str[3]; // creates an array of three pointers to char

str[0] = "IN";
str[1] = "OUT";
str[2] = "TRISTATE";
```

The array `str[]` itself is like any other array. Each element, such as str[1], is a pointers to `char`.

![Array of pointers](img/array_of_pointers.png)

{{% notice note %}}
Strings will not “pack” this nicely! There will be empty locations between strings as the compiler aligns the strings in memory.
{{% /notice %}}

## Initialization

A pointer array element may be initialized just like its ordinary variable counterpart.

**Code example**

```c
str[0] = &n;
```

When using strings:

**Code example**

```c
str[0] = "String";
```

## Dereferencing

To use the value pointed to by a pointer array element, just dereference it like you would an ordinary variable

**Code example**

```c
m = *str[0];
```

Using *str[0] is the same as using the object it points to, such as `n` or the string literal `"String"`.

Arrays are frequently treated like pointers. An array name alone represents the address of its first element.
