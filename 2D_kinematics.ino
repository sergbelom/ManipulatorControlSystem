#include <Servo.h>
#include <math.h>

Servo myservo1;
Servo myservo2;

volatile float L_1 = 175.0;
volatile float L_2 = 165.0;
volatile float pi = 3.14159265359;

void setup() {  
  myservo1.attach(5);
  myservo2.attach(6);

  Serial.begin(9600);

  myservo1.write(90);
  myservo2.write(90);
  }

void loop() {
  myservo1.write(10);
  myservo2.write(10);
  inverseKinematics();
}

void inverseKinematics() {

  float angle1;
  float angle2;
  float rad_angle1;
  float rad_angle2;
  float x;
  float y;

  //delay(2000);

  Serial.println("x:");
  while(Serial.available()==0){}
  x=Serial.parseFloat();

  Serial.println("y:");
  while(Serial.available()==0){}
  y=Serial.parseFloat();
  
//  x = 200.0;
//  y = 200.0;

  rad_angle2=acos((sq(x)+ sq(y) - sq(L_1) - sq(L_2)) / (2*L_1*L_2));
  rad_angle1=atan(y / x) - atan((L_2*sin(rad_angle2)) / (L_1 + L_2*cos(rad_angle2)));
  delay(1000);

  angle1=(rad_angle1*180)/pi;
  angle2=(rad_angle2*180)/pi;

  Serial.print("x is "); 
  Serial.println(x);
  Serial.print("y is "); 
  Serial.println(y);
  Serial.print("angle1 is  "); 
  Serial.println(angle1);
  Serial.print("angle2 is "); 
  Serial.println(angle2);

  myservo1.write(angle1);
  myservo2.write(angle2);
  delay(2000);  
}
