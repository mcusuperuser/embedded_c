---
title: "Functions and scope"
date: 2020-12-23T22:17:51+01:00
weight: 7
---

## Scope of parameters

A function's parameters are local to the function and have no meaning outside the function itself. Parameter names may have the same identifier as a variable declared outside the function, but the parameter names will take precedence inside the function.

**Code example**

```c
// The following n's are not the same: 
int n;
int absolute (int n);
```

## Scope of variables inside a function

Variables that are declared inside a function are local to the function itself. 

**Code example**

```c
void my_func (int n) {
    int m;
    ..
    m -= n;  // n refers to the function paramter
             // while me refers to the locally declared variable
}
```

{{% notice note %}}
Variables that are declared within a function block are not accessible outside the function.  
Any access to a local variable outside the function will generate an error.
{{% /notice %}}

## Global versus local variables

Global variables can be seen by everybody, while local variables can only be seen locally.

**Code example**

```c
int n = 5;              // can be seen by everybody

int foo (int m);        // foo's local paramter is m

int foo (int m) {       // foo cannot see main's local variable i
    int p = 3;          // foo's local variable is p
    return (n - m * p); // foo can see gloabal variable n
}

int main (void) {       // main cannot see foo's paramter m nor local variable p
    int i = 2;          // main's local variable is i
    n = foo (i);        // main can see global variable n
    i = foo (n);
}
```

## Overloading variable names

A locally declared identifier takes precedence over a globally defined one. This enables the usage of the same parameter name in different functions. Each function will only use its own parameter. 

**Code example**

```c
int n = 5;              // global variable n

int foo (int n) {       // foo's function parameter
    int p = 3;          // foo's local variable is p
    return (n(1 - p));  // foo can not see glonbal variable n
                        // function parameter n is used instead
}

void bar (int n) {      // bar's function parameter
    // do some computation here
}
```

## `#define` within a function

Use `#define`'s within a function with care. Defining already defined identifiers again can lead to unexpected behavior. 

**Code example**

```c
#define a 5

void func_define (void) {
    #define a 7
    printf ("%d\n", a);
}

void main (void) {
    printf ("%d\n", a);
    func_define();
}
```

Running the code above will lead to the following output:
```
7
7
```

{{% notice warning %}}
Remember that a `#define` is used by the preprocessor to do text substitution before the code is compiled. Situations like the above will lead to unexpected behavior. You can not rely on the order in which the `#define`'s are processed.
{{% /notice %}}
