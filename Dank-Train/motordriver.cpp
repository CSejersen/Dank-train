#include "motorDriver.h"
#include <avr/io.h> 

MotorDriver::MotorDriver(){
    // PE output and set to 0
    DDRE = 0xFF;
    PORTE = 0;
    // Mode = 3 (PWM, Phase Correct, 10 bit)
    // Set OC3A on match down counting / Clear OC3A on match up counting - PE 3
    // Clock prescaler = 1
    TCCR3A = 0b10000011;
    TCCR3B = 0b00000011;
    // Duty cycle = 0%
    OCR3A = 0;
}

void MotorDriver::forward(unsigned char speed){
    unsigned char s = speed;
    if (s != 1 && s != 2 && s !=3 && s !=4 && s !=5 && s !=6){
        //default værdi
        OCR3A = 300;
        return;
    }
    // PB ben 1 styrer retning på motor
    PORTB |= 0b00000001;

    // Duty cycle sættes
    OCR3A = s/6*1024;
}

void MotorDriver::backward(unsigned char speed){

    unsigned char s = speed;

    if (s != 1 && s != 2 && s !=3 && s !=4 && s !=5 && s !=6){
        return;
    }

    // PB ben 1 styrer retning på motor
    PORTB &= 11111110;

    // Duty cycle sættes
    OCR3A = s/6*1024;

}

void MotorDriver::stop(){

    OCR3A = 0;
}


