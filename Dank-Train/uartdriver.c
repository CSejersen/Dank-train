/************************************************
* "uart.c":                                     *
* Implementation file for Mega2560 UART driver. *
* Using UART 0.                                 *
* Henning Hargaard, 5/4 2019                    *
*************************************************/
#include <avr/io.h>
#include <stdlib.h>
#include "uartdriver.h"


/*************************************************************************
UART 0 initialization:
    Asynchronous mode. /
    Baud rate = 9600. /
    Data bits = 8. /
    RX and TX enabled. /
    No interrupts enabled. /
    Number of Stop Bits = 1. /
    No Parity. /
    Baud rate = 9600. /
    Data bits = 8. /
*************************************************************************/
void InitUART(unsigned long BaudRate, unsigned char DataBit, unsigned char Rx_Int)
{
	if((BaudRate < 300 || BaudRate > 115200 || DataBit < 5 || DataBit > 8)){
		exit(1);
	}
	UCSR0B = 0b00011000;
	if(Rx_Int != 0){
		UCSR0B |= 0b10000000;
	}

	
	//U2X0 = 0; // normal asynchronous mode.
	UBRR0 = (XTAL/(16*BaudRate))-1;
	UCSR0C = ((DataBit-5) << 1);
}

/*************************************************************************
  Returns 0 (FALSE), if the UART has NOT received a new character.
  Returns value <> 0 (TRUE), if the UART HAS received a new character.
*************************************************************************/
unsigned char CharReady()
{
	if ((UCSR0A & 0b10000000) == 0){
		return 0;
	}
	else{
		return 1;
	}
}

/*************************************************************************
Awaits new character received.
Then this character is returned.
*************************************************************************/
char ReadChar()
{
	while(CharReady() == 0){
		
	}
	return UDR0;
}

/*************************************************************************
Awaits transmitter register ready.
Then send the character.
Parameter :
	Tegn : Character for sending. 
*************************************************************************/
void SendChar(char Tegn)
{
	while((UCSR0A & 0b00100000) == 0){
		
	}
	UDR0 = Tegn;
		
   // <---- Skriv din kode her
}

/*************************************************************************
Sends 0 terminated string.
Parameter:
   Streng: Pointer to the string. 
*************************************************************************/
void SendString(char* Streng)
{
   // <---- Skriv din kode her
   while(*Streng != 0){
	   SendChar(*Streng);
	   Streng++;
   }
}

/*************************************************************************
Converts the integer "Tal" to an ASCII string - and then sends this string
using the USART.
Makes use of the C standard library <stdlib.h>.
Parameter:
    Tal: The integer to be converted and sent. 
*************************************************************************/
void SendInteger(int Tal)
{
   // <---- Skriv din kode her
   char array[30];
   itoa(Tal, array, 10);
   SendString(array);
}

/************************************************************************/
