/*
 * File:   Main.c
 * Author: Sai Ananda Ingle // 5611044b
 *
 * Created on 7 December, 2023, 7:19 PM
 */


#include <xc.h>
#include "config.h"

//Initialize global variables.
int shoppers = 9999; //Adjust for demo purposes.
int capLimitStatus;

#define system PORTBbits.RB4
#define capLimit PORTBbits.RB2
#define entryB PORTBbits.RB1
#define exitB PORTBbits.RB0
#define LED1 PORTAbits.RA3
#define LED2 PORTAbits.RA2
#define LED3 PORTAbits.RA1
#define LED4 PORTAbits.RA0

//Function declarations: 7-Segment Display
void sevOff(void);

//Function declarations: LCD
void sendLCD(char, unsigned char);
void startLCD(void);

//Function declarations: Operational program functions
void empty(void);
void maxCap(void);
void openCap(void);
void nearMax(void);

void main(void) {
    //Initialize all ports to digital
    ANSELA = 0;
    ANSELB = 0;
    ANSELC = 0;
    ANSELD = 0;
    ANSELE = 0;
    //Initialize respective bits as i/o
    TRISA = 0b11000000;
    TRISB = 0b11110111;
    TRISC = 0;
    TRISD = 0x0F;
    TRISE = 0b11111100;

    startLCD(); //Initiate LCD

    while (1) {
        while (system == 1) { //While system is On
            if (system == 0)
                break; //If system switch Off, break out of loop
            if (capLimit == 1) { //Check if capLimit switch is On
                capLimitStatus = 1; //Update status

                //Check no. of shoppers and run respective functions
                if (shoppers == 0) {
                    empty();
                } else if (shoppers < 990) {
                    openCap();
                } else if (shoppers >= 990 & shoppers < 1000) {
                    nearMax();
                } else if (shoppers >= 1000) {
                    maxCap();
                }
            } else if (capLimit == 0) { //Check if capLimit switch is Off
                capLimitStatus = 0; //Update status

                //Check no. of shoppers and run respective functions
                if (shoppers == 0) {//capLimit
                    empty();
                } else if (shoppers > 0) {
                    openCap();
                }
            }
        }
        while (system == 0) { //While system is Off
            if (system == 1)
                break; //If system switch On, break out of loop

            //Turn off all outputs
            LED1 = 0, LED2 = 0, LED3 = 0, LED4 = 0;
            PORTB = 0;
            sevOff();
            sendLCD(0b00000001, 0); //Clear LCD display & address counter }
        }
    }
}

