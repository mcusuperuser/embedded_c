# Function pointers

You can use pointers to point to functions. This provides a more flexible way to call a function, as it gives a choice of which function to call and finally makes it possible to pass functions to other functions.

## Declaration

A function pointer is declared much like a function prototype:

**Syntax**
```c
int (*fp) (int a);
```

*Note*

- This is the declaration of a function pointer called `fp`.
- The function it points to must take one `int` parameter and must return an `int`.

## Initialization

Initialize a function pointer by setting the pointer name equal to the function name:

**Code example**
```c
int (*fp) (int a); // Function pointer
int   foo (int a); // Function prototype

// Initialization:
fp = foo;          // fp points to foo
```

## Calling a function via a function pointer

The following two calls to the function are equivalent: 

**Code example**
```c
m = fp(a);  // call via function pointer
m = foo(a); // direct call to foo
```

## Passing a function to a function

The following example shows the basic concept:

**Code example**
```c
int a, b;
int add(int n, int m); // Function prototype
int sub(int n, int m); // Function prototype

//Function definition with function pointer parameter
int foobar(int n, int n, int (*fp)(int, int)) {
    return fp(n, m);   // Call function passed by pointer
}

void main(void) {
    a = foobar (2, 72, &add); // Pass address of add
    b = foobar (31, 2, &sub); // Pass address of sub
}
```