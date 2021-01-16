---
title: "Relational operators"
weight: 3
---

Relational operators are binary operators that test a condition and return `1` if that condition is logically `true` and `0` if that condition is `false`. 

| Operator | Operation                | Example  | Result (FALSE = 0, TRUE = 1) |
|:--------:|:-------------------------|:--------:|------------------------------|
| `==`     | Equal to                 | `a == b` | `1` if `a` equal to `b`, else `0` |
| `!=`     | Not equal to             | `a != b` | `1` if `a` not equal to `b`, else `0` |
| `>`      | Greater than             | `a > b`  | `1` if `a` greater than `b`, else `0` |
| `>=`     | Greater than or equal to | `a >= b` | `1` if `a` greater than or equal to `b`, else `0` |
| `<`      | Less than                | `a < b`  | `1` if `a` less than `b`, else `0` |
| `<=`     | Less than or equal to    | `a <= b` | `1` if `a` less than or equal to `b`, else `0` |

*Note*

- Do not interchange `=` with `==`. `=` is the assignment operator, while `==` is the "equals to" relational operator.

**Code example**

```c
int n, m;

n = 3;         // assign the value 3 to a

if (m == 45) { // check if m equals to 45
    // do something here
}
```