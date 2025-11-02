/*
 * File:   Buzzer Tones.c
 * Author: Sai Ananda Ingle // 5611044b
 *
 * Created on 8 December, 2023, 9:26 PM
 */

#include <xc.h>
#include "config.h"

//Function declarations of different musical notes, that each have a unique frequency.
void A_low(float);
void A_hi(float);
void B_low(float);
void B_hi(float);
void C_low(float);
void C_hi(float);
void D(float);
void E(float);
void G(float);
void space(float); //No sound

//Function definitions of different musical notes

void A_low(float sec) {
    int x;
    int loopNum = sec / 0.0043; //Formula to derive no. of loops based on play time required

    for (x = 0; x < loopNum; x++) {
        PORTBbits.RB3 = 1;
        _delay(2150); //233Hz
        PORTBbits.RB3 = 0;
        _delay(2150);
    }
}

void A_hi(float sec) {
    int x;
    int loopNum = sec / 0.0021;

    for (x = 0; x < loopNum; x++) {
        PORTBbits.RB3 = 1;
        _delay(1050); //466Hz
        PORTBbits.RB3 = 0;
        _delay(1050);
    }
}

void B_low(float sec) {
    int x;
    int loopNum = sec / 0.0041;

    for (x = 0; x < loopNum; x++) {
        PORTBbits.RB3 = 1;
        _delay(2050); //246Hz
        PORTBbits.RB3 = 0;
        _delay(2050);
    }
}

void B_hi(float sec) {
    int x;
    int loopNum = sec / 0.002;

    for (x = 0; x < loopNum; x++) {
        PORTBbits.RB3 = 1;
        _delay(1000); //493Hz
        PORTBbits.RB3 = 0;
        _delay(1000);
    }
}

void C_low(float sec) {
    int x;
    int loopNum = sec / 0.0077;

    for (x = 0; x < loopNum; x++) {
        PORTBbits.RB3 = 1;
        _delay(3850); //130Hz
        PORTBbits.RB3 = 0;
        _delay(3850);
    }
}

void C_hi(float sec) {
    int x;
    int loopNum = sec / 0.0039;

    for (x = 0; x < loopNum; x++) {
        PORTBbits.RB3 = 1;
        _delay(1950); //261Hz
        PORTBbits.RB3 = 0;
        _delay(1950);
    }
}

void D(float sec) {
    int x;
    int loopNum = sec / 0.0034;

    for (x = 0; x < loopNum; x++) {
        PORTBbits.RB3 = 1;
        _delay(1700); //293Hz
        PORTBbits.RB3 = 0;
        _delay(1700);
    }
}

void E(float sec) {
    int x;
    int loopNum = sec / 0.003;

    for (x = 0; x < loopNum; x++) {
        PORTBbits.RB3 = 1;
        _delay(1500); //329Hz
        PORTBbits.RB3 = 0;
        _delay(1500);
    }
}

void G(float sec) {
    int x;
    int loopNum = sec / 0.0026;

    for (x = 0; x < loopNum; x++) {
        PORTBbits.RB3 = 1;
        _delay(1300); //392Hz
        PORTBbits.RB3 = 0;
        _delay(1300);
    }
}

void space(float sec) { //No sound
    int x;
    int loopNum = sec * 1000000;
    PORTBbits.RB3 = 0;
    for (x = 0; x < loopNum; x++)
        _delay(1);
}

//Function definitions of tunes for each situation

void entryTone(void) {
    E(0.3);
    space(0.2);
    E(0.3);
    space(0.2);
    E(0.3);
    space(0.5);
    C_hi(0.2);
    E(0.2);
    space(0.3);
    G(0.4);
    space(0.3);
    E(0.4);
}

void exitTone(void) {
    C_hi(0.5);
    space(0.3);
    C_hi(0.5);
    space(0.3);
    C_low(0.25);
    space(0.25);
    C_low(0.25);
    D(0.25);
    space(0.25);
    D(0.25);
    E(0.5);
    G(0.6);
}

void exitErrorTone(void) {
    C_low(0.3);
    C_hi(0.3);
    A_low(0.3);
    A_hi(0.3);
    B_low(0.15);
    B_hi(0.15);
    space(0.2);
    B_hi(0.15);
    E(0.3);
}

void entryErrorTone(void) {
    G(0.5);
    A_hi(0.5);
    B_hi(0.5);
    C_hi(0.5);
    space(0.2);
    D(0.4);
    E(0.3);
}




