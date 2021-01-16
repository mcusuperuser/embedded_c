---
title: "switch statement"
date: 2020-12-23T21:59:06+01:00
weight: 3
---

**Syntax**

```c
switch (expression) {
    case const-expr1: statements1
    :
    case const-exprn: statementsn
    default: statementsn+1
}
```

The expression is evaluated and tested for a match with the `const-expr` in each case clause. The statement(s) in the matching case clause is/are executed.

{{% notice note %}}
Each statement falls through to the next statement. This is the default behavior of the switch statement.  
Adding a `break` statement to each statement block will eliminate fall through, allowing only one case clause's statement block to be executed.
{{% /notice %}}

**Code example**

```c
switch (number) {
    case 0:  printf("Zero selected\n");  break;
    case 1:  printf("One selected\n");   break;
    case 2:  printf("Two selected\n");   break;
    case 3:  printf("Three selected\n"); break;
    case 4:  printf("Four selected\n");  break;
    case 5:  printf("Five selected\n");  break;
    case 6:  printf("Six selected\n");   break;
    case 7:  printf("Seven selected\n"); break;
    case 8:  printf("Eight selected\n"); break;
    case 9:  printf("Nine selected\n");  break;
    default: printf("No number selected\n");
}
```
