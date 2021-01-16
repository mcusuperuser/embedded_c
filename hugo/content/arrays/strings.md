---
title: "Strings"
date: 2020-12-23T22:38:19+01:00
weight: 3
---

Strings are arrays of `char` whose last element is a null character `\0` with an ASCII value of 0. As C has no native string data type, strings must always be treated as character arrays.

Strings:

- are enclosed in double quotes: "string"
- are terminated by a null character `\0`
- must be manipulated as arrays of characters (treated element by element)
- may be initialized with a string literal

## Creating a string character array

**Syntax**

```c
char arrayName[length];
```

{{% notice note %}}
`length` must be one larger than the length of the string to accommodate the terminating null character `\0`.  
A `char` array with n elements holds strings with n-1 `char`.
{{% /notice %}}

**Code example**

```c
char string1[9];  // holds eight characters plus \0

char string2[255] // holds 254 characters plus \0
```

## Initialization at string declaration

**Syntax**

```c
char arrayName[] = "Programmer";
```

{{% notice note %}}
The array size is not required.  
The size automatically determined by the length of the string.  
A NULL character `\0` is automatically appended to the array.
{{% /notice %}}

**Code example**

```c
char string1[] = "Programmer"; // 11 characters "Programmer\0"

char stingr2[6] = "World";     //6 characters "World\0"

// Alternative string declaration that requires the size to be declared:
char string3[4] = {'A', 'r', 'm', '\0'};
```

## String initialization in code

In program code, strings need to be initialized element-by-element. The NULL character needs to be appended manually:

**Syntax**

```c
char arrayName[0] = char1;
char arrayName[1] = char2;
char arrayName[2] = char3;
...
char arrayName[n] = '\0';
```

**Code example**

```c
arrayName[0] = 'A';
arrayName[1] = 'r';
arrayName[2] = 'm';
arrayName[3] = '\0';
```
