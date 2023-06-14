#include "avr/io.h"
#include "lightdriver.h"

// default constructor
LightDriver::LightDriver()
{
	DDRB = 0xFF;
	setFrontLight(0);
	setBackLight(0);
	TCCR0A = 0b10000011;
	TCCR0B = 0b00000011;
	
	TCCR1A = 0b10000001;
	TCCR1B = 0b00000011;
	
}

// Takes % intensity returns pwm on portb ben 7
void LightDriver::setFrontLight(int intensitet){
	if (intensitet >= 0 || intensitet <= 100){
		frontLight = intensitet;
	}
	else{
		frontLight = 1;
	}
	OCR0A = (255 / 100) * frontLight;
}


// Takes % intensity returns pwm on portb ben 5
void LightDriver::setBackLight(int intensitet){
	
	if (intensitet >= 0 || intensitet <= 100){
		backLight = intensitet;
	}
	else{
		backLight = 1;
	}
	
	OCR1A = (255 / 100) * backLight;
}
