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

If both operands are of an integer type, the result will be an integer type as well (valid for `int` and `char`).

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

There are two types of assignment operators available:

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

- Do not interchange `=` with `==`. `=` is the assignment operator, while `==` is the "equals to" relational operator.

**Code example**
```c
int n, m;

n = 3;         // assign the value 3 to a

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

- This will become important when talking about arrays, pointers, structs, and unions later.

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

c = (a % 2 != 0) ? a : b; // conditionally assigns a value to c
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

|Precedence | Operator       | Description | Associativity |
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
|15        | `,`            | Comma | Left-to-right |

### Precedence

When expressions contain multiple operators, their precedence determines the order of evaluation.

| Expression    | Expression with precedence |
|:-------------:|:--------------------------:|
| `a – b * c`   | `a – (b * c)`              |
| `a + ++b`     | `a + (++b)`                |
| `a + ++b * c` | `a + ((++b) * c)`          |

*Note*

- If functions are part of an expression, there is no way to tell which function is evaluated first. 

### Associativity

For two operators with the same precedence, the associativity determines the order of the evaluation of the expression.

| Expression  | Associativity | Expression with precedence |
|:-----------:|:--------------|:--------------------------:|
| `x / y % z` | Left-to-Right | `(x / y) % z`              |
| `x = y = z` | Right-to-Left | `x = (y = z)`              |
| `~++x`      | Right-to-Left | `~(++x)`                   |

Although these rules are always applied, it is good practice to explicitly group the elements of an expression using `()`.
