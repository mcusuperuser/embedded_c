---
title: "Passing structures to functions"
weight: 11
---

**Code example**

```c
// structure type to handle color values
typedef struct {
    int red;
    int green;
    int blue;
} rgb;

void show_rgb (rgb n) {
    printf("(%d, %d, %d)\n", n.reg, n.green, n.blue);
}

int main (void) {
    rgb a = {0, 145, 198};
    rgb b = {0, 255, 255};

    show_rgb (a);
    show_rgb (b);
}
```