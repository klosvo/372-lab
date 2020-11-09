
#include "PWM.h"

void initPWM(){

    // PWM frequency calculation for FAST PWM mode on page 148 of datasheet
    // frequency of PWM = (F_clk)/((Prescaler)* (1 +TOP))
    // frequency of PWM = 16Mhz
    // Prescaler = 1
    // TOP value = 03ff = 1023
    // PWM frequency from calculation = 15.625 kHz

    //-----FOR TIMER 3-----//

    // set Fast PWM 10-bit mode, non-inverting
    // Use Timer 3 

    // initalize pin as output 
    DDRE |= (1 << DDE3); //pin 5 for timer 3

    // Fast PWM 10-bit mode from Table 17-2
    TCCR3A |= (1 << WGM31) | (1 << WGM30);
    TCCR3B |= (1 << WGM32);
    TCCR3B &= ~(1 << WGM33);

   // Noninverting, from Table 17-4
    TCCR3A |= (1 << COM3A1);
    TCCR3A &= ~(1 << COM3A0);

   


    // Clock Prescaler set to 1 from Table 17-6
    TCCR3B |= (1 << CS30);
    TCCR3B &= ~((1 << CS31) | (1 << CS32));

    //-----FOR TIMER 4-----//

    // set Fast PWM 10-bit mode, non-inverting
    // Use Timer 4 

    // initalize pin as output 
    DDRH |= (1 << DDH3); //pin 6 for timer 4

    // Fast PWM 10-bit mode from Table 17-2
    TCCR4A |= (1 << WGM41) | (1 << WGM40);
    TCCR4B |= (1 << WGM42);
    TCCR4B &= ~(1 << WGM43);

   // Noninverting, from Table 17-4
    TCCR4A |= (1 << COM3A1);
    TCCR4A &= ~(1 << COM3A0);


    // Clock Prescaler set to 1 from Table 17-6
    TCCR4B |= (1 << CS40);
    TCCR4B &= ~((1 << CS41) | (1 << CS42));
}

//Set motor speed and direction with count registers using information obtained by ADC 
void SetMOTORspeed(double result) {
    // the last thing is to set the duty cycle.     
    // duty cycle is set by dividing output compare OCR4A value by 1 + TOP value
    // the top value is (1 + 0x3FF) = 1024
    // calculate OCR4A value => OCR4A = duty cycle(fractional number) * (1 + TOP) 
    // we want a duty cycle varies based on voltage variable result
    // OCR1A = 0.60 * 1024


 //convert result into a voltage for this to not change


    if(result < 2.3){
        // set duty cycle
        // Tpulse/Tperiod = OCRnx/TOP
        // duty cycle varies based on voltage variable result
        // 0x3FF/4

        OCR3A = result * 0x400;
        OCR4A = 0;

    }else if (result > 2.7){
        // set duty cycle
        // Tpulse/Tperiod = OCRnx/TOP
        // duty cycle of 25%
        // 0x3FF/4
        OCR4A = result * 0x400;
        OCR3A = 0;
    } else{
         OCR3A = 0;
         OCR4A = 0;
    }

}
