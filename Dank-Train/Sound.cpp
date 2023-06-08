/************************************************************
* Software til SOMO kontrol                                 *
* Den første er kommandoens nummer (liste herunder)         *
* Den anden er en parameter-værdi, hvis betydning           *
* afhænger af kommandoen.                                   *
* Kommandoer:                                               *
  play:                                                     *
  Funktion:  Afspiller en valgt sang. Hardcoded til Folder 1*
  Parameter: Bestemmer hvilket nummer sang.                 *
  pause:                                                    *
  Funktion:  Stopper afspilning                             *
  Parameter: Bruges ikke                                    *
  volume:                                                   *
  Funktion:  Indstiller lydstyrken til en bestemt værdi     *
  Parameter: Bestemmer hvad lydstyrken sættes til (0-30)    *
                                                            *  
* Dato oprettet (ISO): 2023-05-12                           *
* Authors:                                                  *
* Kenny Le, Thomas Bové                                     *
************************************************************/
#pragma once
#define F_CPU 16000000
#include "Sound.h"
#include <avr/io.h>
using namespace std;
#include <util/delay.h>
#include <avr/interrupt.h>
#define DDR   DDRE
#define PORT PORTE
#define PINNR 1
#define BAUD  9600
#define NO_us 1000000/BAUD
extern "C" {
	#include "uart.h"
}

// Sound som Klasse
void Sound::play(unsigned char param) {
	CMD = 0x0F;
	PARA1 = 0x01;
	PARA2 = param;
	checksum();
	send();
}
void Sound::pause() {
	CMD = 0x16;
	PARA1 = 0x00;
	PARA2 = 0x00;
	checksum();
	send();
}
void Sound::volume(unsigned char param) {
	CMD = 0x06;
	PARA1 = 0x00;
	PARA2 = param;
	checksum();
	send();
}

void Sound::checksum() {
	CHECKSUM = (0xFFFF-(CMD+FEEDBACK+PARA1+PARA2)+1);
	CHECKSUM1 = (CHECKSUM >> 8);
	CHECKSUM2 = (CHECKSUM & 0xff);
}
void Sound::send() {
	SendChar(START);
	SendChar(CMD);
	SendChar(FEEDBACK);
	SendChar(PARA1);
	SendChar(PARA2);
	SendChar(CHECKSUM1);
	SendChar(CHECKSUM2);
	SendChar(END);
}
Sound::Sound() {
	START = 0x7E;
	FEEDBACK = 0;
	END = 0xEF;
	InitUART(BAUD, 8, 1);
}





