---
title: "Boolean expressions"
date: 2020-12-23T21:58:56+01:00
weight: 1
---

C (unlike C++) does not have a boolean data type. As shown in the table in chapter [Data types](../../vars/datatypes), you can use `_Bool` for that. But the usual convention is that any boolean expression returns integer values:

- `0` if an expression evaluates as `FALSE`
- non-zero if it evaluates as `TRUE` (usually `1`, but this is not guaranteed)

**Code example**

```c
int main (void) {
    int a = 3, b, c;
    c = (a > 2); // c = 1 (TRUE)
    b = (a < 1); // b = 0 (FALSE)
}
```

## Express it differently

Expressions can be written in different ways which all lead to the same result (are evaluated similarly). Laziness drives programmers to usually use the first method of the following example:

**Code example**

```c
#define BUTTONPRESSED 1

int main (void) {
    if (BUTTONPRESSED)
      // do something
    if (BUTTONPRESSED != 0)
      // do something else
}
```
