# Comments

What is a comment?

> Comments are used to document a program's functionality. They explain what a particular block or line of code does. Comments are always ignored by the compiler.

There are two kinds of comments:

### Block comment
```c
/* This is a comment. */
```

- They begin with /* and end with */
- Can span multiple lines

**Code example**
```c
/*-----------------------------------------------
 * CMSIS-RTOS 'main' function template
 *---------------------------------------------*/

#include "cmsis_os2.h"

/*
 * main: initialize and start the system
 */
int main (void) {
  osKernelInitialize (); /* initialize RTOS */
  
  LED_Initialize();      /* initialize LEDs */
  /* create 'thread' functions that
     start executing. Example:
     tid_name=osThreadCreate (osThread(name), NULL);
  */

  osKernelStart (); /* start thread execution */
}
```

### Single line comment
 ```c
// This is a single line comment.
```

- They begin with // and run until the end of the current line 
- Can *not* span multiple lines

**Code example**
```c
//-----------------------------------------------
// CMSIS-RTOS 'main' function template
//-----------------------------------------------

#include "cmsis_os2.h"

// main: initialize and start the system

int main (void) {
  osKernelInitialize (); // initialize RTOS
  
  LED_Initialize();      // initialize LEDs
  // create 'thread' functions that start executing
  // Example:
  // tid_name=osThreadCreate (osThread(name), NULL);

  osKernelStart (); // start thread execution
}
```

### Nesting comments

- Block comments must not be nested within other comments
- Single line comments may be nested

**Code example**
```c
/*-----------------------------------------------
 * CMSIS-RTOS 'main' function template
 * // comment within a comment
 *---------------------------------------------*/

#include "cmsis_os2.h"

/*
 * main: initialize and start the system
 */
int main (void) {
  osKernelInitialize (); /* initialize RTOS */
  
  LED_Initialize();      /* initialize LEDs */
  /* create 'thread' functions that start
     executing,
     /* another comment which doesn't work  */
     example:
     tid_name=osThreadCreate (osThread(name), NULL);
  */

  osKernelStart (); /* start thread execution */
}
```

# Variables, identifiers and data types

What is a variable?

> A variable is a name that represents one or more memory locations used to hold program data.

A variable is a kind of bucket that you can use to hold program data.

**Code example**
```c
int myVar;
myVar = 42;
```

- Variable declarations consist of a **data type** and a unique **identifier (name)**

```c
int myVar;
char myLetter;
float myFLoat,
```

- The data type determines the size of the memory location that is used to store the variable and determines how the value of the variable is interpreted.

## Identifiers

What are identifiers?

> Identifiers are names that are given to program elements, such as variables, functions, arrays, or any other named element.

- Valid characters in identifiers are '_', 'a' to 'z', 'A' to 'Z', and '0' to '9' (not allowed for the first character).
- Identifiers are case sensitive, so `myVar` is not the same as `myvar`!
- You *must not use* keywords of the C language as identifiers.
- The Arm compiler provides additional keywords that are extensions to the C/C++ standards and *must also not be used* as identifiers.

### ANSI C keywords

| | | | | |
|---|---|---|---|---|
| auto | break | case | char | const |
| continue | default | do | double | else |
| enum | extern | float | for | goto |
| if | int | long | register | return |
| short | signed | sizeof | static | struct |
| switch | typedef | union | unsigned | void |
| volatile | while ||||

### Arm compiler 5 keywords and operators

| | | |
|---|---|---|
| __align | __int64 | __svc |
| \_\_ALIGNOF\_\_ | \_\_INTADDR\_\_ | __svc_indirect |
| __asm | __irq | __svc_indirect_r7 |
| __declspec | __packed | __value_in_regs |
| __forceinline | __pure | __weak |
| __global_reg | __softfp | __writeonly |
| __inline | __smc ||

### Arm compiler 6 (armclang) keywords and operators

