/*
  Differential Drive Robot Header
  Built and maintained by Anuj Verma, CLAD
  Last modified 01:42 IST 12-03-2020 AD

  This the header file for a library that allows you to run a robot using an L293D driver for differential drive.

  This library allows you to control the direction of movement and power supplied to the motor. Power must be entered as a percetage into the built in functions.

  Format used to name pins and variables: each name is composed of two uppercase characters. Either one motor and one direction appear together, or P for power and one motor appear together.

    Motors:
      L - left
      R - right

    Directions:
      F - Forward
      B - backward

    P is used for power, the PWM pins used to contol the power supplied to the motors. Normally, this appears with either L or R for one of the motors, but PC is a special case for the power pin to be used when there is a common connector for both motors.

  Connections expected:
    LF - Left forward motor pin
    LB - Left backward motor pin
    RF - Right forward motor pin
    RB - Right backward motor pin
    [PC - Power control PWM pin]
    [PL - Left power control PWM pin]
    [PR - Right power control PWM pin]

    You must connect all four direction pins (LF, LB, RF, RB). You can optionally connect either a single power control PWM pin (PC), or connect two power control PWM pins (PL, PR) where one control one motor.
*/

#ifndef DDBOT_h
#define DDBOT_h

#include "Arduino.h"


class DDBot {
  public:
    DDBot (uint8_t LF, uint8_t LB, uint8_t RF, uint8_t RB);
    DDBot (uint8_t LF, uint8_t LB, uint8_t RF, uint8_t RB, uint8_t PC);
    DDBot (uint8_t LF, uint8_t LB, uint8_t RF, uint8_t RB, uint8_t PL, uint8_t PR);

    void init();

    void custom(uint8_t LF, uint8_t LB, uint8_t RF, uint8_t RB);
    void custom(uint8_t LF, uint8_t LB, uint8_t RF, uint8_t RB, uint8_t PC);
    void custom(uint8_t LF, uint8_t LB, uint8_t RF, uint8_t RB, uint8_t PL, uint8_t PR);

    void forward();
    void backward();
    void clockwise();
    void counterClockwise();
    void leftF();
    void leftB();
    void rightF();
    void rightB();
    void stop();

    void forward(long power);
    void backward(long power);
    void clockwise(long power);
    void counterClockwise(long power);
    void leftF(long power);
    void leftB(long power);
    void rightF(long power);
    void rightB(long power);
    void stop(long power);

    void setPower(long power);
    void setPower(long powerL, long powerR);

  private:
    uint8_t _LF;
    uint8_t _LB;
    uint8_t _RF;
    uint8_t _RB;
    uint8_t _PC;
    uint8_t _PL;
    uint8_t _PR;
};

#endif
