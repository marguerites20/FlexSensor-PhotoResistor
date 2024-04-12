#ifndef __AVR_ATmega328P__
#define __AVR_ATmega328P__
#endif

#include "IO_Macros.h" // Include the IO macros file

#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>

#define ANALOG_IN_PIN PINC0   // Define the analog input pin (PC0)
#define ANALOG_OUT_PIN PIND3   // Define the analog output pin (PD3)

// Function to initialize ADC
void initADC() {
    // Set reference voltage to AVCC (Arduino: analogReference(DEFAULT);)
    BitSet(ADMUX, REFS0);
    // Enable ADC and set prescaler to 128 (Arduino: analogReadResolution(10);)
    BitSet(ADCSRA, ADEN);
    BitSet(ADCSRA, ADPS2);
    BitSet(ADCSRA, ADPS1);
    BitSet(ADCSRA, ADPS0);
}

// Function to read analog input
int analogRead(int pin) {
    // Select ADC channel (Arduino: analogRead(pin);)
    ADMUX = (ADMUX & 0xF0) | (pin & 0x0F);
    // Start conversion (Arduino: analogRead(pin);)
    BitSet(ADCSRA, ADSC);
    // Wait for conversion to complete (Arduino: analogRead(pin);)
    while (BitCheck(ADCSRA, ADSC));
    // Return ADC value (Arduino: analogRead(pin);)
    return ADC;
}

// Function to initialize PWM
void initPWM() {
    // Set PWM pin as output (Arduino: pinMode(pin, OUTPUT);)
    BitSet(DDRD, ANALOG_OUT_PIN);
    // Set timer1 to Fast PWM mode, non-inverting (Arduino: analogWrite(pin, value);)
    BitSet(TCCR1A, COM1A1);
    BitSet(TCCR1A, WGM11);
    BitSet(TCCR1A, WGM10);
    BitSet(TCCR1B, WGM12);
    BitSet(TCCR1B, CS11); // Prescaler 8
    // Set PWM frequency (around 500 Hz) (Arduino: analogWriteFrequency(pin, frequency);)
    ICR1 = 625;
}

// Function to write analog output
void analogWrite(int pin, int value) {
    // Set PWM duty cycle (Arduino: analogWrite(pin, value);)
    OCR1A = value;
}

int main() {
    // Setup
    initADC();  // Initialize ADC
    initPWM();  // Initialize PWM

    // Loop
    while (1) {
        // Read analog input (Arduino: analogRead(pin);)
        int sensorValue = analogRead(ANALOG_IN_PIN);
        // Map the analog input value (Arduino: map(value, fromLow, fromHigh, toLow, toHigh);)
        int outputValue = map(sensorValue, 0, 1023, 255, 0);
        // Write analog output (Arduino: analogWrite(pin, value);)
        analogWrite(ANALOG_OUT_PIN, outputValue);
        // Delay (Arduino: delay(ms);)
        _delay_ms(100);
    }

    return 0;
}


