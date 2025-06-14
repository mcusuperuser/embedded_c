# Constants and literals

What are constants and literals?

!!! Important
    A literal is a notation for representing a fixed value in source code. A constant is a value that cannot be altered
    by the program during normal execution.

In other words: a literal is the actual value (such as a number or character for example), that is assigned to a
variable or constant. You can also use literals directly as a function parameter or as an operand in an expression.
While both terms are often used interchangeably, they are not the same. A literal is a constant, but a constant is not
a literal.

Constants, as the name implies, never change their value which makes development changes easy and eliminates the use of
"magic numbers".

### How to declare a constant

There are two ways to declare a constant:

```c
#define identifierName value
const type identifierName value;
```

- The `identifierName` is the constant, while the `value` is the literal.
- The first way is very efficient for an embedded system, as it does not consume any memory in the microcontroller. Using the `#define`, you declare a text substitution label, which means that each instance of `identifierName` will be replaced with value by the preprocessor unless `identifierName` is inside a string.
- A `#define` is *never* terminated with a `';'`, unless you want that semicolon to be part of the substitution.
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

C does not have a string type. One way to store strings in C is to use arrays of characters. Later, we will learn how
to use pointers to define strings.

When strings are declared as character arrays, they are stored like other types of arrays in C. If you declare the
string without a dimension, the null character is automatically appended to the end of the string:

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

Use escape sequences to include special characters in strings, just like any other ordinary character. The backslash
`\` plus the following character is considered as a single character with a single ASCII value.

| Escape sequence | Meaning |
|:---:|:---:|
| `\a`  | alert (beep) |
| `\\`  | backslash |
| `\b`  | backspace |
| `\r`  | carriage return |
| `\"`  | double quote |
| `\f`  | formfeed |
| `\t`  | horizontal tab |
| `\n`  | newline |
| `\0`  | null character |
| `\'`  | single quote |
| `\v`  | vertical tab |
| `\?`  | question mark |

**Code example**

```c
char salutation[] = "Dear Paul,\n";
```

In order to nest strings, you need to escape the double quotes:

```c
"printf (\"hello world!\n\")"
```
