---
title: "How to use printf()"
weight: 1
---

**Syntax**

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

{{% notice note %}}
`%d` is the *conversion character*.  
`\n` is a *special character*.
{{% /notice %}}

See next section for a list of conversion characters.