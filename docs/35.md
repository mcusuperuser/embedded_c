# Decision making

## Boolean expressions

C (unlike C++) does not have a boolean data type. As shown in the table in chapter [Data types](#data-types), you can use `_Bool` for that. But the usual convention is that any boolean expression returns integer values:
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

### Express it differently

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

## `if` statement

**Syntax**
```c
if (expression) statement
```

The expression is evaluated in a boolean fashion. If it is true, the statement is executed.

*Note*

- The `statement` can also be a compound/block statement.

**Code example**
```c
#define BUTTONPRESSED 1

int main (void) {
    if (BUTTONPRESSED) {
        printf("Button is pressed\n");
    }
}
```

### `if (a)` vs. `if (a == 1)`

Not only laziness commands the usage of `if (a)`. This C code will also lead to reduced assembly code size, as it only has to test for not being equal to `0`:

```
0x00001170 4807      LDR      r0,[pc,#28]  ; @0x00001190
0x00001172 6800      LDR      r0,[r0,#0x00]
0x00001174 B110      CBZ      r0,0x0000117C
```

`if (a == 1)` creates more assembly code, as it has to explicitly check the equality with `1`:

```
0x0000117C 4808      LDR      r0,[pc,#32]  ; @0x000011A0
0x0000117E 6800      LDR      r0,[r0,#0x00]
0x00001180 2801      CMP      r0,#0x01
0x00001182 D102      BNE      0x0000118A
```

*Note*

- `CBZ` is the "compare and branch on zero" instruction that will only branch if the comparison with `0` is TRUE.
- There is no "compare and branch on one" instruction, so you have to compare first (`CMP`) and then branch (`BNE`) if the result is not equal one.

### Nesting `if` statements

You can nest `if` statements easily.

**Code example**
```c
#define BUTTONPRESSED 1
float adc_input;

int main (void) {
    if (BUTTONPRESSED) {
        printf("Button is pressed\n");
        } if (adc_input >= 2.3) {
            printf("Input is larger than 2.3\n");
            }
}
```

### `if else` statement

**Syntax**
```c
if (expression) statement1
else statement2
```

The expression is evaluated in a boolean fashion. If it is true, statement1 is executed, if false, statement2 is executed.

**Code example**
```c
#define BUTTONPRESSED 1

int main (void) {
    if (BUTTONPRESSED) {
        printf("Button is pressed\n");
        } else {
            printf("Button is not pressed!\n");
            }
}
```

### `if else if` statement

**Syntax**
```c
if (expression1) statement1
else if (expression2) statement2
else statement3
```

The expression1 is evaluated in a boolean fashion. If it is true, statement1 is executed, if false, expression2 is evaluated. If it is true, statement2 is executed, if false, statement3 is executed.

**Code example**
```c
float adc_input;

int main (void) {
    if ((adc_input > 0) && (adc_input <= 1.0)) {
        printf("Input below 1 V!\n");
    } else if { ((adc_input > 1.0) && (adc_input <= 2.0))
        printf("Input above 1 V and below 2 V!\n");
    } else if { ((adc_input > 2.0) && (adc_input <= 3.0))
        printf("Input above 2 V and below 3 V!\n");
    } else {
        printf("Incorrect input voltage!");
    }
}
```

## `switch` statement

**Syntax**
```c
switch (expression) {
    case const-expr1: statements1
    :
    case const-exprn: statementsn
    default: statementsn+1
}
```

The expression is evaluated and tested for a match with the const-expr in each case clause. The statement(s) in the matching case clause is/are executed.


*Note*

- Each statement falls through to the next statement. This is the default behavior of the switch statement.
- Adding a `break` statement to each statement block will eliminate fall through, allowing only one case clause's statement block to be executed.

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


