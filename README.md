# Embedded C for Arm Cortex-M based microcontrollers

This reference manual outlines basic C language principles, with specifics around the usage in Arm Cortex-M based microcontrollers. It contains a documentation that can be accessed via a web browser and directly from within Arm Keil MDK (using the **::Utils:embedded_c** component's documentation link). The CMSIS-Pack also contains a couple of example projects that help to understand the concepts outlined in the manual.

## Directory Structure

| Directory          | Content                                             |
|:-------------------|:----------------------------------------------------|
| docs               | Embedded C for Arm Cortex-M in Markdown format      |
| docs/img           | Images used in the documentation                    |
| projects           | Arm Keil MDK example projects                       |
| pack               | Contains the pre-built CMSIS-Pack and PDSC file     |

## Required Software
- mkdocs (> Version 1.0)
- CMSIS Pack
- xmllint

## Build
To build the pack, run the [gen_pack.sh](gen_pack.sh) script.

## License
[![License](https://img.shields.io/badge/License-Apache%202.0-blue.svg)](https://opensource.org/licenses/Apache-2.0)