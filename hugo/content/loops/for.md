---
title: "For loop"
date: 2020-12-23T22:07:56+01:00
weight: 1
---

A `for` loop checks the loop condition at the top and automatically executes the iterator at the bottom of the loop.

**Syntax**

```c
for (expression1; expression2; expression 3)
    statement
```

The expression1 initializes the loop count variable once (e.g. n= 0). The expression2 is the test condition. The loop will continue while this is true
(e.g. n <= 10). The expression3 is executed at the end of each iteration; usually to modify the loop count variable (e.g. n++).

*Note*

- Any or all of the three expressions may be left blank (semicolons must remain)
- If expression1 or expression3 are missing, their actions simply disappear
- If expression2 is missing, it is assumed to always be true

**Code example**

```c
int n;

for (n = 0; n < 5; n++ ) {
    printf("Loop iteration %d\n", n);
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

### Infinite for loops

A `for` loop without any expressions will execute indefinitely. You can only leave the loop using the `break` statement.

**Code example**

```c
for (;;) {
    // run forever
}
```