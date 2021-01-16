---
title: "Identifiers"
date: 2020-12-23T16:41:55+01:00
weight: 2
---

- Valid characters in identifiers are '_', 'a' to 'z', 'A' to 'Z', and '0' to '9' (not allowed for the first character).
- Identifiers are case sensitive, so `myVar` is not the same as `myvar`!
- You *must not use* keywords of the C language as identifiers.
- The Arm compiler provides additional keywords that are extensions to the C/C++ standards and *must also not be used* as identifiers.

### ANSI C keywords

| | | | | |
|---|---|---|---|---|
| auto | break | case | char | const |
| continue | default | do | double | else |
| enum | extern | float | for | goto |
| if | int | long | register | return |
| short | signed | sizeof | static | struct |
| switch | typedef | union | unsigned | void |
| volatile | while ||||

### Arm compiler 5 keywords and operators

| | | |
|---|---|---|
| __align | __int64 | __svc |
| \_\_ALIGNOF\_\_ | \_\_INTADDR\_\_ | __svc_indirect |
| __asm | __irq | __svc_indirect_r7 |
| __declspec | __packed | __value_in_regs |
| __forceinline | __pure | __weak |
| __global_reg | __softfp | __writeonly |
| __inline | __smc ||

### Arm compiler 6 (armclang) keywords and operators

| | | | |
|---|---|---|---|
| \_\_alignof\_\_ | \_\_asm | \_\_declspec | \_\_inline |
