
#include <avr/io.h>
#include "ADC.h"
#include "timer.h"
#include "PWM.h"
#include <Arduino.h> 
#include "switch.h"

//Create statemachine for button debouncing
//When system is on motor will rotate based on potentiometer location 
//System turns off when button is pushed


int main()
{
   
    initTimer0();
    initADC();
    initPWM();
    initSwitchPD0();
    sei();

    while(1)
    {

    
    }

    return 0;
}
// Establish ISR using external interput on PORTD
  ISR(){
  
} 