| | | | |
|---|---|---|---|
| \_\_alignof\_\_ | \_\_asm | \_\_declspec | \_\_inline |

## Data types

C provides various data types. Normally, you would use:
- `int` for most variables and things that you can count, such as loop counts and events
- `char` for characters and strings
- `float` for measurable things that require decimal numbers, such as distance, temperature, voltage
- `uint32_t` for bit manipulations, especially on 32-bit registers
- The appropriate `<stdint.h>`/`<arm_math.h>` types for storing and working with data explicitly meeting your needs (for example if you require that an interget has exactly N bits)

### Size and alignment of basic data types in Arm C/C++

ANSI C Type        | <stdint.h> C Type  | Size in bits | Natural alignment in bytes | Range of values
|------------------|------------------------|:------------:|:--------------------------:|:---------------|
char               | uint8_t                | 8            | 1 (byte-aligned)           | 0 to 255 (unsigned) by default.
signed char        |  int8_t                | 8            | 1 (byte-aligned)           | -128 to 127
unsigned char      | uint8_t                | 8            | 1 (byte-aligned)           | 0 to 255
signed short       |  int16_t               | 16           | 2 (halfword-aligned)       | -32,768 to 32,767
unsigned short     | uint16_t               | 16           | 2 (halfword-aligned)       | 0 to 65,535
signed int         |  int32_t               | 32           | 4 (word-aligned)           | -2,147,483,648 to 2,147,483,647
unsigned int       | uint32_t               | 32           | 4 (word-aligned)           | 0 to 4,294,967,295
signed long        |                        | 32           | 4 (word-aligned)           | -2,147,483,648 to 2,147,483,647
unsigned long      |                        | 32           | 4 (word-aligned)           | 0 to 4,294,967,295
signed long long   |  int64_t               | 64           | 8 (doubleword-aligned)     | -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807
unsigned long long | uint64_t               | 64           | 8 (doubleword-aligned)     | 0 to 18,446,744,073,709,551,615
float              | float32_t <arm_math.h> | 32           | 4 (word-aligned)           | 1.175494351e-38 to 3.40282347e+38 (normalized values)
double             | float64_t <arm_math.h> | 64           | 8 (doubleword-aligned)     | 2.22507385850720138e-308 to 1.79769313486231571e+308 (normalized values)
long double        | float64_t <arm_math.h> | 64           | 8 (doubleword-aligned)     | 2.22507385850720138e-308 to 1.79769313486231571e+308 (normalized values)
All pointers       |                        | 32           | 4 (word-aligned)           | Not applicable.
bool (C++ only)    |                        | 8            | 1 (byte-aligned)           | false or true
\_Bool (C only)    |                        | 8            | 1 (byte-aligned)           | false or true

*Notes*
- Integers are represented in two's complement form.
- Floating-point quantities are stored in IEEE format.

### How to declare a variable

```c
type identifier1, identifier2, ..., identifiern;
```

- Variables must be declared before they can be used
- The type is important! It tells the compiler how much memory space to allocate and how handle the values

```c
char myFirstLetter;
int a, b, c;
float currentSpeed;
double sensorValue;
```

There are multiple ways to declare a variable:

**Declaration on a single line**
```c
type name;
```

**Declaration on a single line with an initial value**
```c
type name = initialValue;
```

**Multiple declarations of the same type on a single line**
```c
type name1, name2, name3;
```

**Multiple declarations of the same type on a single line with initial values**
```c
type name1 = value1, name2 = value2, name3;
```

**Code example**
```c
unsigned int myVar;
signed int answer = 42;
char myFirstLetter = 'a', mySecondLetter, myLastLetter = 'z';
float hugeNumber = 5.12e+21
```

## Using typedefs
**Syntax**
```c
typedef type typeName;
```

- Typedefs are an alternative way to name types and create an alias name for the type.
- The *typeName* is now the same as the type

**Code example**
```c
typedef unsigned int uint32_t;

uint32_t a, b;    // alias for unsigned int a, b;
```

