/*
  Differential Drive Robot CPC
  Built and maintained by Anuj Verma, CLAD
  Last modified 14:30 IST 13-03-2020 AD

  This the CPP file for a library that allows you to run a robot using an L293D driver for differential drive.

  This library allows you to control the direction of movement and power supplied to the motor. Power must be entered as a percetage into the built in functions.

  Format used to name pins and variables: each name is composed of two uppercase characters. Either one motor and one direction appear together, or P for power and one motor appear together.

    Motors:
      L - left
      R - Right
      C - Common

    Directions:
      F - Forward
      B - backward

    P is used for power, the PWM pins used to contol the power supplied to the motors. Normally, this appears with either L or R for one of the motors, but PC is a special case for the power pin to be used when there is a common connector for both motors.

  Connections expected:
    LF - Left forward motor pin
    LB - Left backward motor pin
    RF - Right forward motor pin
    RB - Right backward motor pin
    [PC - Common ower control PWM pin]
    [PL - Left power control PWM pin]
    [PR - Right power control PWM pin]

    You must connect all four direction pins (LF, LB, RF, RB). You can optionally connect either a single common power control PWM pin (PC), or connect two power control PWM pins (PL, PR) where one control one motor.
*/

#include "Arduino.h"
#include "DDBot.h"

/* Initializing class instances */

// Class method 1: no power control
// This takes the DIO pin numbers for motors as its input
DDBot::DDBot (uint8_t LF, uint8_t LB, uint8_t RF, uint8_t RB) {
  // Pin numbers passed into the function are transferred to global variables for the rest of the program to interact with
  _LF = LF; // Left-forward
  _LB = LB; // Left-backward
  _RF = RF; // Right-forward
  _RB = RB; // Right-backward

  // Power pins are set to -1 by default, to indicate that they are not to be used.
  _PC = -1; // Power-common
  _PL = -1; // Power-left
  _PR = -1; // Power-right
}

// Class method 2: common power control
// This takes the DIO and PWM pin numbers for motors as its input
DDBot::DDBot (uint8_t LF, uint8_t LB, uint8_t RF, uint8_t RB, uint8_t PC) {
  // Pin numbers passed into the function are transferred to global variables for the rest of the program to interact with
  _LF = LF; // Left-forward
  _LB = LB; // Left-backward
  _RF = RF; // Right-forward
  _RB = RB; // Right-backward

  // Power pins are set to -1 by default, to indicate that they are not to be used. Where they are used, the pin numbers passed into the function are transferred to global variables for the rest of the program to interact with
  _PC = PC; // Power-common
  _PL = -1; // Power-left
  _PR = -1; // Power-right
}

// Class method 3: separate power control
// This takes the DIO and PWM pin numbers for motors as its input
DDBot::DDBot (uint8_t LF, uint8_t LB, uint8_t RF, uint8_t RB, uint8_t PL, uint8_t PR) {
  // Pin numbers passed into the function are transferred to global variables for the rest of the program to interact with
  _LF = LF; // Left-forward
  _LB = LB; // Left-backward
  _RF = RF; // Right-forward
  _RB = RB; // Right-backward

  // Power pins are set to -1 by default, to indicate that they are not to be used. Where they are used, the pin numbers passed into the function are transferred to global variables for the rest of the program to interact with
  _PC = -1; // Power-common
  _PL = PL; // Power-left
  _PR = PR; // Power-right
}


/* Custom writes
  These functions allow you to digitalWrite() to the pins directly. You can type these as boolean commands. Example:
  custom(0, 1, 0, 1);
*/

// No power control
// This function takes boolean values for the pin state as its inputs
void DDBot::custom(uint8_t LF, uint8_t LB, uint8_t RF, uint8_t RB) {
  digitalWrite(_LF, LF);
  digitalWrite(_LB, LB);
  digitalWrite(_RF, RF);
  digitalWrite(_RB, RB);
}

// Common power control
// This function takes boolean values for the pin state, and an integer value for the power, as its inputs
void DDBot::custom(uint8_t LF, uint8_t LB, uint8_t RF, uint8_t RB, long PC) {
  digitalWrite(_LF, LF);
  digitalWrite(_LB, LB);
  digitalWrite(_RF, RF);
  digitalWrite(_RB, RB);

  setPower(PC);
}

