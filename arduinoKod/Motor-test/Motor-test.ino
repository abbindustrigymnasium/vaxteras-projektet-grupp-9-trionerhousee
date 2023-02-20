const byte FanSpeed = 4;
const byte FanDir = 2;


void setup() {
  // put your setup code here, to run once:
  
  pinMode(FanDir, OUTPUT);
  digitalWrite(FanDir, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  digitalWrite(FanDir, LOW);

  analogWrite(FanSpeed, 1023);


}
