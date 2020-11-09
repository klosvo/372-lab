
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
  Serial.begin(9600);
    int valueADC = 0;
    double voltage = 0.0;
    bool onOff = true;
    initTimer0();
    initADC();
    initPWM();
    initSwitchPD0();
    sei();
    
    while(1)
    {
valueADC = ADCL;
valueADC +=( (unsigned int) ADCH<< 8);
//voltage = valueADC*(5.0/1024.0);
//SetMOTORspeed(valueADC);

      /////////////////////////////////////////////////////debounce state machine
 switch(state){
        case wait_press:
        break;
        case dbpress:
        delayMs(1); 
        state = waitrelse;
        break;
        case waitrelse:

        break;
        case dbrelse:
        
      delayMs(1);
        state = wait_press;

        switch(onOff){
          case false:
          onOff = true;
          
          break;
          case true:
          onOff = false;
          break;
        }


        break;
        }
        if(onOff){ 
       valueADC = 550;
       }
     SetMOTORspeed(valueADC);
      // Serial.println(voltage);  
      // Serial.flush();
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
