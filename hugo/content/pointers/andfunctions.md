---
title: "Pointers and functions"
weight: 3
---

In general, functions operate on copies of the data that is passed to them. This is called pass by value. The value of the variable that is passed to a function is copied into the local variable of the function. The original variable *is not* changed.

## Passing pointers to functions

Using a pointer, a function can operate on the original value instead of a copy. This is called pass by reference.

**Code example**

```c
int n = 3;

void square (int *a) { 
    *a *= *a;
}

int main (void) {
    square(&n);
}
```

{{% notice note %}}
In the example above, the address of the variable is passed to the function and stored in the local pointer variable a. After the function call, n = 9. It was changed by the function.
{{% /notice %}}

Functions with pointer parameters:

```c
int foo (*n)
```

must be called in one of the following two ways.

1. `foo(&a)` which passes an address to the function so that the address may be assigned to the pointer parameter: `n = &a`.
2. `foo(p)` which passes a pointer to the function so that the pointer may be assigned to the pointer parameter `n = p`.

As addresses of parameters are copied to local pointer variables, functions can now modify the original variables via pointers, as shown in the next example.

**Code example**

```c
void swap_values (int *v1, int *v2) {
	int temp;
	temp = *v1;
	*v1  = *v2;
	*v2  = temp;
}

// main() function
int main(void) {
	int  n = 5, m = 10;
	int *p = &m;
	swap_values (&n, p);
  // Endless loop
	while(1);
}
```

Pointers enable the programmer to pass a variable by reference to a function. This allows the function to modify the original variable and not just a copy of its contents.
