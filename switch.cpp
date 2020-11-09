// Description: This file implements the initialization of an external
// switch.
//----------------------------------------------------------------------//

#include "switch.h"
#include <avr/io.h>

//Setup pin D0 as input 
//Set pull up resistance 
//Setup external interupt with any edge change 

void initSwitchPD0(){
 DDRD &= ~(1<< DDD0);// turns port 21 into an input
 PORTD |= (1<<PORTD0);// enables the pull up resistor


 /////////////////////////////////////////////////////////////
 // this code turns pin 21 into an external interupt.
 EICRA |= (1<<ISC00);
  EICRA &= ~(1<<ISC01);
 EIMSK |= (1 << INT0);      
    
}