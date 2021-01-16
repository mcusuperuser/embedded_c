---
title: "Introduction"
date: 2020-12-23T22:38:04+01:00
weight: 1
---

Arrays may contain any number of elements which must be of the same type. The array index is zero based and the size of the array (number of elements) must be
specified at the array declaration.

**Syntax**

```c
type arrayIdentifier[size];
```

The `size` refers to the number of elements and must be a constant integer.

**Code example**

```c
int n[100]; // an array that holds 100 integer values

char c[26]; // an array that holds 26 characters
```

Arrays may be initialized when declared using a list: 

**Syntax**

```c
type arrayIdentifier[size] = {item1, ..., itemsize-1};
```

All items must match the `type` of the array.

**Code example**

```c
int n[3] = {1, 2, 3};

char c[3] = {'A', 'B', 'C'};
```

Arrays are accessed just like variables, but with an additional index value:

**Syntax**

```c
arrayIdentifier[index];
```

- The `index` value may be a variable or constant.
- The first element of an array has an index of `0`.
- C does not provide any bounds checking, so make sure that you do not try to access values that are not available.

**Code example**

```c
int i;
int n[10];    // an array that can hold 10 integers

for (i = 0; i < 10; i++) {
    n[i] = 0; // initialize all array elements to 0
}
n[2] = 23;    // set third element to 23
```

{{% notice info %}}
Arrays may be used to store a group of related variables of the same type under a common name. Individual elements are accessed by using the array index in conjunction
with the array name.
{{% /notice %}}
