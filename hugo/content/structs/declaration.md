---
title: "Variable declaration"
weight: 2
---

There are two ways to declare a structure variable:

1. At structure definition:

**Syntax**

```c
struct structName {
    type1 memberName1;  // Members are declared just
    ...                 // like odinary variables
    typen memberNamen;
} variableName1, ..., variableNamen;
```

**Code example**

```c
// structure to handle color values
struct rgb {
    int red;
    int green;
    int blue;
} color; // declare color of type rgb
```

2. If the structure has already been defined:

**Syntax**

```c
struct structName variableName1, ..., variableNamen;
```

**Code example**

```c
// structure to handle color values
struct rgb {
    int red;
    int green;
    int blue;
}
...
struct rgb color; // declare color of type rgb
```