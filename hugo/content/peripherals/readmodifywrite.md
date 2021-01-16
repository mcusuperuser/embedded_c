---
title: "Reading, modifying, and writing bit fields in registers"
weight: 2
---

How do we find the current value of the ICSR ISRPREEMPT bit? We read the  register SCB, AND it (using &) with the mask, and then shift it right (using >>) by the shift value:

**Code example**

```c
id = (SCB->ICSR & SCB_ICSR_ISRPREEMPT_Msk) >> SCB_ICSR_ISRPREEMPT_Pos;
```

How do we set fields NMIPENDSET and PENDSVSET in that register, leaving everything else as zero? We use the = assignment operator:

**Code example**

```c
SCB->ICSR = SCB_ICSR_NMIPENDSET_Msk | SCB_ICSR_PENDSVSET_Msk;
```

How do we set fields NMIPENDSET and PENDSVSET in that register without modifying anything else? We need to perform a read/modify/write operation with the OR read/modify/write operator |=:

**Code example**

```c
SCB->ICSR |= SCB_ICSR_NMIPENDSET_Msk | SCB_ICSR_PENDSVSET_Msk;
```

How do we clear field NMIPENDSET in that register without modifying anything else? We need to perform a read/modify/write operation, while zeroing out the bit for NMIPENDSET. We do this by first complementing the mask for NMIPENDSET using the ~ operator. This flips all of its ones to zeros and zeros to ones. Using the AND read/modify/write operator &= will zero out the control register’s bits for NMIPENDSET’s field:

**Code example**

```c
SCB->ICSR &= SCB_ICSR_NMIPENDSET_Msk;
```