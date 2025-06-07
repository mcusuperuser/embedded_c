# Arrays

What is an array?

!!! Important
    Arrays are variables that can store many items of the same type stored at continuous memory locations. The items
    are known as elements and are  identified by the array index.

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

## Multidimensional arrays

Arrays may have any number of dimensions that are added in the declaration:

**Syntax**

```c
type arrayIdentifier[size0]...[sizen];
```

**Code example**

```c
int n[3][3];         // 3 x 3 array for 9 integers 

float c[10][10][10]; // 10 x 10 x 10 array for 1000 floats
```

Multidimensional arrays are initialized with lists within a list: 

**Syntax**

```c
type arrayIdentifier[size0]...[sizen] = 
                     {{item, ..., item},
                     ...
                     {item, ..., item}};
```

**Code example**

```c
char c[3][3] = {{'o','x','o'},
                {'x','x','x'},
                {'o','x','o'}}; 

int n[2][3][4] = {{{0, 1, 2, 3},{4, 5, 6, 7},{8, 9, 10, 11}},
                 {{12, 13, 14, 15},{16, 17, 18, 19},{20,21, 22, 23}}};
```

### Visualizing 2-dimensional arrays

![2-dimensional arrays](img/2-dim-arrow_862x276.png)

### Visualizing 3-dimensional arrays

!!! Error
    This is still to do.

## Strings

What are strings?

!!! Important
    Strings are arrays of `char` whose last element is a null
    character `\0` with an ASCII value of 0. As C has no native
    string data type, strings must always be treated as
    character arrays.

Strings:

- are enclosed in double quotes: "string".
- are terminated by a null character `\0`.
- must be manipulated as arrays of characters (treated element by element).
- may be initialized with a string literal.

### Creating a string character array

**Syntax**

```c
char arrayName[length];
```

!!! Note
    - `length` must be one larger than the length of the string
      to accommodate the terminating null character `\0`.
    - A `char` array with n elements holds strings with n-1
      `char`.

**Code example**

```c
char string1[9];  // holds eight characters plus \0

char string2[255] // holds 254 characters plus \0
```

### Initialization at string declaration

**Syntax**

```c
char arrayName[] = "Programmer";
```

!!! Note
    - The array size is not required.
    - The size automatically determined by the length of the string.
    - A NULL character `\0` is automatically appended to the array.

**Code example**

```c
char string1[] = "Programmer"; // 11 characters "Programmer\0"

char stingr2[6] = "World";     //6 characters "World\0"

// Alternative string declaration that requires the size to be declared:
char string3[4] = {'A', 'r', 'm', '\0'};
```

### String initialization in code

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

## Summary

Arrays may be used to store a group of related variables of the same type under a common name. Individual elements are
accessed by using the array index in conjunction with the array name.
