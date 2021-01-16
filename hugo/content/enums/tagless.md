---
title: "Tagless enumeration variable"
weight: 3
---

If you omit the tape name, you can only have variables of that type that are specified as part of the `enum` declaration. Later, you cannot specify any additional variable of the `enum` type.  

**Code example**

```c
enum {JAN, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC} current_month;
```