---
title: "Pointer declaration"
weight: 1
---

![Pointer](../../img/pointer_intro.png)


As any other variable, you need to declare a pointer. Furthermore, you have to initialize a pointer before you can use it.

You declare a pointer just like any other variable:

**Syntax**

```c
type *name;
```

{{% notice note %}}
`type` can be any C type (such as `char`, `int`, or `float` for example).  
`name` is the name of the pointer variable.  
The `*` makes the variable a pointer.  
Pointers are usually described as "a pointer to `type`"
{{% /notice %}}

**Code example**

```c
int *myPointer        // declares a pointer named myPointer as an integer type

float *myOtherPointer // declares a pointer named myOtherPointer as a float type

myPointer = &myIntVar;        // assigns the memory address of myIntVar to myPointer

myOtherPointer = &myFloatVar; // assigns the memory address of myFloatVar to myOtherPointer
```

## Creating pointer types with typedef

**Syntax**

```c
typedef type *typeName;
```

*Note*

- A pointer variable can now be declared as type `typeName` which is a synonym for `type`.
- The * is no longer needed since `typeName` explicitly identifies the variable as a pointer to `type`.

**Code example**

```c
typedef int *intPointer; // Create a pointer to int type

intPointer p;            // Create pointer to int (without *)
                         // Equivalent to int *p;
```

## Initialization

To set a pointer to point to another variable, we use the `&` operator (address of), and the pointer variable is used
without the dereference operator `*`:

`p = &n;`

This assigns the address of the variable `n` to the pointer `p` (`p` now points to `n`).

*Note*

- `p` must be declared to point to the type of `n` (e.g. `int n; int *p;`).

## Usage

When accessing the variable pointed to by a pointer, we use the pointer with the dereference operator `*`:

`m = *p;`

This assigns to the variable m, the value of what p is pointing to (n from the last example). Using `*p`, is the same as using the variable it points to (e.g. n).

## In other words

**Code example**

```c
int n, *p; // Create an integer variable and a pointer to an integer variable

p = &n;    // Assign the address of n to p
*p = 3;    // Equals to n = 3;
```

In the pointer world:
- `&n` is a constant pointer which represents the address of `n`. This address of n will never change.
- `p` is a variable pointer to int which can be assigned the address of any int any time.
- `*p` represents the data pointed to by `p` and may be used anywhere you would use `n`.
- `*` is the dereference operator, also called the indirection operator.
- When declaring a pointer, `*` is used to indicate that the variable is a pointer rather than an ordinary variable.

## Pointers at work

Consider the following code example. How is this working in an actual design?

**Code example**

```c
int n, m;    // create two integer variables
int *p;      // create a pointer to an integer variable

 n = 0x1234; // assign 0x1234 to n
 m = 0xABCD; // assign 0xABCD to m
 p = &n;     // assign the address of n to p
*p = 0x4321; // assign 0x4321 to n using *p
 p = &m;     // assign the address of m to p
*p = 0xDCBA; // assign 0xDCBA to m using *p
```

Zero-initialized RAM at program start: 
![Initialization with ZI RAM](../../img/pointers_at_work1.png)

Assign 0x1234 to n:
![Assign 0x1234 to n](../../img/pointers_at_work2.png)

Assign 0xABCD to m:
![Assign 0xABCD to m](../../img/pointers_at_work3.png)

Assign the address of n to p:
![Assign the address of n to p](../../img/pointers_at_work4.png)

Assign 0x4321 to n using *p:
![Assign 0x4321 to n using *p](../../img/pointers_at_work5.png)

Assign the address of m to p:
![Assign the address of m to p](../../img/pointers_at_work6.png)

Assign 0xDCBA to m using *p:
![Assign 0xDCBA to m using *p](../../img/pointers_at_work7.png)
