#pragma once
#include "motordriver.h"
#include "sounddriver.h"
#include "lightdriver.h"


class Controller {

public:
    // Constructer with pointers to motor, sound and light drivers
    Controller(MotorDriver *, SoundDriver *, LightDriver *);

    // Functions to run car
    void startCar();
    void reactToInterupts();
    void initInterupts();

private:
    // ensures each new case in reactToInterupts() only runs once
    int counterCheck;

    // driver pointers
    MotorDriver *motor;
    SoundDriver *sound; 
    LightDriver *lys;
}; 
