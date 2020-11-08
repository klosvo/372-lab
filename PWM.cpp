
#include "PWM.h"
// initalize pin as output 

// set Fast PWM 10-bit mode, non-inverting
// Use Timer 3 

void initPWMTimer3(){

    DDRB |= (1 << DDB5); //pin 11 for timer 1 - FIXME

    // Fast PWM 15-bit mode FIX ME TO 10 BIT MODE
    TCCR1A |= (1 << COM1A1) | (1 << WGM11) | (1 << WGM10);
    TCCR1A &= ~(1 << WGM13);

    //should add 0 bits as well.
    // Fast PWM mode, 10-bit, Clock Prescaler set to 1
    TCCR1B |= (1 << WGM12) | (1 << CS10);


    // set duty cycle
    // Tpulse/Tperiod = OCRnx/TOP
    // duty cycle of 25%
    OCR1A = 255;

}

//initalize pin as output

// set Fast PWM 10-bit mode, inverting
// Use Timer 4 for 

void initPWM()
{
    // THIS IS IN 15 BIT MODE, NEED TO CHANGE
    TCCR4A |= (1 << WGM40) | (1 << WGM41);
    TCCR4B |= (1 << WGM42) | (1 << WGM43);

    // FIX ME THIS IS NONINVERTING
    TCCR4A &= ~(1 << COM4C0);
    TCCR4A |= (1 << COM4C1);

    // PRESCALER 1
    TCCR4B |= (1 << CS40);
    DDRH |= (1 << DDH5);
}

//Set motor speed and direction with count registers using information obtained by ADC 
void SetMOTORspeed(int result) {


}
