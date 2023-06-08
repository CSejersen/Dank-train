#include "motorstyring.h"
#include "Sound.h"
#include "Lys.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>


  
  
int main(){
	
     Motor motor;
     Lys light;
     Sound sound;

     motor.forward(4);
     sound.volume(10);
     sound.play(1);
	 light.setFrontItens(100);
	 light.setBakItens(100);

    return 0;
}
