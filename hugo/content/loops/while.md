---
title: "While loop"
date: 2020-12-23T22:08:01+01:00
weight: 2
---

A `while` loop checks the loop condition at the top; you must create the iterator if needed.

**Syntax**

```c
while (expression)
    statement
```

If the expression is true, the statement will be executed. Afterwards, the expression will be reevaluated to determine whether or not to execute the statement again. It is possible that the statement will never be 
executed if the expression is false when it is evaluated for the first time.

{{% notice note %}}
The expression must always be there, unlike with a `for` loop.  
`while` is used more often than `for` when implementing an infinite loop, though it is only a matter of personal taste (mainly less coding effort).  
Frequently used for the main loop of a program.
{{% /notice %}}

**Code example**

```c
int n = 0;

while (n < 5) {
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

### Infinite while loops

A `while` loop with the expression = 1 will execute indefinitely. You can only leave the loop using the `break` statement.

**Code example**

```c
while (1) {
    // run forever
}
```