// Separate power control
// This function takes boolean values for the pin state, and integer values for the power, as its inputs
void DDBot::custom(uint8_t LF, uint8_t LB, uint8_t RF, uint8_t RB, long PL, long PR) {
  digitalWrite(_LF, LF);
  digitalWrite(_LB, LB);
  digitalWrite(_RF, RF);
  digitalWrite(_RB, RB);

  setPower(PL, PR);
}


// Initializing function
// This sets the pinModes of the pins that will be used throughout the program. It uses the values of the pin numbers from the class instance to determine how many PWM pins to use for controlling power.
void DDBot::init () {
  // Set the pinModes as OUTPUT for the DIO pins that control direction
  pinMode(_LF, OUTPUT);
  pinMode(_LB, OUTPUT);
  pinMode(_RF, OUTPUT);
  pinMode(_RB, OUTPUT);

  // Determine, and set the pinModes of the appropriae PWM pins as OUTPUT. If none have been specified, no pins are allocated to power control.
  if (!((_PC == -1) && (_PL == -1) && (_PR == -1))) { // Check if any power control has been specified
    if (!(_PC == -1)) { // Then check whether it is the common pin
      pinMode(_PC, OUTPUT); // If it is the common pin, set it to OUTPUT
    }

    else {  // If it is not the common pin, but power control pins have been specified, set the individual power control pins to OUTPUT
      pinMode(_PL, OUTPUT);
      pinMode(_PR, OUTPUT);
    }
  }
}


/* No power specification commands
  These functions are commands for specific motion directions. They do not change the power parameter.

  Syntax:
  motors.[task]();

  The raw values used for digitalWrite() are indicated alongside each action in order of the DIO pin: (LF LB RF RB). For example, the code for rotating clockwise (1 0 0 1) corresponds to
  digitalWrite(_LF, HIGH);
  digitalWrite(_LB, LOW);
  digitalWrite(_RF, LOW);
  digitalWrite(_RB, HIGH);
*/

// Move forward (1 0 1 0)
void DDBot::forward() {
  digitalWrite(_LF, HIGH);
  digitalWrite(_LB, LOW);
  digitalWrite(_RF, HIGH);
  digitalWrite(_RB, LOW);
}

// Move backward (0 1 0 1)
void DDBot::backward() {
  digitalWrite(_LF, LOW);
  digitalWrite(_LB, HIGH);
  digitalWrite(_RF, LOW);
  digitalWrite(_RB, HIGH);
}

// Rotate clockwise (1 0 0 1)
void DDBot::clockwise() {
  digitalWrite(_LF, HIGH);
  digitalWrite(_LB, LOW);
  digitalWrite(_RF, LOW);
  digitalWrite(_RB, HIGH);
}

// Rotate counter-clockwise (0 1 1 0)
void DDBot::counterClockwise() {
  digitalWrite(_LF, LOW);
  digitalWrite(_LB, HIGH);
  digitalWrite(_RF, HIGH);
  digitalWrite(_RB, LOW);
}

// Move forward, curving left (0 0 1 0)
void DDBot::leftF() {
  digitalWrite(_LF, LOW);
  digitalWrite(_LB, LOW);
  digitalWrite(_RF, HIGH);
  digitalWrite(_RB, LOW);
}

// Move backward, curving left (0 0 0 1)
void DDBot::leftB() {
  digitalWrite(_LF, LOW);
  digitalWrite(_LB, LOW);
  digitalWrite(_RF, LOW);
  digitalWrite(_RB, HIGH);
}

// Move forward, curving right (1 0 0 0)
void DDBot::rightF() {
  digitalWrite(_LF, HIGH);
  digitalWrite(_LB, LOW);
  digitalWrite(_RF, LOW);
  digitalWrite(_RB, LOW);
}

// Move backward, curving right (0 1 0 0)
void DDBot::rightB() {
  digitalWrite(_LF, LOW);
  digitalWrite(_LB, HIGH);
  digitalWrite(_RF, LOW);
  digitalWrite(_RB, LOW);
}

// Stop moving (0 0 0 0)
void DDBot::stop() {
  digitalWrite(_LF, LOW);
  digitalWrite(_LB, LOW);
  digitalWrite(_RF, LOW);
  digitalWrite(_RB, LOW);
}

