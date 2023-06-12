#include <avr/io.h>
#include <avr/interrupt.h>
#define f_CPU 16000000
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
    sound->play(1);

    _delay_ms(10000); // wait for song
    lys->setFrontItens(100);
    lys->setBakItens(20);
    motor->forward(2);

    // Acceleration
    motor->forward(3);
    _delay_ms(500);
    motor->forward(4);
    _delay_ms(500);
    motor->forward(5);
}


void Controller::reactToInterupts()
{
    switch (counter) {
        case 1:
            if (controllerCounter == counter) // only true once
            {
                controllerCounter++;
                sound->play(2); 
                // to do
            }

        case 2:
            if (controllerCounter == counter)
            {
                sound->play(3); 
                // to do
            }
        
        case 3:
            if (controllerCounter == counter)
            {
                sound->play(4); 
                // to do
            }
        // flere cases
    }
}

    ISR(INT2_vect)
    {
        // disable interrupts
    EIMSK &= ~(1 << INT2);
    EIMSK &= ~(1 << INT3);

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
    EIMSK &= ~(1 << INT2);
    EIMSK &= ~(1 << INT3);

    counter++;
    _delay_ms(400);

    // reset interrupt flags and enable again
    EIFR |= (1 << INTF3);
    EIFR |= (1 << INTF2);
    EIMSK |= (1 << INT3);
    EIMSK |= (1 << INT2);
}

