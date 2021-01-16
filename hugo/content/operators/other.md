---
title: "Other operators"
weight: 8
---

| Operator | Operation            | Example     | Result |
|:--------:|:---------------------|:-----------:|--------|
| `(...)`  | Function call        | `f(...)`    | Calls the function f(), with specified arguments
| `,`      | Comma operator       | `a, b`      | Evaluates `a` then `b`, else result is value of `b`
| `(type)` | Type cast            | `(type)a`   | Casts the type of `a` to type
| `? :`    | Conditional operator | `a ? b : c` | The value of `b` if `a` is true, else value of `c`
| `sizeof` | Sizeof operator      | `sizeof a`  | The size in bytes of `a`

## The conditional operator

**Syntax**

```c
(test_expression) ? do_if_true : do_if_false;
```

**Code example**

```c
int a = 3, b = 4, c;

(a % 2 != 0) ?
  printf("%d is odd\n", a) :
  printf("%d is even\n", a);

c = (a % 2 != 0) ? a : b; // conditionally assigns a value to c
```

## Explicit type cast operator

You can use the cast operator `(type)` to cast a variable:

**Code example**

```c
int a = 10;
float b;
b = (float)a / 4; // b is 2.5, because float/int = float
```