#pragma once

#include "motorstyring.h"
#include "sound.h"
#include "lys.h"


class Controller {

public:
    // Constructer with pointers to motor, sound and light drivers
    Controller(Motor *, Sound *, Lys *);

    // Functions to run car
    void startCar();
    void reactToInterupts();
    void initInterupts();

private:
    // ensures each new case in reactToInterupts() only runs once
    int controllerCounter;

    // driver pointers
    Motor *motor;
    Sound *sound; 
    Lys *lys;
}; 
