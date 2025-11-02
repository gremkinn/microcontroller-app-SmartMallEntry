/*
 * File:   Functions.c
 * Author: Sai Ananda Ingle // 5611044b
 *
 * Created on 7 December, 2023, 7:41 PM
 */


#include <xc.h>
#include "config.h"

//Initialize global variables
extern int shoppers;
extern int capLimitStatus;

//Define bits of the buttons/switches
#define system PORTBbits.RB4
#define capLimit PORTBbits.RB2
#define entryB PORTBbits.RB1
#define exitB PORTBbits.RB0

//Function declarations: LCD 
void sendLCD(char, unsigned char);
void msgLCD(char msg[]);

//Function declarations: Buzzer Tones
void entryTone(void);
void exitTone(void);
void exitErrorTone(void);
void entryErrorTone(void);

//Function declarations: 7-Segment Display
void sevSegNum(int);
void sevSegFull(void);
void sevOff(void);

//Function declarations: LEDs Patterns
void errorLED(void);
void entryLED(void);
void exitLED(void);
void nearMaxLED(void);
void maxLED(void);
void offLED(void);

//Function declarations: Operational program functions
void entryF(void);
void exitF(void);

void entryF(void) {
    sevOff();

    //Turn on LED
    entryLED();

    //Disp welcome message
    sendLCD(0b00000001, 0); //Clear LCD display & address counter
    sendLCD(0b10000100, 0); //Send cursor to line 1
    msgLCD("Welcome!");
    sendLCD(0b11000000, 0); //Send cursor to line 2
    msgLCD("~Enjoy shopping~");

    //Play entry tone
    entryTone();

    sendLCD(0b00000001, 0); //Clear LCD display & address counter

    //Update shoppers & disp on 7 seg
    shoppers++;
    sevSegNum(shoppers);
}

void exitF(void) {
    sevOff();

    //Turn on LED
    exitLED();

    //Disp thank you message
    sendLCD(0b00000001, 0); //Clear LCD display & address counter
    sendLCD(0b10000011, 0); //Send cursor to line 1
    msgLCD("Thank you!");
    sendLCD(0b11000001, 0); //Send cursor to line 2
    msgLCD("~See you soon~");

    //Play exit tone
    exitTone();
 
    sendLCD(0b00000001, 0); //Clear LCD display & address counter

    shoppers--; //Subtract from shoppers
    sevSegNum(shoppers); //Update 7 seg display 
}

void empty(void) {
    offLED(); //Turn off LEDs

    //Disp default message
    sendLCD(0b10000001, 0); //Send cursor to line 1
    msgLCD("| Springside |");
    sendLCD(0b11000001, 0); //Send cursor to line 2
    msgLCD("|    Mall    |");

    while (1) {
        sevSegNum(shoppers); //Display no. of shoppers on 7 seg disp
        if (entryB == 0) {
            entryF(); //If entry button pressed, carry out entry operations.
            break;
        } else if (exitB == 0) { //If exit button pressed, carry out error operations
            sevOff();
            errorLED();

            //Display error message
            sendLCD(0b00000001, 0); //Clear LCD display & address counter
            sendLCD(0b10000001, 0); //Send cursor to line 1
            msgLCD("Mall is empty");
            sendLCD(0b11000000, 0); //Send cursor to line 2
            msgLCD("Exit unavailable");

            exitErrorTone(); //Play error tone
            _delay(1000000);
            sendLCD(0b00000001, 0); //Clear LCD display & address counter
            break;
        } else if (system == 0 || capLimit != capLimitStatus)
            break; //Check if system and capLimit switches have changed, break out of loop if true.
    }
}

void maxCap(void) {
    maxLED(); //Turn on all LEDs

    //Display full message
    sendLCD(0b10000001, 0); //Send cursor to line 1
    msgLCD("| Springside |");
    sendLCD(0b11000001, 0); //Send cursor to line 2
    msgLCD("|  is full!  |");

    while (1) {
        sevSegFull(); //Display FULL on 7 seg disp
        if (exitB == 0) {
            exitF(); //If exit button pressed, carry out exit operations.
            break;
        } else if (entryB == 0) { //If entry button pressed, carry out error operations.
            sevOff();
            errorLED();

            //Display error message
            sendLCD(0b00000001, 0); //Clear LCD display & address counter
            sendLCD(0b10000010, 0); //Send cursor to line 1
            msgLCD("Mall is full");
            sendLCD(0b11000000, 0); //Send cursor to line 2
            msgLCD("No entry allowed");

            entryErrorTone(); //Play error tone
            _delay(1000000);
            sendLCD(0b00000001, 0); //Clear LCD display & address counter
            break;
        } else if (system == 0 || capLimit != capLimitStatus)
            break; //Check if system and capLimit switches have changed, break out of loop if true.
    }
}

void openCap(void) {
    offLED(); //Turn off LEDs

    //Disp default message
    sendLCD(0b10000001, 0); //Send cursor to line 1
    msgLCD("| Springside |");
    sendLCD(0b11000001, 0); //Send cursor to line 2
    msgLCD("|    Mall    |");

    while (1) {
        sevSegNum(shoppers); //Display no. of shoppers on 7 seg disp
        if (entryB == 0) {
            entryF(); //If entry button pressed, carry out entry operations.
            break;
        } else if (exitB == 0) {
            exitF(); //If exit button pressed, carry out exit operations.
            break;
        } else if (system == 0 || capLimit != capLimitStatus)
            break; //Check if system and capLimit switches have changed, break out of loop if true.
    }
}

void nearMax(void) {
    nearMaxLED(); //Turn on 2 LEDs

    //Disp default message
    sendLCD(0b10000011, 0); //Send cursor to line 1
    msgLCD("Springside");
    sendLCD(0b11000001, 0); //Send cursor to line 2
    msgLCD("is almost full.");

    while (1) {
        sevSegNum(shoppers); //Display no. of shoppers on 7 seg disp
        if (entryB == 0) {
            entryF(); //If entry button pressed, carry out entry operations.
            break;
        } else if (exitB == 0) {
            exitF(); //If exit button pressed, carry out exit operations.
            break;
        } else if (system == 0 || capLimit != capLimitStatus)
            break; //Check if system and capLimit switches have changed, break out of loop if true.
    }
}



