# Peripheral access using CMSIS

CMSIS defines naming conventions, requirements, and optional features for accessing device specific peripherals (including core peripherals). Typically, the device header file `<device.h>` contains these definitions and also includes the core specific header files.

Each peripheral provides a data type definition with a name that is composed of:
- an optional prefix `<device abbreviation>_`
- `<peripheral name>`
- postfix `_Type` or `_TypeDef` to identify a type definition.

## Accessing peripherals

To access the peripheral registers and related function in a device, the files `device.h` and `core_cm#.h` define as a minimum:

1. The **register layout typedef** for each peripheral that defines all register names. RESERVED is used to introduce space into the structure for adjusting the addresses of the peripheral registers.

**Code example**
```c
typedef struct
{
  __IM  uint32_t CPUID;                  /*!< Offset: 0x000 (R/ )  CPUID Base Register */
  __IOM uint32_t ICSR;                   /*!< Offset: 0x004 (R/W)  Interrupt Control and State Register */
  __IOM uint32_t VTOR;                   /*!< Offset: 0x008 (R/W)  Vector Table Offset Register */
  __IOM uint32_t AIRCR;                  /*!< Offset: 0x00C (R/W)  Application Interrupt and Reset Control Register */
  __IOM uint32_t SCR;                    /*!< Offset: 0x010 (R/W)  System Control Register */
  __IOM uint32_t CCR;                    /*!< Offset: 0x014 (R/W)  Configuration Control Register */
  __IOM uint8_t  SHP[12U];               /*!< Offset: 0x018 (R/W)  System Handlers Priority Registers (4-7, 8-11, 12-15) */
  __IOM uint32_t SHCSR;                  /*!< Offset: 0x024 (R/W)  System Handler Control and State Register */
  __IOM uint32_t CFSR;                   /*!< Offset: 0x028 (R/W)  Configurable Fault Status Register */
  __IOM uint32_t HFSR;                   /*!< Offset: 0x02C (R/W)  HardFault Status Register */
  __IOM uint32_t DFSR;                   /*!< Offset: 0x030 (R/W)  Debug Fault Status Register */
  __IOM uint32_t MMFAR;                  /*!< Offset: 0x034 (R/W)  MemManage Fault Address Register */
  __IOM uint32_t BFAR;                   /*!< Offset: 0x038 (R/W)  BusFault Address Register */
  __IOM uint32_t AFSR;                   /*!< Offset: 0x03C (R/W)  Auxiliary Fault Status Register */
  __IM  uint32_t PFR[2U];                /*!< Offset: 0x040 (R/ )  Processor Feature Register */
  __IM  uint32_t DFR;                    /*!< Offset: 0x048 (R/ )  Debug Feature Register */
  __IM  uint32_t ADR;                    /*!< Offset: 0x04C (R/ )  Auxiliary Feature Register */
  __IM  uint32_t MMFR[4U];               /*!< Offset: 0x050 (R/ )  Memory Model Feature Register */
  __IM  uint32_t ISAR[5U];               /*!< Offset: 0x060 (R/ )  Instruction Set Attributes Register */
        uint32_t RESERVED0[5U];
  __IOM uint32_t CPACR;                  /*!< Offset: 0x088 (R/W)  Coprocessor Access Control Register */
} SCB_Type;
```

*Note*

- IO Type Qualifiers are used to specify the access to peripheral variables:

|IO Type Qualifier 	|Type 	|Description|
|:-:|-|-|
|__IM 	|Struct member 	|Defines 'read only' permissions
|__OM 	|Struct member 	|Defines 'write only' permissions
|__IOM 	|Struct member 	|Defines 'read / write' permissions
|__I 	|Scalar variable| 	Defines 'read only' permissions
|__O 	|Scalar variable| 	Defines 'write only' permissions
|__IO 	|Scalar variable| 	Defines 'read / write' permissions

2. The **base address** for each peripheral (in case of multiple peripherals that use the same register layout typedef multiple base addresses are defined).

**Code example**
```c
#define SCS_BASE (0xE000E000UL) // System Control Space Base Address
```

3. **Access definitions** for each peripheral. In case of multiple peripherals that are using the same register layout typedef, multiple access definitions exist (UART0, UART2).

**Code example**
```c
#define SCB  ((SCB_Type *) SCB_BASE) // SCB configuration struct
```

These definitions allow accessing peripheral registers with simple assignments.

**Code example**
```c
SCB->SCR = 0;
```

4. For core registers, macros define the position and the mask value for a bit field. Such definitions are often also created for other peripheral registers.

