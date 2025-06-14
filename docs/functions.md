# Functions

What are functions?

!!! Important
    Functions are self contained program segments designed to perform a specific task. They take inputs, do some
    computation, and produce output.

Functions provide a way to modularize code and make it easier to maintain. Also, functions promote code reuse.

!!!! Note
    - All C programs have one (at least the `main()` function is required) or more functions.
    - Functions can accept parameters from the code that calls them.
    - Functions usually return a single value.
    - Functions help to organize a program into logical, manageable segments.

**Syntax**

```c
type identifier (type1 arg1, type2 arg2, ..., typen argn) {
    declarations        // body
    statements          // body
    return expression;  // body
}
```

Where:

- `type` is the data type of the return expression.
- `identifier` is the name of the function.
- `type1 arg1, type2 arg2, ..., typen argn` is the parameter list which is optional.
- `expression` is the (optional) return value.
- the body is also optional. 

## Return data type

- A function's `type` must match the type of data in the return `expression`
- A function may have multiple return statements (of the same type), but only one will be executed
- The function type is `void` if the `return` statement has no `expression` or is not present at all. This is also
known as a procedure function, since nothing is returned.
- Functions can return any type except arrays and functions. We can get around this limitation by returning a pointer
to an array or a pointer to a function.

## Parameters

- A function's parameters are declared just like ordinary variables, but in a comma separated list inside the
parentheses.
- The parameter names are only valid inside the function (local to the function).
- The list may mix different data types.
- Parameters of the same type must be declared separately (as separation using commas will not work here).
- If no parameters are required, use the keyword `void` in place of the parameter list when defining the function.

## How to call a function

**Code example**

```c
foo ();         // no parameters, no return value
x = foo ();     // no parameters, but with a return value
foo (n, m);     // with parameters, but no return value
x = foo (n, m); // with parameters and with a return value
```

## Function prototypes

Just like a variable, a function must be declared before it may be used. This declaration must occur before `main()`
or any other function that uses it. The declaration may have two forms:

- The entire function definition.
- Just a function prototype – the function definition itself may then be placed anywhere in the program.

**Code example 1**

In this example, the function is declared *and* defined before it is used in `main()`.

```c
int n = 5, m = 10, res;
int minimum (int a, int b) {
    return ((a <= b) ? a : b);
}

int main (void) {
    res = minimum (n, m);
    printf("The minimum is %d\n", res);
}
```

**Code example 2**

In this example, the function is declared before it is used in `main()`, but only defined after it is used in `main()`.

```c
int n = 5, m = 10, res;
int minimum (int a, int b);

int main (void) {
    res = minimum (n, m);
    printf("The minimum is %d\n", res);
}

int minimum (int a, int b) {
    return ((a <= b) ? a : b);
}
```

### Function prototype formats

**Code example**

```c
// Function prototype 1:
int minimum (int x, int y);  // exact copy of the function header

// Function prototype 2:
int minimum (int, int);      // contains only the parameter data types
```

## Passing parameters by value

Parameters are passed to a function *by value*. These values are copied into the local parameter variables. This means, that the original variable that is passed to a function cannot be modified by the function, since only a copy of its value was passed.

**Code example**

```c
int n = 5, m = 10, res;
int minimum (int a, int b);

int main (void) {
    res = minimum (n, m);  // the value of n is copied into a
                           // the value of m is copied into b
    printf("The minimum is %d\n", res);
}

int minimum (int a, int b) {
    return ((a <= b) ? a : b);
}
```

## Functions and scope

### Scope of parameters

A function's parameters are local to the function and have no meaning outside
the function itself. Parameter names may have the same identifier as a variable declared outside the function, but the parameter names will take precedence inside the function.

**Code example**

```c
// The following n's are not the same: 
int n;
int absolute (int n);
```

### Scope of variables inside a function

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

!!! Note
    - Variables that are declared within a function block are not accessible outside the function.
    - Any access to a local variable outside the function will generate an error.

### Global versus local variables

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

### Overloading variable names

A locally declared identifier takes precedence over a globally defined one. This enables the usage of the same
parameter name in different functions. Each function will only use its own parameter.

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

### `#define` within a function

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

```txt
7
7
```

!!! Note
    Remember that a `#define` is used by the preprocessor to do text substitution before the code is compiled.
    Situations like the above will lead to unexpected behavior. You can not rely on the order in which the `#define`'s
    are processed.