/* Implicit specification commands
  These functions are commands for specific motion directions. They allow you to change the power parameter. The power is entered as percentage value (0 to 100), scaled internally from 0 to 225 for the PWM duty cycle.

  Syntax:
  motors.[task]([power]);

  The raw values used for digitalWrite() are indicated alongside each action in order of the DIO pin: (LF LB RF RB). For example, the code for rotating clockwise (1 0 0 1) corresponds to
  digitalWrite(_LF, HIGH);
  digitalWrite(_LB, LOW);
  digitalWrite(_RF, LOW);
  digitalWrite(_RB, HIGH);
*/

// Move forward at specified power (1 0 1 0)
void DDBot::forward(long power) {
  digitalWrite(_LF, HIGH);
  digitalWrite(_LB, LOW);
  digitalWrite(_RF, HIGH);
  digitalWrite(_RB, LOW);

  setPower(power);
}

// Move backward at specified power (0 1 0 1)
void DDBot::backward(long power) {
  digitalWrite(_LF, LOW);
  digitalWrite(_LB, HIGH);
  digitalWrite(_RF, LOW);
  digitalWrite(_RB, HIGH);

  setPower(power);
}

// Rotate clockwise at specified power (1 0 0 1)
void DDBot::clockwise(long power) {
  digitalWrite(_LF, HIGH);
  digitalWrite(_LB, LOW);
  digitalWrite(_RF, LOW);
  digitalWrite(_RB, HIGH);

  setPower(power);
}

// Rotate counter-clockwise at specified power (0 1 1 0)
void DDBot::counterClockwise(long power) {
  digitalWrite(_LF, LOW);
  digitalWrite(_LB, HIGH);
  digitalWrite(_RF, HIGH);
  digitalWrite(_RB, LOW);

  setPower(power);
}

// Move forward, curving left at specified power (0 0 1 0)
void DDBot::leftF(long power) {
  digitalWrite(_LF, LOW);
  digitalWrite(_LB, LOW);
  digitalWrite(_RF, HIGH);
  digitalWrite(_RB, LOW);

  setPower(power);
}

// Move backward, curving left at specified power (0 0 0 1)
void DDBot::leftB(long power) {
  digitalWrite(_LF, LOW);
  digitalWrite(_LB, LOW);
  digitalWrite(_RF, LOW);
  digitalWrite(_RB, HIGH);

  setPower(power);
}

// Move forward, curving right at specified power (1 0 0 0)
void DDBot::rightF(long power) {
  digitalWrite(_LF, HIGH);
  digitalWrite(_LB, LOW);
  digitalWrite(_RF, LOW);
  digitalWrite(_RB, LOW);

  setPower(power);
}

// Move backward, curving right at specified power (0 1 0 0)
void DDBot::rightB(long power) {
  digitalWrite(_LF, LOW);
  digitalWrite(_LB, HIGH);
  digitalWrite(_RF, LOW);
  digitalWrite(_RB, LOW);

  setPower(power);
}

// Stop moving (at specified power?) (0 0 0 0)
// Although power will be immaterial when the robot is not moving, the library allows you to specify it for the sake of consistency.
void DDBot::stop(long power) {
  digitalWrite(_LF, LOW);
  digitalWrite(_LB, LOW);
  digitalWrite(_RF, LOW);
  digitalWrite(_RB, LOW);

  setPower(power);
}


/* Set the power
  The power is enterd as percentage (0 to 100) and scaled from 0 to 255 for the PWM duty cycle. The map() function, built into the Arduino environment, provides an easy method for the scaling; you can change the input to have a different range. Example for range 200 to 800 mapped to 0 to 255:
  map(power, 200, 800, 0, 255)
*/

// Common power control
void DDBot::setPower(long power) {
  analogWrite(_PC, map(power, 0, 100, 0, 255)); // Map and write the power value
}

// Separate power control
void DDBot::setPower(long powerL, long powerR) {
  analogWrite(_PL, map(powerL, 0, 100, 0, 255));   // Map and write the power value for the left motor
  analogWrite(_PR, map(powerR, 0, 100, 0, 255));   // Map and write the power value for the right motor
}
