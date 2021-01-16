---
title: "break statement"
date: 2020-12-23T22:08:14+01:00
weight: 4
---

**Syntax**
```c
break;
```

The `break` statement causes immediate termination of a loop, even if the exit condition has not been met. Also, it exits from a `switch` statement so that execution doesn't fall through to next `case` clause.

**Code example**

```c
int n = 0;

while (n < 10) {
    if (n == 5) break;
    printf("Loop iteration %d\n", n++);
}
```

**Output**

```
Loop iteration 0
Loop iteration 1
Loop iteration 2
Loop iteration 3
Loop iteration 4
```