### Declaring variables

*Header* files are used to declare variables and other program elements in a separate file. Usually, header files have the filename extension *.h*. To use a header file in your C code, associate it with the `#include` directive.

The `#include` directive can be used in three different ways. You can:

1. Look for a header file in the compiler include path, which contains the compiler's directory and all of its sub-directories:
```c
#include <stdio.h>
```
2. Look for a file in the project directory:
```c
#include "myHeader.h"
```
3. Look for a file using an absolute or relative path:
```c
#include "..\..\myHeader2.h"
#include "C:\projects\myProject\inc\myHeader3.h"
```

**Code example**

main.h header file:
```c
int n, m, p;
float myFloat;
```

main.c source file:
```c
#include "main.h"

int main (void) {
    n = 3;
    m = 1;
    p = n - m;
    myFLoat = 1 / p;
}
```
Using the `#include` directive, the contents of the main.h header file are pasted into the main.c source file, starting at the `#include` directive’s line.

After the preprocessor runs, the compiler sees the main.c source file as follows:
```c
int n, m, p;
float myFloat;

int main (void) {
    n = 3;
    m = 1;
    p = n - m;
    myFloat = 1 / p;
}
```


# Constants and literals

What are constants and literals?

> A literal is a notation for representing a fixed value in source code. A constant is a value that cannot be altered by the program during normal execution.

In other words: a literal is the actual value (such as a number or character for example), that is assigned to a variable or constant. You can also use literals directly as a function parameter or as an operand in an expression.
While both terms are often used interchangeably, they are not the same. A literal is a constant, but a constant is not a literal.

Constants, as the name implies, never change their value which makes development changes easy and eliminates the use of "magic numbers".

### How to declare a constant

There are two ways to declare a constant:

```c
#define identifierName value
const type identifierName value;
```
- The `identifierName` is the constant, while the `value` is the literal.
- The first way is very efficient for an embedded system, as it does not consume any memory in the microcontroller. Using the `#define`, you declare a text subsitution label, which means that each instance of identifierName will be replaced with value by the preprocessor unless identifierName is inside a string.
- A `#define` is *never* terminated with a ';', unless you want that semicolon to be part of the substitution.
- The second way allocates a variable in program memory, but it cannot be changed due to the `const` keyword. While this is inefficient for normal constants, it is a good way to save lookup tables in Flash memory for example.

## Types of literals

The Arm assembler user's guide states that "source code can contain numeric, string, Boolean, and single character literals".

Literals can be expressed as:
- Decimal numbers, for example `123`.
- Hexadecimal numbers, for example `0x7B`.
- Numbers in any base from 2 to 9, for example `5_204` is a number in base 5.
- Floating point numbers, for example `123.4`.
- Boolean values `{TRUE}` or `{FALSE}`.
- Single character values enclosed by single quotes, for example `'w'`.
- Strings enclosed in double quotes, for example `"This is a string"`.

### String literals

C does not have a string type. One way to store strings in C is to use arrays of characters. Later, we will learn how to use pointers to define strings.

When strings are declared as character arrays, they are stored like other types of arrays in C. If you declare the string without a dimension, the null character is automatically appended to the end of the string:

**Code example**
```c
char name[] = "Cortex";
```

This is stored as:
```c
name[0] = 'C'
name[1] = 'o'
name[2] = 'r'
name[3] = 't'
name[4] = 'e'
name[5] = 'x'
name[6] = '\0'
```

**Special characters in strings**

Use escape sequences to include special characters in strings, just like any other ordinary character. The backslash '\' plus the following character is considered as a single character with a single ASCII value.

**Code example**
```c
char salutation[] = "Dear Paul,\n";
```

In order to nest strings, you need to use escape the double quotes:

```c
"printf (\"hello world!\n\")"
```
# The printf() C library function

