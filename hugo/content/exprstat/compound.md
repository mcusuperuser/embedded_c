---
title: "Compound or block statements"
date: 2020-12-23T21:52:24+01:00
weight: 2
---

A **compound statement** is a group of statements enclosed within a pair of curly braces (`{ }`) and is often also called a **block statement**. The statements within the block may be of any statement type (including (again) compound statements). This allows statements to be embedded or nested within other statements. A compound statement **does not** end with a semicolon after the closing `}`.

**Code example**

```c
{
  a = 0;
  a++;
  b = 3 + c;
  y = (a * x) + b;
  printf("Speed = %f", x);
}
```
