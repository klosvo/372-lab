

#include "timer.h"

/* Initialize timer 0, you should not turn the timer on here.
* You will need to use CTC mode */
void initTimer0(){
TCCR0A &= ~(1 << WGM00); // Set timer to be in CTC mode (Page 128 on Data Sheet)
TCCR0A |= (1 << WGM01);
TCCR0B &= ~(1 << WGM02);
TCCR0B |= (1 << CS00)|(1<<CS01); // Sets the prescaler to 64
OCR0A = 250;//number that the timer counts to for 1 ms
}

/* This delays the program an amount specified by unsigned int delay.
* Use timer 0. Keep in mind that you need to choose your prescalar wisely
* such that your timer is precise to 1 millisecond and can be used for
* 100-200 milliseconds
*/
void delayMs(unsigned int delay){
    unsigned int delayCnt= 0;
    TCNT0 = 0;//starting the timer at 0 instead of some random junk number
    TIFR0 |= (1 << OCF0A);// set compare flag to start timer
    while (delayCnt< delay) {
        if (TIFR0 & (1 << OCF0A)) {
        
            delayCnt++;
            TIFR0 |= (1 << OCF0A);//re-start timer. will go to 0 before reaching the if statement above
        }
     }
}