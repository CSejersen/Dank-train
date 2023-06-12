#include "avr/io.h"
#include "Lys.h"

// default constructor
Lys::Lys()
{
	DDRB = 0xFF;
	setFrontItens(0);
	setBakItens(0);
	TCCR0A = 0b10000011;
	TCCR0B = 0b00000011;
	
	TCCR1A = 0b10000001;
	TCCR1B = 0b00000011;
	
}

// Takes % intensity returns pwm on portb ben 7
void Lys::setFrontItens(int intensitet){
	if (intensitet >= 0 || intensitet <= 100){
		frontLys = intensitet;
	}
	else{
		frontLys = 1;
	}
	OCR0A = (255 / 100) * frontLys;
}


// Takes % intensity returns pwm on portb ben 5
void Lys::setFrontItens(int intensitet){
void Lys::setBakItens(int intensitet){
	
	if (intensitet >= 0 || intensitet <= 100){
		bakLys = intensitet;
	}
	else{
		bakLys = 1;
	}
	
	OCR1A = (255 / 100) * bakLys;
}
