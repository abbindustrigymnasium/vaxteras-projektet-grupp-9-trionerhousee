const byte MotorSpeed = 5;
const byte MotorDir = 0;

const byte FanSpeed = 4;
const byte FanDir = 2;

int pot = A0;
int potval = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(MotorDir, OUTPUT);
  digitalWrite(MotorDir, HIGH);

  pinMode(FanDir, OUTPUT);
  digitalWrite(FanDir, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:

  potval = analogRead(pot);
  Serial.println(potval);

  digitalWrite(MotorDir, HIGH);

  analogWrite(MotorSpeed, 1020);
  
  digitalWrite(FanDir, HIGH);

  analogWrite(FanSpeed, 1020);


}
