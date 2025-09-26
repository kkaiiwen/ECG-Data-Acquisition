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

<p align="center">
  <kbd>
    <img width="660" src="https://github.com/kkaiiwen/ECG-Data-Acquisition/raw/main/ECG Circuit Diagram.jpg">
  </kbd>
</p>
<p align="center">
    <text> Figure 1: ECG Circuit Diagram </text>
</p>

| Component                          | Function                                                                                                                                                                                                 |
|------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| Instrumentation Amplifier           | Amplifies ECG signals with a high signal-to-noise ratio (SNR). Gain is set to 3.13. The high common-mode rejection ratio (CMRR) suppresses common-mode interference, such as mains power noise.          |
| Potential Divider                   | Generates a 2.5 V virtual ground used as the circuit reference and to bias the body, allowing the ECG signal to remain within the op-amp’s operating range.                                            |
| Passive High-Pass Filter            | Removes DC offset and low-frequency drift, such as baseline wander from breathing or electrode movement. Cutoff frequency: 0.48 Hz.                                                                    |
| Second-Order Passive Low-Pass Filter| Attenuates high-frequency noise and muscle artifacts while preserving the ECG frequency band. Cutoff frequency: 48 Hz. Two cascaded stages provide a steeper roll-off.                                 |
| Voltage Buffer                      | Provides unity gain with high input impedance and low output impedance. Buffers isolate circuit stages, prevent loading effects, and ensure stable signal transfer.                                     |
| Non-Inverting Amplifier             | Provides additional gain while ensuring the ECG signal stays within the Arduino’s 0-5 V ADC input range. Gain is set to 2201.                                                                          |

## Usage

1.	Place electrodes on the left arm, right arm, and the reference electrode on the right leg.
2.	Connect the Arduino UNO to your PC.
3.	Upload the ECG Data Acquisition Programme to the Arduino.
4.	Open the Arduino Serial Monitor at 9600 baud.
5.	The Arduino samples the ECG signal at 100 Hz using Timer1 interrupt, then the ADC interrupt converts each sample to a 10-bit value (0-1023) and transmits it over the serial port.
6.	Use the Arduino Serial Plotter or external tools to display the ECG waveform in real time.

