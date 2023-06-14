#define F_CPU 16000000
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "controller.h"

int counter = 0;

Controller::Controller(Motor *motor, Sound *sound, Lys *lys){
    
    this->motor = motor; 
    this->sound = sound;
    this->lys = lys;

    controllerCounter = 1;
    
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
    lys->setFrontItens(100);
    lys->setBakItens(20);
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
            if (controllerCounter == counter) // only true once
            {
                controllerCounter++;
                sound->play(7); 
			}
            break;
        case 2:
            if (controllerCounter == counter)
            {
                controllerCounter++;
                sound->play(7); 
            }
            break;
            

        case 3:
            if (controllerCounter == counter)
            {
                controllerCounter++;
                sound->play(7); 
				motor->forward(5);
            }
            break;
                
        
        case 4:
            if (controllerCounter == counter)
            {
                controllerCounter++;
                sound->play(7); 
				motor->forward(3);
            }
            break;

        case 5:
            if (controllerCounter == counter)
            {
               controllerCounter++;
                sound->play(7); 
            }
            break;
        
        case 6:
            if (controllerCounter == counter)
            {
                controllerCounter++;
                sound->play(7); 
                motor->backward(5);
            }
            break;

        case 7:
            if (controllerCounter == counter)
            {
                controllerCounter++;
				
                
            }
			break;
			
		case 8:
			if (controllerCounter == counter)
			{
				controllerCounter++;
				sound->play(7);
				motor->forward(3);
			}
            break;
		case 9:
			if (controllerCounter == counter)
			{
				controllerCounter++;
				motor->forward(5);
			}
			break;
			
		case 10:
			if (controllerCounter == counter)
			{
				controllerCounter++;
			}
			break;
		case 11:
			if (controllerCounter == counter)
			{
				controllerCounter++;
				motor->stop();
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

