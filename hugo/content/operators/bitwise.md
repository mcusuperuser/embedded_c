---
title: "Bitwise operators"
weight: 5
---

Bitwise operators apply the operation to each bit of the first operand with each corresponding bit of the second operand.

| Operator | Operation           | Example  | Result |
|:--------:|:--------------------|:--------:|--------|
| `~`      | Bitwise NOT         | `~a`     | `1`, if `0` in `a`; `0`, if `1` in `a`
| `&`      | Bitwise AND         | `a & b`  | `1`, if `1` in both `a` and `b`; `0`, if `0` in `a` or `b` or both
| `|`      | Bitwise OR          | `a | b`  | `1`, if `1` in `a` or `b` or both; `0`, if `0` in both `a` and `b`
| `^`      | Bitwise XOR         | `a ^ b`  | `1`, if `1` in `a` or `b` but not both; `0`, if `0` or `1` in both `a` and `b`

{{% notice note %}}
The bitwise NOT is also known as "[One's complement](https://en.wikipedia.org/wiki/Ones%27_complement)".  
Do not interchange `&` with `&&`. `&` is the *bitwise* AND operator, while `&&` is the *logical* AND operator.
{{% /notice %}}

**Code example**

```c
int n, m;

if (n && m) { // check if both values are true (non-zero)
    // do something here
}
```