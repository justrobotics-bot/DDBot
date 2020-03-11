#include "DDBot.h"

DDBot motors (2, 3, 4, 5, 6);

void setup(){
    motors.init();
    Serial.begin(9600);
}

void loop(){
    Serial.println("Power: 100");
    motors.setPower(100);
    delay(1000);

    Serial.println("Forward");
    motors.forward();
    delay(2500);

    Serial.println("Backward");
    motors.backward();
    delay(2500);

    Serial.println("Cloclwise");
    motors.clockwise();
    delay(2500);

    Serial.println("Left Forward");
    motors.leftF();
    delay(2500);

    Serial.println("Left Backward");
    motors.leftB();
    delay(2500);

    Serial.println("Right Forward");
    motors.rightF();
    delay(2500);

    Serial.println("Right Backward");
    motors.rightB();
    delay(2500);

    Serial.println("Stop");
    motors.clockwise();
    delay(4000);

    Serial.println("Forward 50");
    motors.forward(50);
    delay(2500);

    Serial.println("Backward 50");
    motors.backward(50);
    delay(2500);

    Serial.println("Cloclwise 50");
    motors.clockwise(50);
    delay(2500);

    Serial.println("Left Forward 50");
    motors.leftF(50);
    delay(2500);

    Serial.println("Left Backward 50");
    motors.leftB(50);
    delay(2500);

    Serial.println("Right Forward 50");
    motors.rightF(50);
    delay(2500);

    Serial.println("Right Backward 50");
    motors.rightB(50);
    delay(2500);

    Serial.println("Stop 50");
    motors.clockwise(50);
    delay(4000);
}