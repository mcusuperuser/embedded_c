---
title: "Assignment operators"
weight: 2
---

Assignment operators are binary operators that modify the variable to their left using the value to their right, or in other words, they assign a value to a variable.

There are two types of assignment operators available:

## Simple assignments

**Syntax**

`variable = expression`

The expression is evaluated and the result is assigned to the variable.

## Compound assignments

**Syntax**

`variable = variable operator expression`

The variable is modified using the operator and the expression and the result is assigned to the variable.

| Operator  | Example   | Equivalent |
|:---------:|:---------:|--------|
|`=`        | `a = b`   | Assign the value of `b` to `a`
|`+=`       | `a += b`  | `a = a + b`
|`-=`       | `a -= b`  | `a = a - b`
|`*=`       | `a *= b`  | `a = a * b`
|`/=`       | `a /= b`  | `a = a / b`
|`%=`       | `a %= b`  | `a = a % b`
|`&=`       | `a &= b`  | `a = a & b`
|`\|=`      | `a \|= b` | `a = a \| b`
|`^=`       | `a ^= b`  | `a = a ^ b`
|`<<=`      | `a <<= b` | `a = a << b`
|`>>=`      | `a >>= b` | `a = a >> b`