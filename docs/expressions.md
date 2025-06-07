# Expressions and statements

Every C program is made using statements. The program is executed statement by statement. Every statement is made using
one or more expressions. An expression is a sequence of [operators](./operators.md#operators) and their operands that
specifies a computation.

In other words, an expression is an instruction that is executed and returns a value (even when this value is `void`).
A statement is used to form the sequence of a program (see below).

There are three kinds of statements in C:
1. [Expression statements](#expression-statements)
1. [Compound statements](#compound-or-block-statements)
1. [Control statements](#control-statements)

**Code example**

```c
n + m
a = b
time = dist/speed
x = ReadIO()
f <= 2
y == 42
count++
c = b + 3
```

## Expression statements

An expression statement is an expression followed by a semicolon (`;`). The execution of the statements causes the
expression to be evaluated.

**Code example**

```c
a = 0;
a++;
b = 3 + c;
y = (a * x) + b;
printf("Speed = %f", x);
; // the semicolon itself is an expression
```

## Compound or block statements

A compound statement is a group of statements enclosed within a pair of curly braces (`{ }`) and is often also called a
block statement. The statements within the block may be of any statement type (including (again) compound statements).
This allows statements to be embedded or nested within other statements. A compound statement **does not** end with a
semicolon after the closing `}`.

**Code example**

```c
{
  a = 0;
  a++;
  b = 3 + c;
  y = (a * x) + b;
  printf("Speed = %f", x);
}
```

## Control statements

Control statements are used for loops, branches and logical tests and often require other statements to be embedded
within them. We will take a closer look at them in the chapter
[Decision making](./making_decisions.md#decision-making).

**Code example**

```c
while (1) {
    // do something here
}
```
