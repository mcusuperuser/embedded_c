---
title: "Operator precedence"
weight: 9
---

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

## Precedence

When expressions contain multiple operators, their precedence determines the order of evaluation.

| Expression    | Expression with precedence |
|:-------------:|:--------------------------:|
| `a – b * c`   | `a – (b * c)`              |
| `a + ++b`     | `a + (++b)`                |
| `a + ++b * c` | `a + ((++b) * c)`          |

{{% notice note %}}
If functions are part of an expression, there is no way to tell which function is evaluated first. 
{{% /notice %}}

## Associativity

For two operators with the same precedence, the associativity determines the order of the evaluation of the expression.

| Expression  | Associativity | Expression with precedence |
|:-----------:|:--------------|:--------------------------:|
| `x / y % z` | Left-to-Right | `(x / y) % z`              |
| `x = y = z` | Right-to-Left | `x = (y = z)`              |
| `~++x`      | Right-to-Left | `~(++x)`                   |

Although these rules are always applied, it is good practice to explicitly group the elements of an expression using `()`.
