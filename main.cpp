
#include <avr/io.h>
#include "ADC.h"
#include "timer.h"
#include "PWM.h"
#include <Arduino.h> 
#include "switch.h"

//Create statemachine for button debouncing
//When system is on motor will rotate based on potentiometer location 
//System turns off when button is pushed

// Create states for the debounce machine.
typedef enum stateType_enum{wait_press, dbpress, waitrelse, dbrelse} stateType;
volatile stateType state = wait_press;

int main()
{
   
    initTimer0();
    initADC();
    initPWM();
    initSwitchPD0();
    sei();

    while(1)
    {
      /////////////////////////////////////////////////////debounce state machine
 switch(state){
        case wait_press:
        break;
        case dbpress:
        _delay_us(100);
        state = waitrelse;
        break;
        case waitrelse:
        break;
        case dbrelse:
        
        _delay_us(100);
        state = wait_press;
    ///////////////////////////////////////////////////////////////////CHANGE OF THE DUTY CYCLE
        break;
        }

         
    }

    return 0;
}
// Establish ISR using external interput on PORTD
  ISR(INT0_vect){
    if(state == wait_press){//code to change state based on current state
     state = dbpress;
    }
    if(state == waitrelse){
    state = dbrelse;
    }
} 
