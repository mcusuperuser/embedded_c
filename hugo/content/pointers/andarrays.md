---
title: "Pointers and arrays"
weight: 2
---

In general, array elements occupy consecutive locations in memory. Using this knowledge, we can use pointers to access array elements.

![Integer array memory locations](../../img/array_in_memory.png)

## Initializing a pointer to an array

**Code example**

```c
int a[5] = {0, 1, 2, 3, 4}; // integer array
int *p;                     // Create a pointer to an integer variable
```

To initialize the pointer to the array, you can use three different (equal) methods:

**Code example**

```c
p = a;     // works only for arrays, as the array name (here: a) is the same as the address of its first element; Arm compiler will not complain
p = &a;    // works for arrays and variabls alike, but in case of an array, the Arm compiler will issue a warning
p = &a[0]; // safe way to point to the first element; compiler will not complain 
```

To move to the next element of the array, simply increment the pointer:

**Code example**

```c
p++;     // moves the pointer to the next element of the array
p--;      // moves the pointer to the previous element of the array
```

{{% notice note %}}
Adding or subtracting a number to/from the pointer will change it by a multiple of the number of bytes of its type.
{{% /notice %}}

**Code example**

![Pointer arithmetic](../../img/pointer_arithmetic1.png)

![Pointer arithmetic](../../img/pointer_arithmetic2.png)

![Pointer arithmetic](../../img/pointer_arithmetic3.png)

![Pointer arithmetic](../../img/pointer_arithmetic4.png)

![Pointer arithmetic](../../img/pointer_arithmetic5.png)

![Pointer arithmetic](../../img/pointer_arithmetic6.png)

![Pointer arithmetic](../../img/pointer_arithmetic7.png)

![Pointer arithmetic](../../img/pointer_arithmetic8.png)



## Increment/decrement syntax rules

Use parentheses to determine what gets incremented or decremented.

**Modify the pointer itself**

```c
// Pre-increment:
*(++p);
*++p;
++p;
// usage example:
n = *(++p);
// is equivalent to:
p = p + 1;
n = *p;

// Post-increment:
*(p++);
*p++;
p++;
// usage example:
n = *p++;
// is equivalent to:
n = *p;
p = p + 1;
```

**Modify the value pointed to by the pointer**

```c
// Pre-increment:
++(*p);
// usage example:
n = ++(*p);
// is equivalent to:
*p = *p + 1;
n = *p;

// Post-increment:
(*p)++;
// usage example:
n = (*p)++;
// is equivalent to:
n = *p;
*p = *p + 1;
```

**Post-increment code example**

![Post-increment](../../img/postincrement1.png)

![Post-increment](../../img/postincrement2.png)

![Post-increment](../../img/postincrement3.png)

![Post-increment](../../img/postincrement4.png)

{{% notice note %}}
Remember that `*(p++)` is the same as `*p++`!
{{% /notice %}}

**Pre-increment code example**

![Pre-increment](../../img/preincrement1.png)

![Pre-increment](../../img/preincrement2.png)

![Pre-increment](../../img/preincrement3.png)

{{% notice note %}}
Remember that `*(++p)` is the same as `*++p`!
{{% /notice %}}
