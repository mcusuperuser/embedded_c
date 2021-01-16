---
title: "Declaration of enumeration type variable"
weight: 2
---

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