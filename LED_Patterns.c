/*
 * File:   LED_Patterns.c
 * Author: HUMANOID
 *
 * Created on 9 December, 2023, 8:52 PM
 */


#include <xc.h>
#include "config.h"

//Define the bit corresponding to each LED to avoid interfering with the other Port A bits
#define LED1 PORTAbits.RA3
#define LED2 PORTAbits.RA2
#define LED3 PORTAbits.RA1
#define LED4 PORTAbits.RA0

void errorLED(void) { //All LEDs blink once for an error
    LED1 = 0, LED2 = 0, LED3 = 0, LED4 = 0;
    _delay(500000);
    LED1 = 1, LED2 = 1, LED3 = 1, LED4 = 1;
    _delay(500000);
}

void entryLED(void) { //LEDs light up one at a time, in sequence from left to right
    LED1 = 1, LED2 = 0, LED3 = 0, LED4 = 0;
    _delay(250000);
    LED1 = 0, LED2 = 1, LED3 = 0, LED4 = 0;
    _delay(250000);
    LED1 = 0, LED2 = 0, LED3 = 1, LED4 = 0;
    _delay(250000);
    LED1 = 0, LED2 = 0, LED3 = 0, LED4 = 1;
    _delay(250000);
    LED1 = 0, LED2 = 0, LED3 = 0, LED4 = 0;
}

void exitLED(void) { //LEDs light up one at a time, in sequence from right to left
    LED1 = 0, LED2 = 0, LED3 = 0, LED4 = 1;
    _delay(500000);
    LED1 = 0, LED2 = 0, LED3 = 1, LED4 = 0;
    _delay(500000);
    LED1 = 0, LED2 = 1, LED3 = 0, LED4 = 0;
    _delay(500000);
    LED1 = 1, LED2 = 0, LED3 = 0, LED4 = 0;
    _delay(500000);
    LED1 = 0, LED2 = 0, LED3 = 0, LED4 = 0;
}

void nearMaxLED(void) { //Turn on only 2 LEDS to show system is reaching the max
    LED1 = 1, LED2 = 0, LED3 = 0, LED4 = 1;
}

void maxLED(void) { //Turn on all LEDs to indicate max capacity has been reached 
    LED1 = 1, LED2 = 1, LED3 = 1, LED4 = 1;
}

void offLED(void) { //Turn off all LEDs
    LED1 = 0, LED2 = 0, LED3 = 0, LED4 = 0;
}
