#include <BluetoothSerial.h>

BluetoothSerial ESP_BT;

int command;

int IN_1 = 5; // Kanan
int IN_2 = 18; // Kanan
int IN_3 = 19; // Kiri
int IN_4 = 21; // Kiri

void setup() {
  Serial.begin(9600);
  ESP_BT.begin("ESP32_Motor_Control");
  Serial.println("Bluetooth Ready to Pair...");
  pinMode(IN_1, OUTPUT);
  pinMode(IN_2, OUTPUT);
  pinMode(IN_3, OUTPUT);
  pinMode(IN_4, OUTPUT);
}

void loop() {
  command = 0;
  if (ESP_BT.available()) {
    command = ESP_BT.read();
    Serial.print("Received :");
    Serial.println(command);

    if (command == 70)
    {
      //Forward
      digitalWrite(IN_1, HIGH);
      digitalWrite(IN_2, LOW);
      digitalWrite(IN_3, HIGH);
      digitalWrite(IN_4, LOW);
    }
    if (command == 66)
    {
      //Backward
      digitalWrite(IN_1, LOW);
      digitalWrite(IN_2, HIGH);
      digitalWrite(IN_3, LOW);
      digitalWrite(IN_4, HIGH);
    }
    if (command == 76)
    {
      //Left
      digitalWrite(IN_1, LOW);
      digitalWrite(IN_2, LOW);
      digitalWrite(IN_3, LOW);
      digitalWrite(IN_4, HIGH);
    }
    if (command == 82)
    {
      //Right
      digitalWrite(IN_1, LOW);
      digitalWrite(IN_2, HIGH);
      digitalWrite(IN_3, LOW);
      digitalWrite(IN_4, LOW);
    }
    if (command == 83) {
      //Stop
      digitalWrite(IN_1, LOW);
      digitalWrite(IN_2, LOW);
      digitalWrite(IN_3, LOW);
      digitalWrite(IN_4, LOW);
    }
  }
}
