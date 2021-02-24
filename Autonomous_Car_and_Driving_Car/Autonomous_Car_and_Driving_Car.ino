#include <BluetoothSerial.h>
#include "Drive.h"

BluetoothSerial ESP_BT;

int command;

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
      drive::backward();
    }
    if (command == 76)
    {
      drive::turn_left();
    }
    if (command == 82)
    {
      drive::turn_right();
    }
    if (command == 83) {
      drive::stop();
    }
  }
}
