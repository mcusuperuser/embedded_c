---
title: "Register variables"
date: 2020-12-23T22:28:48+01:00
weight: 5
---

This storage class declares `register` variables which have the same functionality as `auto` variables. The only difference is that the Arm compiler v5 tries to store these variables in a register of the Arm Cortex-M core if a free register is available. This accelerates the access to the `register` variables. Arm compiler v6 ignores this keyword.