# ECG-Data-Acquisition

## Description

An Arduino-based ECG Data Acquisition System programmed in C++ using register-level (low-level) programming. The system employs an interrupt-driven design, sampling electrocardiogram (ECG) signals at a fixed rate of 100 Hz by configuring Timer1 and the ADC directly at the hardware register level. Each sample is automatically handled in interrupt service routines, converted into a 10-bit digital value (0-1023), and streamed over the serial port for visualization or further analysis.

## Requirements

Hardware
1.	Arduino UNO (or compatible ATmega328P board)
2.	ECG electrodes
3.	Instrumentation amplifier (e.g. AD623)
4.	Operational amplifiers (e.g. MCP604)
5.	Passive components (resistors, capacitors)
6.	Breadboards and jumper wires

Software
1.	Arduino IDE
2.	Arduino Serial Monitor and Serial Plotter

## Circuit Specifications

Circuit Diagram







