# Structures

What are structures?

!!! Important
    Arrays are named collections of identical objects. Structures are named collections of different objects. Variables
    within a structure are referred to as *members*, and may be accessed individually as needed.

Structures:

- may contain any number of members. These members may be of any data type.
- allow a group of related variables to be treated as a single unit, even if different types are contained.
- organize complicated data more easily.

## Structure definition

**Syntax**

```c
struct structName {
    type1 memberName1;  // Members are declared just
    ...                 // like odinary variables
    typen memberNamen;
}
```

## Variable declaration

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

## Using structure variables

**Syntax**

```c
structVariableName.memberName;
```

**Code example**

```c
// structure to handle color values
struct rgb {
    int red;
    int green;
    int blue;
} color;

int main (void){
    color.red   = 0;   // set   red portion of color
    color.green = 145; // set green portion of color
    blue        = 189; // set  blue portion of color
}
```

## Structure types

Structure types can be created using a `typedef`.

**Syntax**

```c
typedef struct structTag {
    type1 memberName1;
    ...
    typen memberNamen;
} typeName;
```

!!! Note
    The `structTag` is optional

**Code example**

```c
// structure type to handle color values
typedef struct {
    int red;
    int green;
    int blue;
} rgb;
```

### Declare a structure type variable

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

## Initialization of structure variables

If `typeName` or `structName` have already been defined:

**Syntax**

```c
typeName variableName = {const1, ..., constn};
// or
struct structName variableName = {const1, ...,constn};
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
rgb color = {0, 145, 189};
```

## Nested structures

Using the `typedef` structure declaration, you can nest one structure within another structure.

**Code example**

```c
// declare struct type for a single point
typedef struct {
    float x;
    float y;
} point;

// declare a struct type for a line with a start and end point
typedef struct {
    point start;
    point end;
} line;

int main(void) {
    line l;

    l.start.x = 3.5;
    l.start.y = 8.4;
    l.end.x = 12.7;
    l.end.y = 18.5;
    ...
}
```

## Pointers to structures

There are two ways to declare a pointer to a structure. If the `typeName` or the `structName` have already been
defined:

**Syntax**

```c
typeName *pointerName;
// or
struct structName *pointerName;
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
rgb *pColor;
```

**Code example**

```c
// structure type to handle color values
struct rgb {
    int red;
    int green;
    int blue;
}
...
struct rgb *pColor;
```

### Accessing structure members using a pointer

If a `pointerName` has already been defined:

**Syntax**

```c
pointerName -> memberName;
```

!!! Note
    First, the pointer must be initialized to point to the address of the structure itself:
    `pointerName = &structVariable;`

**Code example**

```c
// structure type to handle color values
typedef struct {
    int red;
    int green;
    int blue;
} rgb;
...
rgb color;   // rgb variable
rgb *pColor; // pointer to color

int  main (void) {
    pColor        = color;
    pColor->red   = 0;     // Set   red using pColor
    pColor->green = 145;   // Set green using pColor
    pColor->blue  = 189;   // Set  blue using pColor
}
```

!!! Note
    We will later see in an example how CMSIS uses this to access core peripherals of a Cortex-M based device.

## Creating arrays of structures

There are two ways to create arrays of structures. If the `typeName` or the `structName` have already been defined:

**Syntax**

```c
typeName arrayName[n];
// or
struct structName arrayName[n];
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
rgb aColor[2];
```

## Initializing arrays of structures at declaration

If the `typeName` or the `structName` have already been defined:

**Syntax**

```c
typeName arrayName[n] = {{list1}, ..., {listn}};
// or
struct structName arrayName[n] = {{list1}, ..., {listn}};
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
rgb aColor[2] = {{0, 0, 0}, {255, 255, 255}};
```

### Using arrays of structures

If the `arrayName` has already been defined:

**Syntax**

```c
arrayName[n].memberName
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
rgb aColor[2] = {{0, 0, 0}, {255, 255, 255}};

int main (void) {
    aColor[0].red   = 0;
    aColor[0].green = 145;
    aColor[0].blue  = 189;
    ...
}
```

### Passing structures to functions

**Code example**

```c
// structure type to handle color values
typedef struct {
    int red;
    int green;
    int blue;
} rgb;

void show_rgb (rgb n) {
    printf("(%d, %d, %d)\n", n.reg, n.green, n.blue);
}

int main (void) {
    rgb a = {0, 145, 198};
    rgb b = {0, 255, 255};

    show_rgb (a);
    show_rgb (b);
}
```
