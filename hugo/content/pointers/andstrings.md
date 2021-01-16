---
title: "Pointers and strings"
weight: 4
---

Until now, we have used arrays of `char` to work with strings. Using pointers, strings can be created and used in a more efficient way.

**Syntax**

```c
char *name = "string_content";
```

*Note*

- Initializing a character string when it is declared is essentially the same for both a pointer and an array
- The NULL character `\0` is automatically appended to
strings in both cases

**Code example**

```c
char *str = "Cortex";
```

![Pointer to string](img/pointer_to_string.png)

At initialization, a pointer to a string points to the first character. To access subsequent characters, add an offset to the pointer.

![Pointer to string](img/pointer_to_string_plus4.png)

## Pointers versus arrays

An entire string may be assigned to a pointer in a single step, while a character array must be assigned character
by character. Also, you must explicitly add the NULL character `\0` to an array.

**Code example**

```c
// Pointer variable
char *str;
str = "Cortex";

// Array variable
char str[7];
str[0] = 'C';
str[1] = 'o';
str[2] = 'r';
str[3] = 't';
str[4] = 'e';
str[5] = 'x';
str[6] = '\0';
```