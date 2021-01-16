---
title: "Introduction"
date: 2020-12-23T22:19:42+01:00
weight: 1
---

Functions provide a way to modularize code and make it easier to maintain. Also, functions promote code reuse.

{{% notice note %}}
All C programs have one (at least the `main()` function is required) or more functions.  
Functions can accept parameters from the code that calls them.  
Functions usually return a single value.  
Functions help to organize a program into logical, manageable segments.
{{% /notice %}}

**Syntax**

```c
type identifier (type1 arg1, type2 arg2, ..., typen argn) {
    declarations        // body
    statements          // body
    return expression;  // body
}
```

Where:

- `type` is the data type of the return expression.
- `identifier` is the name of the function.
- `type1 arg1, type2 arg2, ..., typen argn` is the parameter list which is optional.
- `expression` is the (optional) return value.
- the body is also optional. 