Using the Arm C complier, it is mandatory to link your application with the standard C library, even you do not directly use C library functions. This is because the compiler might impleicitly generate calls to C library functions.
The standard C library consists of:
- All functions defined by the ISO C99 library standard.
- Target-dependent functions that implement the C library functions in the semihosted execution environment. You can redefine these functions in your own application.
- Functions called implicitly by the compiler.
- Arm extensions that are not defined by the ISO C library standard, but are included in the library.

One of the most commonly used C library function is the `printf()` function which allows to write text to the "standard output" (normally a monitor or line printer). In embedded systems, often a UART is used. In Arm Cortex-N based systems you can redirect the standard output to the ITM debug channel which saves resourecs (the UART) and is much faster. In µVision, you can use the "Debug printf() Viewer" window to observe `printf()` messages delivered via ITM.

### How to use printf()

```c
printf(ControlString, arg1, ..., argn);
```
Everything within the `ControlString` is printed verbatim except `%d`'s
which are replaced by the argument values from the list.

**Code example**
```c
int n = 1, m = 7;
printf("n = %d\nm = %d\n", n, m);
```
The output is:
```c
n = 1
m = 7
```
*Note*
The character `%d` is the *conversion character*.

### Conversion characters for the ControlString

| Conversion character | Description |
|---:|---|
| %c | Single character
| %s | String (all characters until `\0`)
| %d | Signed decimal integer
| %# | A `0x` should precede a hexadecimal number
| %u | Unsigned decimal integer
| %x | Unsigned hexadecimal integer with lowercase digits (`1a4e`)
| %X | As x, but with uppercase digits (`1A4E`)
| %f | Signed decimal value (floating point)
| %e | Signed decimal with exponent (`1.13e-4`)
| %E | As e, but uses E for exponent (`1.13E-4`)
| %g | As e or f, but depends on size and precision of value
| %G | As g, but uses E for exponent



# Operators

What is an operator?

> An arithmetic expression contains one or more operands and arithmetic operators.

Operands may be variables, constants or functions that return a value.

## Arithmetic operators

Arithmetic operators are used to perform arithmetic/mathematical operations on operands. Arithmetic operators are of two distinct types: 
- Binary Operators work on two operands: +, -, *, /, %
- Unary Operators work on a single operand: +, -, ++, --

| Operator | Operation | Example | Result |
|:----------:|-----------|:---------:|--------|
| * | Multiplication | `a * b` | Product of `a` and `b` |
| / | Division | `a / b` | Quotient of `a` and `b` |
| % | Modulo | `a % b` | Remainder of `a` divided by `b` |
| + | Addition | `a + b` | Sum of `a` and `b` |
| - | Subtraction | `a - b` | Difference of `a` and `b` |
| - | (unary) Negative | `-a` | Negative value of `a`|
| + | (unary) Positive | `+a` | Value of `a` |

### Division operator

If both operands are of an integer type, the result will be an interger type as well (valid for `int` and `char`).

If one or both of the operands is a floating point type, the result will be a floating point type (`float`, `double`).

### Implicit type conversion

When an expression is used in the context where a value of a different type is expected, conversion may occur. In such cases, the type of one operand will be temporarily "promoted" to the larger type of the other operand. This means that during an operation, the smaller data type will be promoted to the largest one in the expression.

**Code examples**
```c
short n = -5;
-n      // promotion to int; result is 5
n * -3L // promotion to long, because -3L is a long; result is 15
7 / n   // promotion to int; result is -1
9 % n   // promotion to int; result is 4
8.0 / n // promotion to double, because 8.0 is a double; result is -1.6
```

### Increment and decrement

Increment/decrement operators are unary operators that increment/decrement the value of a given variable by 1.

| Operator | Operation | Example | Result |
|:----------:|-----------|:---------:|--------|
| ++ | Increment | `a++` | Postfix form: use `a` and then add `1` |
|  |  | `++a` | Prefix form: add `1` to `a` and then use `a` |
| -- | Decrement | `a--` | Postfix form: use `a` and then subtract `1` |
|  |  | `--a` | Prefix form: subtract `1` from `a` and then use `a` |

