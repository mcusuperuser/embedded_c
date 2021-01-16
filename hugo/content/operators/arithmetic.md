---
title: "Arithmetic operators"
weight: 1
---

Arithmetic operators are used to perform arithmetic/mathematical operations on operands. Arithmetic operators are of two distinct types:

- Binary Operators work on two operands: +, -, *, /, %
- Unary Operators work on a single operand: +, -, ++, --

| Operator | Operation | Example | Result |
|:----------:|-----------|:---------:|--------|
| * | Multiplication | `a * b` | Product of `a` and `b` |
| / | Division | `a / b` | Quotient of `a` and `b` |
| % | Modulo | `a % b` | Remainder of `a` divided by `b` |
| + | Addition | `a + b` | Sum of `a` and `b` |
| - | Subtraction | `a - b` | Difference of `a` and `b` |
| - | (unary) Negative | `-a` | Negative value of `a`|
| + | (unary) Positive | `+a` | Value of `a` |

## Division operator

If both operands are of an integer type, the result will be an integer type as well (valid for `int` and `char`).

If one or both of the operands is a floating point type, the result will be a floating point type (`float`, `double`).

## Implicit type conversion

When an expression is used in the context where a value of a different type is expected, conversion may occur. In such cases, the type of one operand will be temporarily "promoted" to the larger type of the other operand. This means that during an operation, the smaller data type will be promoted to the largest one in the expression.

**Code examples**

```c
short n = -5;
-n      // promotion to int; result is 5
n * -3L // promotion to long, because -3L is a long; result is 15
7 / n   // promotion to int; result is -1
9 % n   // promotion to int; result is 4
8.0 / n // promotion to double, because 8.0 is a double; result is -1.6
```

## Increment and decrement

Increment/decrement operators are unary operators that increment/decrement the value of a given variable by 1.

| Operator | Operation | Example | Result |
|:----------:|-----------|:---------:|--------|
| ++ | Increment | `a++` | Postfix form: use `a` and then add `1` |
|  |  | `++a` | Prefix form: add `1` to `a` and then use `a` |
| -- | Decrement | `a--` | Postfix form: use `a` and then subtract `1` |
|  |  | `--a` | Prefix form: subtract `1` from `a` and then use `a` |

**Code example**

```c
int n, m;
n = 3;

// Postfix example
m = (n++) + 8;  // Result: n = 4, m = 11

// Prefix example
m = (++n) + 8;  // Result: n = 4, m = 12
```