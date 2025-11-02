/*
 * File:   7-Segment Code.c
 * Author: Sai Ananda Ingle // 5611044b
 *
 * Created on 7 December, 2023, 7:15 PM
 */

#include <xc.h>
#include "config.h"

void sevSegNum(int shoppers) {
    unsigned char digits[10] = {
        0b11000000, 0b11111001,
        0b10100100, 0b10110000,
        0b10011001, 0b10010010,
        0b10000010, 0b11111000,
        0b10000000, 0b10010000
    }; //Array of bits corresponding to digits 0-9

    //Formulas to derive individual digits of shoppers.
    int dig1 = shoppers / 1000;
    int dig2 = (shoppers / 100) % 10;
    int dig3 = (shoppers / 10) % 10;
    int dig4 = shoppers % 10;

    //Display shoppers no. on 7 seg disp
    PORTAbits.RA5 = 1; //1st panel
    PORTAbits.RA4 = 1;
    if (shoppers < 1000)
        PORTC = 0xFF; //Turn off panel if not req
    else
        PORTC = digits[dig1];
    _delay(5000);

    PORTAbits.RA5 = 1; //2nd panel
    PORTAbits.RA4 = 0;
    if (shoppers < 100) //Turn off panel if not req
        PORTC = 0xFF;
    else
        PORTC = digits[dig2];
    _delay(5000);

    PORTAbits.RA5 = 0; //3rd panel
    PORTAbits.RA4 = 1;
    if (shoppers < 10) //Turn off panel if not req
        PORTC = 0xFF;
    else
        PORTC = digits[dig3];
    _delay(5000);

    PORTAbits.RA5 = 0; //4th panel
    PORTAbits.RA4 = 0;
    PORTC = digits[dig4];
    _delay(5000);
}

void sevSegFull(void) {
    unsigned char full[] = {
        0b10001110, 0b11000001, 0b11000111
    }; //Array of bits corresponding to the letters 'F','U','L'

    //Display FULL no. on 7 seg disp
    PORTAbits.RA5 = 1; //1st panel, F
    PORTAbits.RA4 = 1;
    PORTC = full[0];
    _delay(5000);

    PORTAbits.RA5 = 1; //2nd panel, U
    PORTAbits.RA4 = 0;
    PORTC = full[1];
    _delay(5000);

    PORTAbits.RA5 = 0; //3rd panel, L
    PORTAbits.RA4 = 1;
    PORTC = full[2];
    _delay(5000);

    PORTAbits.RA5 = 0; //4th panel, L
    PORTAbits.RA4 = 0;
    PORTC = full[2];
    _delay(5000);
}

void sevOff(void) {
    //Turn off 7-segment display.
    PORTAbits.RA5 = 1;
    PORTAbits.RA4 = 1;
    PORTC = 0xFF;
    _delay(5000);

    PORTAbits.RA5 = 1;
    PORTAbits.RA4 = 0;
    PORTC = 0xFF;
    _delay(5000);

    PORTAbits.RA5 = 0;
    PORTAbits.RA4 = 1;
    PORTC = 0xFF;
    _delay(5000);

    PORTAbits.RA5 = 0;
    PORTAbits.RA4 = 0;
    PORTC = 0xFF;
    _delay(5000);
}