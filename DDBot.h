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
    void custom(int LF, int LB, int RF, int RB, int PP)
    void custom(int LF, int LB, int RF, int RB, int PL, int PR)

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