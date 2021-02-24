#include <Servo.h>
#include "Drive.h"
//#include "Ping.h"

int Trig = A1;
int Echo = A2;

int rightDistance = 0, leftDistance = 0;

int Distance_test() {
  digitalWrite(Trig, LOW);
  delayMicroseconds(2);
  digitalWrite(Trig, HIGH);
  delayMicroseconds(20);
  digitalWrite(Trig, LOW);
  float distance = pulseIn(Echo, HIGH);
  distance = distance / 58;
  return (int) distance;
}

  Servo myservo;

  char command;

  void setup() {
    Serial.begin(9600);
    myservo.attach(3);
    drive::setup();
    //    ping::setup();
    pinMode(Echo, INPUT);
    pinMode(Trig, OUTPUT);
  }

  void loop() {
    if (Serial.available() > 0) {
      int command = Serial.read();
      Serial.print("Received:");
      Serial.println(command);
//      if (command == 87) {
//        if (command == 66) //Forward
//        {
//          drive::backward();
//        }
//        if (command == 70) //Backward
//        {
//          drive::forward();
//        }
//        if (command == 82)
//        {
//          drive::turn_right();
//        }
//        if (command == 76)
//        {
//          drive::turn_left();
//        }
//        if (command == 83) {
//          drive::stop();
//        }
//      }
//      if (command == 85) {
        myservo.write(60);  //setservo position to right side
        delay(700);
        rightDistance = Distance_test();

        myservo.write(120);  //setservo position to left side
        delay(700);
        leftDistance = Distance_test();


        if ((rightDistance > 70) && (leftDistance > 70)) {
          drive::stop();
        } else if ((rightDistance >= 20) && (leftDistance >= 20)) {
          drive::backward();
        } else if ((rightDistance <= 10) && (leftDistance <= 10)) {
          drive::forward();
          delay(100);
        } else if (rightDistance - 3 > leftDistance) {
          drive::turn_left();
          delay(100);
        } else if (rightDistance + 3 < leftDistance) {
          drive::turn_right();
          delay(100);
        }
//      }
//      else {
//        drive::stop();
//      }
    }
  }
