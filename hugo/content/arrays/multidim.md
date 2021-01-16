---
title: "Multidimensional arrays"
date: 2020-12-23T22:38:14+01:00
weight: 2
---

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

## Visualizing 2-dimensional arrays

![2-dimensional arrays](../../img/2-dim-arrow_862x276.png)

## Visualizing 3-dimensional arrays