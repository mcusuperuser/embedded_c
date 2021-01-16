---
title: "Memory addressing/member access"
weight: 7
---

Member access operators allow access to the members of their operands.

| Operator | Operation                     | Example  | Result |
|:--------:|:------------------------------|:--------:|--------|
| `[]`     | Array subscript               | `a[b]`   | access the `b`th element of array `a`
| `*`      | Pointer dereference           | `*a`     | The object or function `a` points to
| `&`      | Address of                    | `&a`     | Pointer to `a`
| `.`      | Member access (struct/union)  | `a.b`    | The member `b` of struct or union `a`
| `->`     | Member access through pointer | `a->b`   | The member `b` of struct or union pointed to by `a`

{{% notice note %}}
This will become important when talking about arrays, pointers, structs, and unions later.
{{% /notice %}}
