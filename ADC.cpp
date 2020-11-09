
#include "ADC.h"

  // set voltage references to be AVCC
  //(RIGHT JUSTIFIED)
  // set Auto Trigger Source Selection
  // set to free-running mode 
  // enable auto-triggering and turn-on ADC
  // set the pre-scaler
  // disable ADC0 pin digital input
  // start the first conversion
  
void initADC()
{
    // Set reference voltage to be AVCC
    ADMUX |= (1<<REFS0);
    ADMUX &= ~(1<<REFS1);

    // Set to right justified
    ADMUX &= ~(1<<ADLAR);

    // Set Auto-trigger Source Selection
    // Set to Free-running
    ADCSRB &= ~((1<<ADTS2) | (1<<ADTS1) | (1<<ADTS0));

    // Enable auto-triggering and turn on ADC
    ADCSRA |= (1<<ADEN) | (1<<ADATE);

    // Set prescalar to 128
    ADCSRA |= (1<<ADPS2) | (1<<ADPS1) | (1<<ADPS0);

    // Disable ADC0 pin digital input
    DIDR0 |= (1<<ADC7D);

    // Start first conversion
    ADCSRA |= (1<<ADSC);
}

