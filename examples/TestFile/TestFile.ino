/*
  Differential Drive Robot
  Built and maintained by Anuj Verma, CLAD
  Last modified 14:30 IST 13-03-2020 AD

  This example was used for internal testing.

  This is an example test file for a library that allows you to run a robot using an L293D driver for differential drive. This example demostrates all the directions that are pre-defined in the library. It also demonstrates two ways to set the power given to the motors: sepcifying it explicitly using the setPower(int power) function, and sepcifying it within the function that commands the robot to move in a particular direction. During execution, the name of the current command is sent to the Tx line of the default Serial (USB) port of the Arduino.

  Only one PWM pin is used in this example to control the power to the motors, presumably common to the left and right motors.

  The raw values used for digitalWrite() are indicated alongside each action in order of the DIO pin: (LF LB RF RB). For example, the code for rotating clockwise (1 0 0 1) corresponds to
    digitalWrite(_LF, HIGH);
    digitalWrite(_LB, LOW);
    digitalWrite(_RF, LOW);
    digitalWrite(_RB, HIGH);

  Pin connections expected by this code:
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

        Serial.println([name of task]);
        motors.[task]([value]);
        delay([value]);

      The first line sends the name of the task down the Serial line.
      The second line calls the function in the library. Here we only specify the common power value in these functions.
      The last is a delay in milliseconds to make the task last long enough to be observable.
  */

  // Set power to 100% (full)
  Serial.println("Power: 100"); // Send information down the Serial line
  motors.setPower(100); // Write to PWM pins to set the power to 100%. The entered percentage value is internally scaled from 0 to 225 for the PWM duty cycle.
  delay(1000);  // Wait for 1 s before the next action


  /* No power specification commands
    These functions are commands for specific motion directions. They do not change the power parameter.

    Syntax:
    motors.[task]();
  */

  // Move forward (1 0 1 0)
  Serial.println("Forward"); // Send information down the Serial line
  motors.forward(); // Write to digital pins to move the robot forward
  delay(2500);  // Wait for 2.5 s before the next action

  // Move backward (0 1 0 1)
  Serial.println("Backward"); // Send information down the Serial line
  motors.backward(); // Write to digital pins to move the robot backward
  delay(2500);  // Wait for 2.5 s before the next action

  // Rotate clockwise (1 0 0 1)
  Serial.println("Cloclwise");  // Send information down the Serial line
  motors.clockwise(); // Write to digital pins to rotate the robot clockwise
  delay(2500);  // Wait for 2.5 s before the next action

  // Rotate counter-clockwise (0 1 1 0)
  Serial.println("Counter-clockwise");  // Send information down the Serial line
  motors.counterClockwise();  // Write to digital pins to rotate the robot counter-clockwise
  delay(2500);  // Wait for 2.5 s before the next action

  // Move forward, curving left (0 0 1 0)
  Serial.println("Left Forward"); // Send information down the Serial line
  motors.leftF(); // Write to digital pins to move the robot forward, curving left
  delay(2500);  // Wait for 2.5 s before the next action

  // Move backward, curving left (0 0 0 1)
  Serial.println("Left Backward");  // Send information down the Serial line
  motors.leftB(); // Write to digital pins to move the robot backward, curving left
  delay(2500);  // Wait for 2.5 s before the next action

  // Move forward, curving right (1 0 0 0)
  Serial.println("Right Forward");  // Send information down the Serial line
  motors.rightF();  // Write to digital pins to move the robot forward, curving right
  delay(2500);  // Wait for 2.5 s before the next action

  // Move backward, curving right (0 1 0 0)
  Serial.println("Right Backward"); // Send information down the Serial line
  motors.rightB();  // Write to digital pins to move the robot backward, curving right
  delay(2500);  // Wait for 2.5 s before the next action

  // Stop moving (0 0 0 0)
  Serial.println("Stop"); // Send information down the Serial line
  motors.stop();  // Stop the robot
  delay(4000);  // Wait for 4 s before the next action


  /* Implicit specification commands
    These functions are commands for specific motion directions. They allow you to change the power parameter. The power is entered as percentage value (0 to 100), scaled internally from 0 to 225 for the PWM duty cycle.

    Syntax:
    motors.[task]([power]);
  */

  // Move forward at 75% power (1 0 1 0)
  Serial.println("Forward 75"); // Send information down the Serial line
  motors.forward(75); // Write to digital pins to move the robot forward at 75% power
  delay(2500);  // Wait for 2.5 s before the next action

  // Move backward at 75% power (0 1 0 1)
  Serial.println("Backward 75"); // Send information down the Serial line
  motors.backward(75); // Write to digital pins to move the robot backward at 75% power
  delay(2500);  // Wait for 2.5 s before the next action

  // Rotate clockwise at 75% power (1 0 0 1)
  Serial.println("Cloclwise 75");  // Send information down the Serial line
  motors.clockwise(75); // Write to digital pins to rotate the robot clockwise at 75% power
  delay(2500);  // Wait for 2.5 s before the next action

  // Rotate counter-clockwise at 75% power (0 1 1 0)
  Serial.println("Counter-clockwise 75");  // Send information down the Serial line
  motors.counterClockwise(75);  // Write to digital pins to rotate the robot counter-clockwise at 75% power
  delay(2500);  // Wait for 2.5 s before the next action

  // Move forward, curving left at 75% power (0 0 1 0)
  Serial.println("Left Forward 75"); // Send information down the Serial line
  motors.leftF(75); // Write to digital pins to move the robot forward, curving left at 75% power
  delay(2500);  // Wait for 2.5 s before the next action

  // Move backward, curving left at 75% power (0 0 0 1)
  Serial.println("Left Backward 75");  // Send information down the Serial line
  motors.leftB(75); // Write to digital pins to move the robot backward, curving left at 75% power
  delay(2500);  // Wait for 2.5 s before the next action

  // Move forward, curving right at 75% power (1 0 0 0)
  Serial.println("Right Forward 75");  // Send information down the Serial line
  motors.rightF(75);  // Write to digital pins to move the robot forward, curving right at 75% power
  delay(2500);  // Wait for 2.5 s before the next action

  // Move backward, curving right at 75% power (0 1 0 0)
  Serial.println("Right Backward 75"); // Send information down the Serial line
  motors.rightB(75);  // Write to digital pins to move the robot backward, curving right at 75% power
  delay(2500);  // Wait for 2.5 s before the next action

  // Stop moving (at 75% power?) (0 0 0 0)
  // Although power will be immaterial when the robot is not moving, the library allows you to specify it for the sake of consistency.
  Serial.println("Stop 75"); // Send information down the Serial line
  motors.stop(75);  // Stop the robot (at 75% power?)
  delay(4000);  // Wait for 4 s before the next action


  // This is the end of this iteration of the loop. It will now repeat.
}
