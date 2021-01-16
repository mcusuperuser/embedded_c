---
title: "Return data type"
date: 2020-12-23T22:17:13+01:00
weight: 2
---

- A function's `type` must match the type of data in the return `expression`.
- A function may have multiple return statements (of the same type), but only one will be executed.
- The function type is `void` if the `return` statement has no `expression` or is not present at all. This is also known as a procedure function, since nothing is returned.
- Functions can return any type except arrays and functions. We can get around this limitation by returning a pointer to an array or a pointer to a function.