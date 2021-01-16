---
title: "do while loop"
date: 2020-12-23T22:08:07+01:00
weight: 3
---

A `do .. while` loop checks the loop condition at the bottom; you must create the iterator if needed.

**Syntax**

```c
do statement while (expression);
```

The statement is executed and then the expression is evaluated to determine
whether or not to execute the statement again. The statement will always execute at least once, even if the expression is false when the loop starts.

**Code example**

```c
int n = 0;

do { printf("Loop iteration %d\n", n); }
while (n < 5);
```

**Output**

```
Loop iteration 0
Loop iteration 1
Loop iteration 2
Loop iteration 3
Loop iteration 4
```