**Code example**
```c
int n, m;
n = 3;

// Postfix example
m = (n++) + 8;  // Result: n = 4, m = 11

// Prefix example
m = (++n) + 8;  // Result: n = 4, m = 12
```

## Assignment operators

Assignment operators are binary operators that modify the variable to their left using the value to their right, or in other words, they assign a value to a variable.

There are two types of assingment operators available:

### Simple assignments

`variable = expression`

The expression is evaluated and the result is assigned to the variable.

### Compound assignments

`variable = variable operator expression`

The variable is modified using the operator and the expression and the result is assigned to the variable.

| Operator  | Example   | Equivalent |
|:---------:|:---------:|--------|
|`=`        | `a = b`   | Assign the value of `b` to `a`
|`+=`       | `a += b`  | `a = a + b`
|`-=`       | `a -= b`  | `a = a - b`
|`*=`       | `a *= b`  | `a = a * b`
|`/=`       | `a /= b`  | `a = a / b`
|`%=`       | `a %= b`  | `a = a % b`
|`&=`       | `a &= b`  | `a = a & b`
|`\|=`      | `a \|= b` | `a = a \| b`
|`^=`       | `a ^= b`  | `a = a ^ b`
|`<<=`      | `a <<= b` | `a = a << b`
|`>>=`      | `a >>= b` | `a = a >> b`

## Relational (comparison) operators

Relational operators are binary operators that test a condition and return `1` if that condition is logically `true` and `0` if that condition is `false`. 

| Operator | Operation                | Example  | Result (FALSE = 0, TRUE = 1) |
|:--------:|:-------------------------|:--------:|------------------------------|
| `==`     | Equal to                 | `a == b` | `1` if `a` equal to `b`, else `0` |
| `!=`     | Not equal to             | `a != b` | `1` if `a` not equal to `b`, else `0` |
| `>`      | Greater than             | `a > b`  | `1` if `a` greater than `b`, else `0` |
| `>=`     | Greater than or equal to | `a >= b` | `1` if `a` greater than or equal to `b`, else `0` |
| `<`      | Less than                | `a < b`  | `1` if `a` less than `b`, else `0` |
| `<=`     | Less than or equal to    | `a <= b` | `1` if `a` less than or equal to `b`, else `0` |

*Note*

Do not interchange `=` with `==`. `=` is the assignment operator, while `==` is the "equals to" relational operator.

**Code example**
```c
int n, m;

n = 3;         // assing the value 3 to a

if (m == 45) { // check if m equals to 45
    // do something here
}
```

## Logical operators

Logical operators apply standard *boolean algebra* operations to their operands.

| Operator | Operation   | Example  | Result |
|:--------:|:------------|:--------:|--------|
| `!`      | Logical NOT | `!a`     | `1` if `a = 0`, else `0`
| `&&`     | Logical AND | `a && b` | `1` if both `a ≠ 0` and `b ≠ 0`, else `0`
| `||`     | Logical OR  | `a || b` | `0` if both `a = 0` and `b = 0`, else `1`

## Bitwise operators

Bitwise operators apply the operation to each bit of the first operand with each corresponding bit of the second operand.

| Operator | Operation           | Example  | Result |
|:--------:|:--------------------|:--------:|--------|
| `~`      | Bitwise NOT         | `~a`     | `1`, if `0` in `a`; `0`, if `1` in `a`
| `&`      | Bitwise AND         | `a & b`  | `1`, if `1` in both `a` and `b`; `0`, if `0` in `a` or `b` or both
| `|`      | Bitwise OR          | `a | b`  | `1`, if `1` in `a` or `b` or both; `0`, if `0` in both `a` and `b`
| `^`      | Bitwise XOR         | `a ^ b`  | `1`, if `1` in `a` or `b` but not both; `0`, if `0` or `1` in both `a` and `b`

*Note*

