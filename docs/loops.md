# Loops

The C language provides three basic looping structures:

- [`for` loop](#for-loop): checks the loop condition at the top and automatically executes the iterator at the bottom
  of the loop.
- [`while` loop](#while-loop): checks the loop condition at the top; you must create the iterator if needed.
- [`do-while` loop](#do-while-loop): checks the loop condition at the bottom; you must create the iterator if needed.

## `for` loop

**Syntax**

```c
for (expression1; expression2; expression 3)
    statement
```

The expression1 initializes the loop count variable once (e.g. n= 0). The expression2 is the test condition. The loop will continue while this is true
(e.g. n <= 10). The expression3 is executed at the end of each iteration; usually to modify the loop count variable (e.g. n++).

!!! Note
    - Any or all of the three expressions may be left blank (semicolons must remain).
    - If expression1 or expression3 are missing, their actions simply disappear.
    - If expression2 is missing, it is assumed to always be true.

**Code example**

```c
int n;

for (n = 0; n < 5; n++ ) {
    printf("Loop iteration %d\n", n);
}
```

**Output**

```txt
Loop iteration 0
Loop iteration 1
Loop iteration 2
Loop iteration 3
Loop iteration 4
```

### Infinite for loops

A `for` loop without any expressions will execute indefinitely. You can only leave the loop using the `break`
statement.

**Code example**

```c
for (;;) {
    // run forever
}
```

## `while` loop

**Syntax**

```c
while (expression)
    statement
```

If the expression is true, the statement will be executed. Afterwards, the expression will be reevaluated to determine
whether or not to execute the statement again. It is possible that the statement will never be executed if the
expression is false when it is evaluated for the first time.

!!! Note
    - The expression must always be there, unlike with a for loop.
    - `while` is used more often than `for` when implementing an infinite loop, though it is only a matter of personal
    taste (mainly less coding effort).
    - Frequently used for the main loop of a program.

**Code example**

```c
int n = 0;

while (n < 5) {
    printf("Loop iteration %d\n", n++);
}
```

**Output**

```txt
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

## `do-while` loop

**Syntax**

```c
do statement while (expression);
```

The statement is executed and then the expression is evaluated to determine whether or not to execute the statement
again. The statement will always execute at least once, even if the expression is false when the loop starts.

**Code example**

```c
int n = 0;

do { printf("Loop iteration %d\n", n); }
while (n < 5);
```

**Output**

```txt
Loop iteration 0
Loop iteration 1
Loop iteration 2
Loop iteration 3
Loop iteration 4
```

## `break` statement

**Syntax**

```c
break;
```

The `break` statement causes immediate termination of a loop, even if the exit condition has not been met. Also, it
exits from a `switch` statement so that execution doesn't fall through to next `case` clause.

**Code example**

```c
int n = 0;

while (n < 10) {
    if (n == 5) break;
    printf("Loop iteration %d\n", n++);
}
```

**Output**

```txt
Loop iteration 0
Loop iteration 1
Loop iteration 2
Loop iteration 3
Loop iteration 4
```

## `continue` statement

**Syntax**

```c
continue;
```

The `continue` statement causes a program to jump back to the beginning of a loop without completing the current
iteration.

**Code example**

```c
int n = 0;

while (n < 5) {
    if (n == 3) continue;
    printf("Loop iteration %d\n", n++);
}
```

**Output**

```txt
Loop iteration 0
Loop iteration 1
Loop iteration 2
Loop iteration 4
```
