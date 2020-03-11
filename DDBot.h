/* 
Differential Drive Robot Header
Built and maintained by Anuj Verma, CLAD
Last updated: 13:28 IST 11-03-2020 AD

This the header file for a library that allows you to run a robot using an L293D driver for differential drive.

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

#ifndef DDBOT_h
#define DDBOT_h

#include "Arduino.h"


class DDBot {
    public:
    DDBot (int LF, int LB, int RF, int RB);
    DDBot (int LF, int LB, int RF, int RB, int PP);
    DDBot (int LF, int LB, int RF, int RB, int PL, int PR);

    void init();

    void custom(int LF, int LB, int RF, int RB);
    void custom(int LF, int LB, int RF, int RB, int PP);
    void custom(int LF, int LB, int RF, int RB, int PL, int PR);

    void forward();
    void backward();
    void clockwise();
    void counterClockwise();
    void leftF();
    void leftB();
    void rightF();
    void rightB();
    void stop();

    void forward(int power);
    void backward(int power);
    void clockwise(int power);
    void counterClockwise(int power);
    void leftF(int power);
    void leftB(int power);
    void rightF(int power);
    void rightB(int power);
    void stop(int power);

    void setPower(int power);
    void setPower(int powerL, int powerR);

    private:
        int _LF;
        int _LB;
        int _RF;
        int _RB;
        int _PP;
        int _PL;
        int _PR;
};

#endif