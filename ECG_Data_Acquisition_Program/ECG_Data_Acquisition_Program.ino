#include <avr/io.h>
#include <avr/interrupt.h>

// Functions
static inline void initTimer(void) {
  // Initialize Timer 1 for 100 Hz sampling rate
  TCNT1 = 65380;    // Preload timer for ~10ms overflow (65536 - 16MHz/1024/100Hz)
  TCCR1B |= (1 << CS12) | (1 << CS10);    // Set prescaler to 1024
  TIMSK1 |= (1 << TOIE1);    // Enable timer overflow interrupt
}

static inline void initADC(void) {
  // Initialize the ADC
  ADMUX |= (1 << REFS0);    // Set reference voltage to AVcc (5V)
  ADCSRA |= (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);    // Set ADC prescaler to 128
  ADCSRA |= (1 << ADEN);    // Enable the ADC
  ADCSRA |= (1 << ADIE);    // Enable ADC interrupt
}

// Interrupt Service Routine for Timer 1 Overflow
ISR(TIMER1_OVF_vect) {
  // Reload Timer 1 for the next interval
  TCNT1 = 65380;    // Preload for ~10 ms interval (100 Hz)

  // Start ADC conversion
  ADCSRA |= (1 << ADSC);
}

// Interrupt Service Routine for ADC Conversion Complete
ISR(ADC_vect) {
  uint16_t adcValue = ADC;    // Read the ADC value
  // Transmit the ADC value via serial
  Serial.println(adcValue);
}

int main(void) {
  noInterrupts();    // Disable global interrupts
  initIOPorts();    // Initialize GPIO ports (if needed)
  initTimer();    // Initialize Timer 1
  initADC();    // Initialize ADC
  interrupts();    // Enable global interrupts

  Serial.begin(9600);    // Start serial communication

// Main loop remains empty as everything is handled by interrupts
  while (1) {

  }
  return 0;
}
