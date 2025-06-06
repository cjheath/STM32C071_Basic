# STM32C071_Basic

A template project for STM32 projects using the STM32C071 32-pin QFP, with USB and SWD.
![3D view](https://github.com/cjheath/STM32C071_Basic/blob/main/Hardware/STM32C071_Basic.3D.png)

## Goals and Status

This project provides a self-contained quick-start for projects
which require an easy-to-use USB-based micro-controller with Single-Wire-Debug (SWD),
such as for small test PCBs to evaluate new integrated circuit chips
that need configuration via SPI, I2C or UART
before integrating those chips into larger designs.

The following aspects are (to be) provided:

* Configuration
  - STM32CubeMX pin-configuration file you should edit for your required I/O configuration
* Hardware
  - KiCad schematic and 2-layer PCB containing the STM32, USB and SWD connectors
  - 3.3V Buck switcher from VBUS up to 20V (in case you use USB-PD)
  - KiCad project-local library of symbols, footprints and 3D models
  - LCSC ordering codes on all parts, to facilitate ordering on JLCPCB
* Firmware (incomplete)
  - Chip initialisation and peripheral setup firmware (NOT using the CubeMX-generated HAL code)
  - Basic USB device initialisation as a USB CDC-ish (USB serial) to support remote-control protocols
  - A Makefile for the firmware
* Host software (not started)
  - A simple command-line program for you to extend to add configuration commands

This template is still incomplete. Use at own risk

## How to use this template

View the README file in the Hardare directory. You may explore alternative MCU pin configurations
using either Kicad or by opening Configuration/STM32C071_Basic.ioc using STM32CubeMX.
