# Enumerations

What are enumerations?

!!! Important
    Enumerations are user defined data types (with a limited range of values).

Enumerations:

- Are unique integer data types
- May only contain a specified list of values
- Values are specified as symbolic constants

## Enumeration declaration

**Syntax**

```c
enum typeName { label0, label1, ..., labeln }
```

!!! Note
    The compiler sets `label0 = 0`, `label1 = 1`, `labeln = n`

**Code example**

```c
enum month {JAN, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC};
```

!!! Note
    - You can assign a specific value to any label
    - Subsequent labels will increment from that value

**Code example**

```c
enum group {Peter, Paul = 5, Mary};
// label values: Peter = 0, Paul = 5, Mary = 6
```

## Declaration of enumeration tape variable

**Declared along with type**

```c
enum typeName { list_of_constants } variable_name1, ...;
```

**Declared independently**

```c
enum typeName variable_name1, ...;
```

**Code example**

```c
enum month {JAN, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC} current_month;

enum month current_month;
```

## Tagless enumeration variable

If you omit the tape name, you can only have variables of that type that are specified as part of the `enum`
declaration. Later, you cannot specify any additional variable of the `enum` type.  

**Code example**

```c
enum {JAN, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC} current_month;
```

## Declare an enumeration type with `typedef`

As always, variables can be declared as type `typeName` without requiring the keyword `enum`:

**Syntax**

```c
typedef enum {list_of_constants} typeName;
```

The enumeration can now be used as an ordinary data type, such as int or float.

**Code example**

```c
typedef enum {JAN, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC} month;
month current_month; // Variable of type month
```

## Using an enumeration type variable

If the enumeration and the variable have already been defined:

**Syntax**

```c
varName = labeln;
```

!!! Note
    - Use the labels just like any other symbolic constant
    - Enumeration type variables must only use the type’s labels or equivalent integer

**Code example**

```c
enum color {red, green, blue};
enum color myCar;

myCar = red;
myCar = 3;

if (myCar == 2) {
    // do something
}
```
