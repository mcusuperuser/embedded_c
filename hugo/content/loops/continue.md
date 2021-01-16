---
title: "continue statement"
date: 2020-12-23T22:08:20+01:00
weight: 5
---

**Syntax**

```c
continue;
```

The `continue` statement causes a program to jump back to the beginning of a loop without completing the current iteration.

**Code example**

```c
int n = 0;

while (n < 5) {
    if (n == 3) continue;
    printf("Loop iteration %d\n", n++);
}
```

**Output**

```
Loop iteration 0
Loop iteration 1
Loop iteration 2
Loop iteration 4
```