/****************************************
* "uart_int.h":                         *
* Header file for Mega2560 UART driver. *
* Using UART 0.                         *
* If parameter Rx_Int <> 0 :            *
* Receiver interrupt will be enabled    *
*                                       *
* Henning Hargaard, 10/4 2019           *
*****************************************/ 

// Target CPU frequency
#define XTAL 16000000

void InitUART(unsigned long BaudRate, unsigned char DataBit, unsigned char Rx_Int);
unsigned char CharReady();
char ReadChar();
void SendChar(char Tegn);
void SendString(char* Streng);
void SendInteger(int Tal);
/****************************************/