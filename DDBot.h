#ifndef DDBOT_h
#define DDBOT_h

#include "Arduino.h"


class DDBot {
    public:
    DDBot (int LF, int LB, int RF, int RB);
    DDBot (int LF, int LB, int RF, int RB, int SP);
    DDBot (int LF, int LB, int RF, int RB, int SL, int SR);

    void init();

    void forward();
    void backward();
    void clockwise();
    void counterClockwise();
    void leftF();
    void lrftB();
    void rightF();
    void rightB();
    void stop();

    void forward(int speed);
    void backward(int speed);
    void clockwise(int speed);
    void counterClockwise(int speed);
    void leftF(int speed);
    void lrftB(int speed);
    void rightF(int speed);
    void rightB(int speed);
    void stop(int speed);

    void setSpeed(int speed);
    void setSpeed(int speedL, int speedR);

    private:
        int _LF;
        int _LB;
        int _RF;
        int _RB;
        int _SP;
        int _SL;
        int _SR;
};

#endif