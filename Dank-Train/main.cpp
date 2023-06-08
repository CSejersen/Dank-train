#include "motorstyring.h"
#include "Sound.h"
#include "Lys.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>



  
int main(){
	int refleksCounter = 1;


     Motor motor;
     Lys light;
     Sound sound;

     sound.volume(30); //OBS det blir pissehøjt. sæt evt til 5 mens vi tester.
     sound.play(refleksCounter);

     motor.forward(5); //Prøver lige med speed 5 til en start
     
	 light.setFrontItens(100);
	 light.setBakItens(25);


     while(refleksCounter <= 7){
        
     }

     light.setBakItens(0);
     light.setFrontItens(0);

    return 0;
}


ISR(INT2_vect){

	refleksCounter+=1;
    

    if(refleksCounter <= 5){
        return;
    }

    if(refleksCounter == 5){ //hvilket nummer er bakkesensoren??
        light.setBakItens(100)
        motor.stop();
        //alternativt, prøv at bruge getStatus() fra motorstyring.h til at time bakningen
        // getStatus() returnerer 0 efter vi har kaldt stop() og motoren er helt stoppet.
        light.setBakItens(25)
        motor.backward(5);
    }
    if(refleksCounter == 6){
        light.setBakItens(100)
        motor.stop();
        //alternativt, prøv at bruge getStatus() fra motorstyring.h til at time bakningen
        // getStatus() returnerer 0 efter vi har kaldt stop() og motoren er helt stoppet.
        light.setBakItens(25)
        motor.forward(5);
    }

    if(refleksCounter == 7){
        light.setBakItens(100)
        motor.stop();
        light.setBakItens(25)
        //alternativt, prøv at bruge getStatus() fra motorstyring.h til at time bakningen
        // getStatus() returnerer 0 efter vi har kaldt stop() og motoren er helt stoppet.
    }

    sound.play(refleksCounter);
}

ISR(INT3_vect){

}
