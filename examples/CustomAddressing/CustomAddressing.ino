/*
  Custom Addressig
  Built and maintained by Anuj Verma, CLAD
  Last modified 21:59 IST 12-03-2020 AD

  This is an example test file for a library that allows you to run a robot using an L293D driver for differential drive. This example demostrates the custom() function of the library, which allows you to send commands directly to write to the DIO pins rather than using the predefined directions. During execution, the name of the current command is sent to the Tx line of the default Serial (USB) port of the Arduino.

  Only one PWM pin is used in this example to control the power to the motors, presumably common to the left and right motors.

  The raw values are used for digitalWrite() in order of the DIO pin: (LF, LB, RF, RB). For example, the code for rotating clockwise (1, 0, 0, 1) corresponds to
    digitalWrite(_LF, HIGH);
    digitalWrite(_LB, LOW);
    digitalWrite(_RF, LOW);
    digitalWrite(_RB, HIGH);

  Pin connections expected in this code:
    2 - LF - Left forward motor pin
    3 - LB - Left backward motor pin
    4 - RF - Right forward motor pin
    5 - RB - Right backward motor pin
    6 - PC - Power control PWM pin
*/

// Include the library into the sketch
#include <DDBot.h>

// Define the DIO and PWM pins to be used for controlling the motors
DDBot motors (2, 3, 4, 5, 6); // Here, an instance of the class is called and it is named "motors". You can choose a different name if you wish.
/* Possible syntaxes
  DDBot (int LF, int LB, int RF, int RB);
  DDBot (int LF, int LB, int RF, int RB, int PC);
  DDBot (int LF, int LB, int RF, int RB, int PL, int PR);

  The second method above is used here.
*/

// Setup code that runs only once
void setup() {
  motors.init();  // Initialize the library; this specifies the pinModes
  Serial.begin(9600); // Initialize the Serial port
}

// Loop code that runs infinitely many times
void loop() {
  /*  Syntax for each block
  
        Serial.println("Information");
        motors.custom([values]);
        delay([value]);

      The first line sends the command details (LF, LB, RF, RB[, PC]) down the Serial line so that it can be seen on the serial monitor.
      The second line calls the function in the library. custom() allows you to address each motor individually, optionally specifying a power parameter. You can enter either a HIGH or LOW value, or a 1 or 0, to write to the digital pin.
      The last is a delay in milliseconds to make the task last long enough to be observable.
  */

  // Stopped
  Serial.println("0 0 0 0");  // Send information down the Serial line
  motors.custom(0, 0, 0, 0);  // Write to digital pins
  delay(1000);  // Wait for 1 s before the next action

  // Forward
  Serial.println("1 0 1 0");  // Send information down the Serial line
  motors.custom(1, 0, 1, 0);  // Write to digital pins
  delay(2500);  // Wait for 1 s before the next action

  // Clockwise
  Serial.println("1 0 0 1");  // Send information down the Serial line
  motors.custom(1, 0, 0, 1);  // Write to digital pins
  delay(2500);  // Wait for 1 s before the next action

  // Forward at 50% power
  Serial.println("0 0 0 0 50");  // Send information down the Serial line
  motors.custom(0, 0, 0, 0, 50);  // Write to digital pins
  delay(1000);  // Wait for 1 s before the next action

  // Rotate counter-clockwise at 50% power
  Serial.println("0 1 1 0 50");  // Send information down the Serial line
  motors.custom(0, 1, 1, 0, 50);  // Write to digital pins
  delay(1000);  // Wait for 1 s before the next action

  // This is the end of this iteration of the loop. It will now repeat.
}