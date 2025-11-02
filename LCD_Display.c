/*
 * File:   LCD_Display.c
 * Author: HUMANOID
 *
 * Created on 11 December, 2023, 3:46 PM
 */

#include <xc.h>
#include "config.h"

#define enableLCD PORTEbits.RE0
#define regSelLCD PORTEbits.RE1

//Function declarations: LCD 
void sendLCD(char, unsigned char);

void startLCD(void) {
    _delay(15000);
    sendLCD(0b00000011, 0);
    _delay(5000);
    sendLCD(0b00000010, 0);

    sendLCD(0b00101000, 0); //Function Set (4-bit DL, 2 lines, 5*7 dots)
    sendLCD(0b00001100, 0); //Disp on, cursor off, blink off
    sendLCD(0b00000110, 0); //Entry Mode (Increment pos,no shift)
    sendLCD(0b00000001, 0); //Clear display & address counter
}

void sendLCD(char x, unsigned char b) {
    regSelLCD = b; //Set to logic 0 to send control instructions or 1 to send data word
    PORTD = x; //Send upper nibble
    enableLCD = 1;
    _delay(1000);
    enableLCD = 0;
    _delay(1000); //Trigger falling edge pulse
    x <<= 4;
    PORTD = x; //Send lower nibble
    enableLCD = 1;
    _delay(1000);
    enableLCD = 0;
    _delay(1000); //Trigger falling edge pulse
}

void msgLCD(char msg[]) { //Send message to be displayed one character at a time
    int i;
    for (i = 0; msg[i] != 0; i++)
        sendLCD(msg[i], 1);
}

