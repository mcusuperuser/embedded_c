---
title: "Constants"
date: 2020-12-23T21:13:17+01:00
weight: 1
---

Constants, as the name implies, never change their value which makes development changes easy and eliminates the use of "magic numbers".

**Syntax**

There are two ways to declare a constant:

```c
#define identifierName value

const type identifierName value;
```

- The `identifierName` is the constant, while the `value` is the literal.
- The first way is very efficient for an embedded system, as it does not consume any memory in the microcontroller. Using the `#define`, you declare a text substitution label, which means that each instance of `identifierName` will be replaced with value by the preprocessor unless `identifierName` is inside a string.
- A `#define` is *never* terminated with a `';'`, unless you want that semicolon to be part of the substitution.
- The second way allocates a variable in program memory, but it cannot be changed due to the `const` keyword. While this is inefficient for normal constants, it is a good way to save lookup tables in Flash memory for example.