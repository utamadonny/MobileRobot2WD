#include <BluetoothSerial.h>
#include "Drive.h"

BluetoothSerial ESP_BT;

int command;

int IN_1 = 5; // Kanan
int IN_2 = 18; // Kanan
int IN_3 = 19; // Kiri
int IN_4 = 21; // Kiri

void setup() {
  drive::setup();
  
  Serial.begin(9600);
  ESP_BT.begin("ESP32_Motor_Control");
  Serial.println("Bluetooth Ready to Pair...");
}

void loop() {
  command = 0;
  if (ESP_BT.available()) {
    command = ESP_BT.read();
    Serial.print("Received :");
    Serial.println(command);

    if (command == 70)
    {
      drive::forward();
    }
    if (command == 66)
    {
      //Backward
      drive::backward();
    }
    if (command == 76)
    {
      //Left
      drive::turn_left();
    }
    if (command == 82)
    {
      //Right
      drive::turn_right();
    }
    if (command == 83) {
      //Stop
      drive::stop();
    }
  }
}
