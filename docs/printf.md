# The printf() C library function

One of the most commonly used C library function is the `printf()` function which allows to write text to the "standard
output" (normally a monitor or line printer). In embedded systems, often a UART is used. In Arm Cortex-M based systems
you can redirect the standard output to the ITM debug channel which saves resources (the UART) and is much faster.

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

!!! Note
    - `%d` is the *conversion character*.
    - `\n` is a *special character*.

### Conversion characters

| Conversion character | Description |
|:---:|:---|
| `%c` | Single character|
| `%s` | String (all characters until `\0`)|
| `%d` | Signed decimal number |
| `%#` | A `0x` should precede a hexadecimal number|
| `%u` | Unsigned decimal number |
| `%o` | Unsigned octal number |
| `%x` | Unsigned hexadecimal number with lowercase digits (`1a4e`)|
| `%X` | As x, but with uppercase digits (`1A4E`)|
| `%f` | Signed decimal value (floating point)|
| `%e` | Signed decimal with exponent (`1.13e-4`)|
| `%E` | As e, but uses E for exponent (`1.13E-4`)|
| `%g` | As e or f, but depends on size and precision of value|
| `%G` | As g, but uses E for exponent|

!!! Note
    The optional characters `l` or `L` may immediately precede the type character to respectively specify long versions
    of the integer types `d`, `i`, `u`, `o`, `x`, and `X`.

### Special characters

Special characters (also called escape sequences) are used to display non-printing or hard-to-print characters. These
characters control how text is positioned in the output. We have seen the `\n` example for a *newline*.

A list of escape sequences can be found in the chapter [Constants and literals](constants.md#string-literals)

!!! Note
    Escape sequences and words are often joined together in the ControlString (see the example above: `\nm`). This
    looks a bit strange, but follows a general logic. If you'd add a *space* between the two, you would start the
    *newline* with a space as well.
