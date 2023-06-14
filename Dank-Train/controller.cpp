#define F_CPU 16000000
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "controller.h"

int counter = 0;

Controller::Controller(MotorDriver *motor, SoundDriver *sound, LightDriver *lys){
    
    this->motor = motor; 
    this->sound = sound;
    this->lys = lys;

    counterCheck = 1;
    
    initInterupts();
}

void Controller::initInterupts()
{
     // rising edge interupts - INT2 + INT3
    EICRA |= 0b11110000;
    // Enable INT2 + INT3
    EIMSK |= 0b00001100;
    sei();
}

void Controller::startCar()
{
    sound->volume(30);
    _delay_ms(10);
    //sound->play(1);

    _delay_ms(6000); // wait for song
    lys->setFrontLight(43);
    lys->setBackLight(10);
    motor->forward(2);

    // Acceleration
    _delay_ms(300);
    motor->forward(3);
    _delay_ms(300);
    motor->forward(4);
    _delay_ms(300);
	motor->forward(5);
	
}


void Controller::reactToInterupts()
{
    switch (counter) {
        case 1:
            if (counterCheck == counter) // only true once
            {
                counterCheck++;
                sound->play(2); 
			}
            break;
        case 2:
            if (counterCheck == counter)
            {
                counterCheck++;
                sound->play(2); 
            }
            break;
            

        case 3:
            if (counterCheck == counter)
            {
                counterCheck++;
                sound->play(2); 
				motor->forward(5);
            }
            break;
                
        
        case 4:
            if (counterCheck == counter)
            {
                counterCheck++;
                sound->play(2); 
				motor->forward(3);
            }
            break;

        case 5:
            if (counterCheck == counter)
            {
               counterCheck++;
                sound->play(2); 
            }
            break;
        
        case 6:
            if (counterCheck == counter)
            {
                counterCheck++;
                sound->play(2); 
                motor->backward(5);
                lys->setBackLight(52);
            }
            break;

        case 7:
            if (counterCheck == counter)
            {
                counterCheck++;
				
                
            }
			break;
			
		case 8:
			if (counterCheck == counter)
			{
				counterCheck++;
				sound->play(2);
				motor->forward(3);
                lys->setBackLight(10);
			}
            break;
		case 9:
			if (counterCheck == counter)
			{
				counterCheck++;
				motor->forward(5);
			}
			break;
			
		case 10:
			if (counterCheck == counter)
			{
				counterCheck++;
				sound->play(2);
			}
			break;
		case 11:
			if (counterCheck == counter)
			{
				counterCheck++;
				motor->stop();
                sound->play(3);
                lys->setBackLight(0);
                lys->setBackLight(0);
			}
			break;
        default:
            break;
        // flere cases
    }
}

    ISR(INT2_vect)
    {
        // disable interrupts
    EIMSK &= ~(1 << INT3);
    EIMSK &= ~(1 << INT2);

    counter++;
    _delay_ms(500);

    // reset interrupt flags and enable again
    EIFR |= (1 << INTF2);
    EIFR |= (1 << INTF3);
    EIMSK |= (1 << INT2);
    EIMSK |= (1 << INT3);
}

ISR(INT3_vect)
{
    // disable interrupts
    EIMSK &= ~(1 << INT3);
    EIMSK &= ~(1 << INT2);

    counter++;
    _delay_ms(500);

    // reset interrupt flags and enable again
    EIFR |= (1 << INTF3);
    EIFR |= (1 << INTF2);
    EIMSK |= (1 << INT3);
    EIMSK |= (1 << INT2);
}

