#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "motorstyring.h"
#include "lys.h"
#include "sound.h"
#include "controller.h"

int main(){
     
    Motor motor;
    Sound sound;
    Lys lys;
    Controller controller(&motor, &sound, &lys);

    controller.startCar();

    while (true) {
        controller.reactToInterupts();
    }
    return 0;
}
