---
title: "Structure types"
weight: 4
---

Structure types can be created using a `typedef`.

**Syntax**

```c
typedef struct structTag {
    type1 memberName1;
    ...
    typen memberNamen;
} typeName;
```

*Note*

- The `structTag` is optional

**Code example**

```c
// structure type to handle color values
typedef struct {
    int red;
    int green;
    int blue;
} rgb;
```

## Declare a structure type variable

If the `typeName` has already been defined, you can declare a variable of that type without the `struct` keyword:

**Syntax**

```c
typeName variableName1, ..., variableNamen;
```

**Code example**

```c
// structure type to handle color values
typedef struct {
    int red;
    int green;
    int blue;
} rgb;
...
rgb color;
```