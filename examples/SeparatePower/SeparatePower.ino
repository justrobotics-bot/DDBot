/*
  Custom Addressig
  Built and maintained by Anuj Verma, CLAD
  Last modified 23:44 IST 12-03-2020 AD

  This is an example test file for a library that allows you to run a robot using an L293D driver for differential drive. This example demostrates the power control functionality, which allows you to adjust how much power is being delivered to the motors.

  Two PWM pins are used in this example to control the power to the motors, presumably one for each of the left and right motors.

  The raw values are used for digitalWrite() in order of the DIO pin: (LF, LB, RF, RB). For example, the code for rotating clockwise (1, 0, 0, 1) corresponds to
    digitalWrite(_LF, HIGH);
    digitalWrite(_LB, LOW);
    digitalWrite(_RF, LOW);
    digitalWrite(_RB, HIGH);

  Pin connections expected by this code:
    2   - LF - Left forward motor pin
    3   - LB - Left backward motor pin
    4   - RF - Right forward motor pin
    5   - RB - Right backward motor pin
    10  - PL - Left power control PWM pin
    11  - PR - Right power control PWM pin
*/

// Include the library into the sketch
#include <DDBot.h>

// Define the DIO and PWM pins to be used for controlling the motors
DDBot motors (2, 3, 4, 5, 10, 11); // Here, an instance of the class is called and it is named "motors". You can choose a different name if you wish.
/* Possible syntaxes
  DDBot (int LF, int LB, int RF, int RB);
  DDBot (int LF, int LB, int RF, int RB, int PC);
  DDBot (int LF, int LB, int RF, int RB, int PL, int PR);

  The third method above is used here.
*/

// Setup code that runs only once
void setup() {
  motors.init();  // Initialize the library; this specifies the pinModes
}

// Loop code that runs infinitely many times
void loop() {

  /*  Syntax for setPower()
      You can specify the power that must be given to the motors, as a percentage (0 to 100), internally scaled from 0 to 255 for the PWM duty cycle.
      
      If you specify only one value in the arguments like this
        setPower(62);
      the program assumes that you have specified only one pin (PC) for power, presumably common to both motors.

      If you specify two values in the arguments like this
        setPower(48, 90);
      the program assumes that the first is for the left motor (PL) and the second for the right motor (PR).
  */


  // Set direction (forward) and initial power (0%)
  // Of course, the robot should not start moving at this point because the power is 0%.
  motors.setPower(0, 0);  // Set both motors to 0% power
  motors.forward(); // Set the motors to move forward
  

  // Gradually turn up the power for the left motor to 100%.
  for (int powerL = 0; powerL < 100; powerL++){  // Initialize a for loop that increments the value of "powerL" until it reaches 100%.
    motors.setPower(powerL, 0); // Write the value of "powerL" from the current iteration to the left motor. The right motor stays at 0% power.
    delay(50);  // Wait 0.05 s before the next action
  } // Break out of the for loop.

  // Gradually turn up the power for the right motor to 100%.
  for (int powerR = 0; powerR < 100; powerR++){ // Initialize a for loop that increments the value of "powerR" until it reaches 100%.
    motors.setPower(100, powerR);  // Write the value of "powerR" from the current iteration to the right motor. The left motor stays at 100% power.
    delay(50);  // Wait 0.05 s before the next action
  } // Break out of the for loop.

  // Gradually turn down the power for both motors.
  for (int power = 100; power > 0; power--){  // Initialize a for loop that decrements the value of "power" until it reaches 0%.
    motors.setPower(power, power);  // Write the value of "power" from the current iteration to both motors.
    delay(20);  // Wait 0.02 s before the next action
  } // Break out of the for loop.


  // Set direction (backward) and initial power (0%)
  // Of course, the robot should not start moving at this point because the power is 0%.
  motors.setPower(0, 0);  // Set both motors to 0% power
  motors.backward(); // Set the motors to move backward
  
  // Gradually turn up the power for the left motor to 100%.
  for (int powerL = 0; powerL < 100; powerL++){  // Initialize a for loop that increments the value of "powerL" until it reaches 100%.
    motors.setPower(powerL, 0); // Write the value of "powerL" from the current iteration to the left motor. The right motor stays at 0% power.
    delay(50);  // Wait 0.05 s before the next action
  } // Break out of the for loop.

  // Gradually turn up the power for the right motor to 100%.
  for (int powerR = 0; powerR < 100; powerR++){ // Initialize a for loop that increments the value of "powerR" until it reaches 100%.
    motors.setPower(100, powerR);  // Write the value of "powerR" from the current iteration to the right motor. The left motor stays at 100% power.
    delay(50);  // Wait 0.05 s before the next action
  } // Break out of the for loop.

  // Gradually turn down the power for both motors.
  for (int power = 100; power > 0; power--){  // Initialize a for loop that decrements the value of "power" until it reaches 0%.
    motors.setPower(power, power);  // Write the value of "power" from the current iteration to both motors.
    delay(20);  // Wait 0.02 s before the next action
  } // Break out of the for loop.

  // This is the end of this iteration of the loop. It will now repeat.
}