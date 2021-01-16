---
title: "Nested structures"
weight: 6
---

Using the `typedef` structure declaration, you can nest one structure within another structure.

**Code example**

```c
// declare struct type for a single point
typedef struct {
    float x;
    float y;
} point;

// declare a struct type for a line with a start and end point
typedef struct {
    point start;
    point end;
} line;

int main(void) {
    line l;

    l.start.x = 3.5;
    l.start.y = 8.4;
    l.end.x = 12.7;
    l.end.y = 18.5;
    ...
}
```