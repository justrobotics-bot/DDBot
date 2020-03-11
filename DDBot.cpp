/* 
Differential Drive Robot CPP
Built and maintained by Anuj Verma, CLAD
Last updated: 13:28 IST 11-03-2020 AD

This the CPP file for a library that allows you to run a robot using an L293D driver for differential drive.

This library allows you to control the direction of movement and power supplied to the motor. Power must be entered as a percetage into the built in functions.

Connections expected:
    LF - Left forward motor pin
    LB - Left backward motor pin
    RF - Right forward motor pin
    RB - Right backward motor pin
    [PP - Power control PWM pin]
    [PL - Left power control PWM pin]
    [PR - Right power control PWM pin]

    You must connect all four direction pins (LF, LB, RF, RB). You can optionally connect either a single power control PWM pin (PP), or connect two power control PWM pins (PL, PR) where one is for each motor.

*/

#include "Arduino.h"
#include "DDBot.h"

DDBot::DDBot (int LF, int LB, int RF, int RB){
    _LF = LF;
    _LB = LB;
    _RF = RF;
    _RB = RB;

    _PP = 0;
    _PL = 0;
    _PR = 0;
}

DDBot::DDBot (int LF, int LB, int RF, int RB, int PP){
    _LF = LF;
    _LB = LB;
    _RF = RF;
    _RB = RB;

    _PP = PP;
    _PL = 0;
    _PR = 0;
}

DDBot::DDBot (int LF, int LB, int RF, int RB, int PL, int PR){
    _LF = LF;
    _LB = LB;
    _RF = RF;
    _RB = RB;

    _PP = 0;
    _PL = PL;
    _PR = PL;
}

void DDBot::custom(int LF, int LB, int RF, int RB){
    digitalWrite(_LF, LF);
    digitalWrite(_LB, LB);
    digitalWrite(_RF, RF);
    digitalWrite(_RB, RB);
}

void DDBot::custom(int LF, int LB, int RF, int RB, int PP){
    digitalWrite(_LF, LF);
    digitalWrite(_LB, LB);
    digitalWrite(_RF, RF);
    digitalWrite(_RB, RB);

    analogWrite(_PP, PP);
}

void DDBot::custom(int LF, int LB, int RF, int RB, int PL, int PR){
    digitalWrite(_LF, LF);
    digitalWrite(_LB, LB);
    digitalWrite(_RF, RF);
    digitalWrite(_RB, RB);

    analogWrite(_PL, PL);
    analogWrite(_PR, PR);
}

void DDBot::init (){
    pinMode(_LF, OUTPUT);
    pinMode(_LB, OUTPUT);
    pinMode(_RF, OUTPUT);
    pinMode(_RB, OUTPUT);

    if (!((_PP == 0) && (_PL == 0) && (_PR == 0))){
        if (!(_PP == 0)){
            pinMode(_PP, OUTPUT);
        }

        else {
            pinMode(_PL, OUTPUT);
            pinMode(_PR, OUTPUT);
        }
    }
}

void DDBot::forward(){
    digitalWrite(_LF, HIGH);
    digitalWrite(_LB, LOW);
    digitalWrite(_RF, HIGH);
    digitalWrite(_RB, LOW);
}

void DDBot::backward(){
    digitalWrite(_LF, LOW);
    digitalWrite(_LB, HIGH);
    digitalWrite(_RF, LOW);
    digitalWrite(_RB, HIGH);
}

void DDBot::clockwise(){
    digitalWrite(_LF, HIGH);
    digitalWrite(_LB, LOW);
    digitalWrite(_RF, LOW);
    digitalWrite(_RB, HIGH);
}

void DDBot::counterClockwise(){
    digitalWrite(_LF, LOW);
    digitalWrite(_LB, HIGH);
    digitalWrite(_RF, HIGH);
    digitalWrite(_RB, LOW);
}

void DDBot::leftF(){
    digitalWrite(_LF, LOW);
    digitalWrite(_LB, LOW);
    digitalWrite(_RF, HIGH);
    digitalWrite(_RB, LOW);
}

void DDBot::leftB(){
    digitalWrite(_LF, LOW);
    digitalWrite(_LB, LOW);
    digitalWrite(_RF, LOW);
    digitalWrite(_RB, HIGH);
}

void DDBot::rightF(){
    digitalWrite(_LF, HIGH);
    digitalWrite(_LB, LOW);
    digitalWrite(_RF, LOW);
    digitalWrite(_RB, LOW);
}

void DDBot::rightB(){
    digitalWrite(_LF, LOW);
    digitalWrite(_LB, HIGH);
    digitalWrite(_RF, LOW);
    digitalWrite(_RB, LOW);
}

void DDBot::stop(){
    digitalWrite(_LF, LOW);
    digitalWrite(_LB, LOW);
    digitalWrite(_RF, LOW);
    digitalWrite(_RB, LOW);
}


void DDBot::forward(int power){
    digitalWrite(_LF, HIGH);
    digitalWrite(_LB, LOW);
    digitalWrite(_RF, HIGH);
    digitalWrite(_RB, LOW);

    setPower(power);
}

void DDBot::backward(int power){
    digitalWrite(_LF, LOW);
    digitalWrite(_LB, HIGH);
    digitalWrite(_RF, LOW);
    digitalWrite(_RB, HIGH);

    setPower(power);
}

void DDBot::clockwise(int power){
    digitalWrite(_LF, HIGH);
    digitalWrite(_LB, LOW);
    digitalWrite(_RF, LOW);
    digitalWrite(_RB, HIGH);

    setPower(power);
}

void DDBot::counterClockwise(int power){
    digitalWrite(_LF, LOW);
    digitalWrite(_LB, HIGH);
    digitalWrite(_RF, HIGH);
    digitalWrite(_RB, LOW);

    setPower(power);
}

void DDBot::leftF(int power){
    digitalWrite(_LF, LOW);
    digitalWrite(_LB, LOW);
    digitalWrite(_RF, HIGH);
    digitalWrite(_RB, LOW);

    setPower(power);
}

void DDBot::leftB(int power){
    digitalWrite(_LF, LOW);
    digitalWrite(_LB, LOW);
    digitalWrite(_RF, LOW);
    digitalWrite(_RB, HIGH);

    setPower(power);
}

void DDBot::rightF(int power){
    digitalWrite(_LF, HIGH);
    digitalWrite(_LB, LOW);
    digitalWrite(_RF, LOW);
    digitalWrite(_RB, LOW);

    setPower(power);
}

void DDBot::rightB(int power){
    digitalWrite(_LF, LOW);
    digitalWrite(_LB, HIGH);
    digitalWrite(_RF, LOW);
    digitalWrite(_RB, LOW);

    setPower(power);
}

void DDBot::stop(int power){
    digitalWrite(_LF, LOW);
    digitalWrite(_LB, LOW);
    digitalWrite(_RF, LOW);
    digitalWrite(_RB, LOW);

    setPower(power);
}

void DDBot::setPower(int power){
    analogWrite(_PP, map(power, 0, 100, 0, 255));
}

void DDBot::setPower(int powerL, int powerR){
    analogWrite(_PL, map(powerL, 0, 100, 0, 255));
    analogWrite(_PR, map(powerR, 0, 100, 0, 255));
}