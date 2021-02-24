namespace ping {
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
  distance= distance / 58;       
  return (int) distance;
} 

void setup(){
pinMode(Echo, INPUT);
pinMode(Trig, OUTPUT);
}
}
