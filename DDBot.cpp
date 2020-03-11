#include "Arduino.h"
#include "DDBot.h"

DDBot::DDBot (int LF, int LB, int RF, int RB){
    _LF = LF;
    _LB = LB;
    _RF = RF;
    _RB = RB;

    _SP = 0;
    _SL = 0;
    _SR = 0;
}

DDBot::DDBot (int LF, int LB, int RF, int RB, int SP){
    _LF = LF;
    _LB = LB;
    _RF = RF;
    _RB = RB;

    _SP = SP;
    _SL = 0;
    _SR = 0;
}

DDBot::DDBot (int LF, int LB, int RF, int RB, int SL, int SR){
    _LF = LF;
    _LB = LB;
    _RF = RF;
    _RB = RB;

    _SP = 0;
    _SL = SL;
    _SR = SL;
}

void DDBot::init (){
    pinMode(_LF, OUTPUT);
    pinMode(_LB, OUTPUT);
    pinMode(_RF, OUTPUT);
    pinMode(_RB, OUTPUT);

    if (!((_SP == 0) && (_SL == 0) && (SR == 0))){
        if (!(_SP == 0)){
            pinMode(_SP, OUTPUT);
        }

        else {
            pinMode(_SL, OUTPUT);
            pinMode(_SR, OUTPUT);
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


void DDBot::forward(int speed){
    digitalWrite(_LF, HIGH);
    digitalWrite(_LB, LOW);
    digitalWrite(_RF, HIGH);
    digitalWrite(_RB, LOW);

    setSpeed(speed);
}

void DDBot::backward(int speed){
    digitalWrite(_LF, LOW);
    digitalWrite(_LB, HIGH);
    digitalWrite(_RF, LOW);
    digitalWrite(_RB, HIGH);

    setSpeed(speed);
}

void DDBot::clockwise(int speed){
    digitalWrite(_LF, HIGH);
    digitalWrite(_LB, LOW);
    digitalWrite(_RF, LOW);
    digitalWrite(_RB, HIGH);

    setSpeed(speed);
}

void DDBot::counterClockwise(int speed){
    digitalWrite(_LF, LOW);
    digitalWrite(_LB, HIGH);
    digitalWrite(_RF, HIGH);
    digitalWrite(_RB, LOW);

    setSpeed(speed);
}

void DDBot::leftF(int speed){
    digitalWrite(_LF, LOW);
    digitalWrite(_LB, LOW);
    digitalWrite(_RF, HIGH);
    digitalWrite(_RB, LOW);

    setSpeed(speed);
}

void DDBot::leftB(int speed){
    digitalWrite(_LF, LOW);
    digitalWrite(_LB, LOW);
    digitalWrite(_RF, LOW);
    digitalWrite(_RB, HIGH);

    setSpeed(speed);
}

void DDBot::rightF(int speed){
    digitalWrite(_LF, HIGH);
    digitalWrite(_LB, LOW);
    digitalWrite(_RF, LOW);
    digitalWrite(_RB, LOW);

    setSpeed(speed);
}

void DDBot::rightB(int speed){
    digitalWrite(_LF, LOW);
    digitalWrite(_LB, HIGH);
    digitalWrite(_RF, LOW);
    digitalWrite(_RB, LOW);

    setSpeed(speed);
}

void DDBot::stop(int speed){
    digitalWrite(_LF, LOW);
    digitalWrite(_LB, LOW);
    digitalWrite(_RF, LOW);
    digitalWrite(_RB, LOW);

    setSpeed(speed);
}

void DDBot::setSpeed(int speed){
    analogWrite(_SP, map(speed, 0, 100, 0, 255));
}

void DDBot::setSpeed(int speedL, int speedR){
    analogWrite(_SL, map(speedL, 0, 100, 0, 255));
    analogWrite(_SR, map(speedR, 0, 100, 0, 255));
}