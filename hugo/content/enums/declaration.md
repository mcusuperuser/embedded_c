---
title: "Enumeration declaration"
weight: 1
---

Enumerations:
- Are unique integer data types
- May only contain a specified list of values
- Values are specified as symbolic constants

**Syntax**

```c
enum typeName { label0, label1, ..., labeln }
```

{{% notice note %}}
The compiler sets label0 = 0, label1 = 1, labeln = n.
{{% /notice %}}

**Code example**

```c
enum month {JAN, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC};
```

{{% notice note %}}
You can assign a specific value to any label.  
Subsequent labels will increment from that value.
{{% /notice %}}

**Code example**

```c
enum group {Peter, Paul = 5, Mary};
// label values: Peter = 0, Paul = 5, Mary = 6
```
