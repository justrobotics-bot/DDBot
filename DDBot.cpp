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