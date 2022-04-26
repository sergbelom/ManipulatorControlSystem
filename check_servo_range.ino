#include <Servo.h>

Servo myservo;
Servo myservo1;
Servo myservo2;

void setup() {
  myservo.attach(9);
  myservo1.attach(5);
  myservo2.attach(6);

  myservo.write(90);
  myservo1.write(90);
  myservo2.write(90);
  }

void loop() {
  for (int i = 90; i >= 0; i--) {
    myservo.write(i);
    myservo1.write(i);
    myservo2.write(i);
    delay(40);
    }
  for (int i = 0; i <= 90; i++) {
    myservo.write(i);
    myservo1.write(i);
    myservo2.write(i);
    delay(50);
    }
  for (int i = 90; i <= 120; i++) {
    myservo.write(i);
    myservo1.write(i);
    myservo2.write(i);
    delay(60);
    }
  for (int i = 120; i >= 90; i--) {
    myservo.write(i);
    myservo1.write(i);
    myservo2.write(i);
    delay(70);
    }
}