**Code example**
```c
/* SCB Interrupt Control State Register Definitions */
#define SCB_ICSR_NMIPENDSET_Pos  31U // SCB ICSR: NMIPENDSET Position 
#define SCB_ICSR_NMIPENDSET_Msk  (1UL << SCB_ICSR_NMIPENDSET_Pos) // SCB ICSR: NMIPENDSET Mask 
#define SCB_ICSR_PENDSVSET_Pos   28U // SCB ICSR: PENDSVSET Position 
#define SCB_ICSR_PENDSVSET_Msk   (1UL << SCB_ICSR_PENDSVSET_Pos)  // SCB ICSR: PENDSVSET Mask 
#define SCB_ICSR_PENDSVCLR_Pos   27U // SCB ICSR: PENDSVCLR Position 
#define SCB_ICSR_PENDSVCLR_Msk   (1UL << SCB_ICSR_PENDSVCLR_Pos)  // SCB ICSR: PENDSVCLR Mask 
#define SCB_ICSR_PENDSTSET_Pos   26U // SCB ICSR: PENDSTSET Position 
#define SCB_ICSR_PENDSTSET_Msk   (1UL << SCB_ICSR_PENDSTSET_Pos)  // SCB ICSR: PENDSTSET Mask 
#define SCB_ICSR_PENDSTCLR_Pos   25U // SCB ICSR: PENDSTCLR Position 
#define SCB_ICSR_PENDSTCLR_Msk   (1UL << SCB_ICSR_PENDSTCLR_Pos)  // SCB ICSR: PENDSTCLR Mask 
#define SCB_ICSR_ISRPREEMPT_Pos  23U // SCB ICSR: ISRPREEMPT Position 
#define SCB_ICSR_ISRPREEMPT_Msk  (1UL << SCB_ICSR_ISRPREEMPT_Pos)  // SCB ICSR: ISRPREEMPT Mask 
#define SCB_ICSR_ISRPENDING_Pos  22U // SCB ICSR: ISRPENDING Position 
#define SCB_ICSR_ISRPENDING_Msk  (1UL << SCB_ICSR_ISRPENDING_Pos) // SCB ICSR: ISRPENDING Mask 
#define SCB_ICSR_VECTPENDING_Pos 12U // SCB ICSR: VECTPENDING Position 
#define SCB_ICSR_VECTPENDING_Msk (0x1FFUL << SCB_ICSR_VECTPENDING_Pos) // SCB ICSR: VECTPENDING Mask 
#define SCB_ICSR_RETTOBASE_Pos   11U // SCB ICSR: RETTOBASE Position 
#define SCB_ICSR_RETTOBASE_Msk   (1UL << SCB_ICSR_RETTOBASE_Pos)  // SCB ICSR: RETTOBASE Mask 
#define SCB_ICSR_VECTACTIVE_Pos  0U  // SCB ICSR: VECTACTIVE Position 
#define SCB_ICSR_VECTACTIVE_Msk  (0x1FFUL << SCB_ICSR_VECTACTIVE_Pos)  // SCB ICSR: VECTACTIVE Mask 
```

## Reading, modifying, and writing bit fields in registers

- How do we find the current value of the ICSR ISRPREEMPT bit? We read the  register SCB, AND it (using &) with the mask, and then shift it right (using >>) by the shift value:

**Code example**
```c
id = (SCB->ICSR & SCB_ICSR_ISRPREEMPT_Msk) >> SCB_ICSR_ISRPREEMPT_Pos;
```

- How do we set fields NMIPENDSET and PENDSVSET in that register, leaving everything else as zero? We use the = assignment operator:

**Code example**
```c
SCB->ICSR = SCB_ICSR_NMIPENDSET_Msk | SCB_ICSR_PENDSVSET_Msk;
```

- How do we set fields NMIPENDSET and PENDSVSET in that register without modifying anything else? We need to perform a read/modify/write operation with the OR read/modify/write operator |=:

**Code example**
```c
SCB->ICSR |= SCB_ICSR_NMIPENDSET_Msk | SCB_ICSR_PENDSVSET_Msk;
```

- How do we clear field NMIPENDSET in that register without modifying anything else? We need to perform a read/modify/write operation, while zeroing out the bit for NMIPENDSET. We do this by first complementing the mask for NMIPENDSET using the ~ operator. This flips all of its ones to zeros and zeros to ones. Using the AND read/modify/write operator &= will zero out the control register’s bits for NMIPENDSET’s field:

**Code example**
```c
SCB->ICSR &= SCB_ICSR_NMIPENDSET_Msk;
```

## Alternative mechanism

Using the CMSIS macros `_VAL2FLD(field, value)` and `_FLD2VAL(field, value)` you can access bit fields more easily.

**Code example**
```c
id = _FLD2VAL(SCB_CPUID_REVISION, SCB->CPUID); // uses the #define's _Pos and _Msk of the related bit field to extract the value of a bit field from a register.

SCB->CPUID = _VAL2FLD(SCB_CPUID_REVISION, 0x3) | _VAL2FLD(SCB_CPUID_VARIANT, 0x3); // uses the #define's _Pos and _Msk of the related bit field to shift bit-field values for assigning to a register.
```
