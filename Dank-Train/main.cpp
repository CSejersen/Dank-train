#include <avr/io.h>
#include <avr/interrupt.h>
#include "motordriver.h"
#include "lightdriver.h"
#include "sounddriver.h"
#include "controller.h"

int main(){
     
    MotorDriver motor;
    SoundDriver sound;
    LightDriver lys;
    Controller controller(&motor, &sound, &lys);

    controller.startCar();

    while (true) {
        controller.reactToInterupts();
    }
    return 0;
}