- The bitwise NOT is also known as "One's complement".
- Do not interchange `&` with `&&`. `&` is the bitwise AND operator, while `&&` is the logical AND operator.

**Code example**
```c
int n, m;

if (n && m) { // check if both values are true (non-zero)
    // do something here
}
```

## Shift operators

| Operator | Operation           | Example  | Result |
|:--------:|:--------------------|:--------:|--------|
| `<<`     | Bitwise left shift  | `a << b` | Shift `a` by `b` bits to the left
| `>>`     | Bitwise right shift | `a >> b` | Shift `a` by `b` bits to the right

*Note*

- Bits that are shifted out are lost (in both cases)
- For shift left, 0's are shifted in (zero fill)

**Code example**
```c
// Logical shift right (zero fill)
// If a is unsigned:
unsigned char a;
a = 250;    // a = 0b11111010 = 250
b = a >> 2; // b = 0b00111110 = 62

// Arithmetic shift right (sign extend)
// If a is signed:
char a;
a = -6;     // a = 0b11111010 = -6
b = a >> 2; // b = 0b11111110 = -2
```

### Power of 2 integer divide vs. shift right

Generally, it is more efficient to use a shift right instead of dividing by a power of 2. This means that `b = a / 2^n` is equal to `b = a >> n`. This trick works for integer and fixed point values.

## Memory addressing/member access

Member access operators allow access to the members of their operands.

| Operator | Operation                     | Example  | Result |
|:--------:|:------------------------------|:--------:|--------|
| `[]`     | Array subscript               | `a[b]`   | access the `b`th element of array `a`
| `*`      | Pointer dereference           | `*a`     | The object or function `a` points to
| `&`      | Address of                    | `&a`     | Pointer to `a`
| `.`      | Member access (struct/union)  | `a.b`    | The member `b` of struct or union `a`
| `->`     | Member access through pointer | `a->b`   | The member `b` of struct or union pointed to by `a`

*Note*

This will become important when talking about arrays, pointers, structs, and unions later.

## Other operators

| Operator | Operation            | Example     | Result |
|:--------:|:---------------------|:-----------:|--------|
| `(...)`  | Function call        | `f(...)`    | Calls the function f(), with specified arguments
| `,`      | Comma operator       | `a, b`      | Evaluates `a` then `b`, else result is value of `b`
| `(type)` | Type cast            | `(type)a`   | Casts the type of `a` to type
| `? :`    | Conditional operator | `a ? b : c` | The value of `b` if `a` is true, else value of `c`
| `sizeof` | Sizeof operator      | `sizeof a`  | The size in bytes of `a`

### The conditional operator

`(test_expression) ? do_if_true : do_if_false;`

**Code example**
```c
int a = 3, b = 4, c;

(a % 2 != 0) ?
  printf("%d is odd\n", a) :
  printf("%d is even\n", a);

c = (a % 2 != 0) ? a : b; // conditionally assigs a value to c
```

### Explicit type cast operator

You can use the cast operator `(type)` to cast a variable:

**Code example**
```c
int a = 10;
float b;
b = (float)a / 4; // b is 2.5, because float/int = float
```

## Operator precedence

The following table lists the precedence and associativity of C operators. Operators are listed top to bottom, in descending precedence. Conflicts between operators with the same precedence are handled via the rules of associativity.

