---
title: "if statement"
date: 2020-12-23T21:59:01+01:00
weight: 2
---

**Syntax**

```c
if (expression) statement
```

The expression is evaluated in a boolean fashion. If it is true, the statement is executed.

{{% notice note %}}
The `statement` can also be a compound/block statement.
{{% /notice %}}

**Code example**

```c
#define BUTTONPRESSED 1

int main (void) {
    if (BUTTONPRESSED) {
        printf("Button is pressed\n");
    }
}
```

## `if (a)` vs. `if (a == 1)`

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

{{% notice note %}}
`CBZ` is the "compare and branch on zero" instruction that will only branch if the comparison with `0` is TRUE.  
There is no "compare and branch on one" instruction, so you have to compare first (`CMP`) and then branch (`BNE`) if the result is not equal one.
{{% /notice %}}

## Nesting `if` statements

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

## `if else` statement

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

## `if else if` statement

**Syntax**

```c
if (expression1) statement1
else if (expression2) statement2
else statement3
```

The `expression1` is evaluated in a boolean fashion. If it is true, `statement1` is executed, if false, `expression2` is evaluated. If it is true, `statement2` is executed, if false, `statement3` is executed.

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