Precedence | Operator       | Description | Associativity
|:--------:|:--------------:|:-----------|--------|
|1         | `++ --`        | Suffix/postfix increment and decrement | Left-to-right
|          | `()`           | Function call| |
|          | `[]`           | Array subscripting| |
|          | `.`            | Structure and union member | |
|          | `->`           | Structure and union member access through pointer| |
|          | `(type){list}` | Compound literal(C99)| |
|2         | `++ --`        | Prefix increment and decrement | Right-to-left
|          | `+ -`          | Unary plus and minus| |
|          | `! ~`          | Logical NOT and bitwise NOT| |
|          | `(type)`       | Type cast| |
|          | `*`            | Indirection (dereference)| |
|          | `&`            | Address-of| |
|          | `sizeof`       | Size-of| |
|3         | `* / %`        | Multiplication, division, and remainder | Left-to-right
|4         | `+ -`          | Addition and subtraction| |
|5         | `<< >>`        | Bitwise left shift and right shift| |
|6         | `< <=`         | For relational operators < and ≤ respectively| |
|          | `> >=`         | For relational operators > and ≥ respectively| |
|7         | `== !=`        | For relational = and ≠ respectively| |
|8         | `&`            | Bitwise AND| |
|9         | `^`            | Bitwise XOR (exclusive or)| |
|10        | `|`            | Bitwise OR (inclusive or)| |
|11        | `&&`           | Logical AND| |
|12        | `||`           | Logical OR| |
|13        | `?:`           | Ternary conditional | Right-to-Left
|14        | `=`            | Simple assignment| |
|          | `+= -=`        | Assignment by sum and difference| |
|          | `*= /= %=`     | Assignment by product, quotient, and remainder| |
|          | `<<= >>=`      | Assignment by bitwise left shift and right shift| |
|          | `&= ^= |=`     | Assignment by bitwise AND, XOR, and OR| |
|15        | `,`            | Comma | Left-to-right 

### Precedence

When expressions contain multiple operators, their precedence determines the order of evaluation.

| Expression    | Expression with precedence |
|:-------------:|:--------------------------:|
| `a – b * c`   | `a – (b * c)`              |
| `a + ++b`     | `a + (++b)`                |
| `a + ++b * c` | `a + ((++b) * c)`          |

*Note*

If functions are part of an expression, there is no way to tell which function is evaluated first. 

### Associativity

For two operators with the same precedence, the associativity determines the order of the evaulation of the expression.

| Expression  | Associativity | Expression with precedence |
|:-----------:|:--------------|:--------------------------:|
| `x / y % z` | Left-to-Right | `(x / y) % z`              |
| `x = y = z` | Right-to-Left | `x = (y = z)`              |
| `~++x`      | Right-to-Left | `~(++x)`                   |

Although these rules are always applied, it is good practise to explicitly group the elements of an expression using `()`.
# Expressions and statements

Every C program is made using statements. The program is executed statement by statement. Every statement is made using one or more expressions. An expression is a sequence of [operators](#operators) and their operands that specifies a computation.

In other words, an expression is an instruction that is executed and returns a value (even when this value is `void`). A statement is used to form the sequence of a program (see below).

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

An expression statement is an expression followed by a semicolon (`;`). The execution of the statements causes the expression to be ealuated.

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

A compund statement is a group of statements enclosed within a pair of curly braces (`{ }`) and is often also called a block statement. The statements within the block may be of any statement type (including (again) compound statements). This allows statements to be embedded or nested within other statements. A compound statement **does not** end with a semicolon after the closing `}`.

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

Control statments are used for loops, branches and logical tests and often require other statements to be embedded within them. We will take a closer look at them in the chapter [Decision making](#decision-making).

**Code example**
```c
while (1) {
    // do something here
}
```
# Pointers

What is a pointer?

Many books will teach you that a pointer points to something, but this is not true:

> A pointer is a variable that contains the memory address of another variable.

As any other variable, you need to declare a pointer. Furthermore, you have to initialize a pointer before you can use it.

## Pointer declaration

You declare a pointer just like any other variable:

`type *name;`

- `type` can be any C type (such as `char`, `int`, or `float` for example).
- `name` is the name of the pointer variable.
- The `*` makes the variable a pointer.

**Code example**
```c
int *myPointer        // declares a pointer named myPointer as an integer type
float *myOtherPointer // declares a pointer named myOtherPointer as a float type

myPointer = &myIntVar;        // assigns the memory address of myIntVar to myPointer
myOtherPointer = &myFloatVar; // assigns the memory address of myFloatVar to myOtherPointer
```

## Working with pointers
