const byte MotorSpeed = 5;
const byte MotorDir = 0;

const byte FanSpeed = 4;
const byte FanDir = 2;

int pot = 90;
int potval = 900;

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


  Serial.println(potval);

  digitalWrite(MotorDir, HIGH);

  analogWrite(MotorSpeed, 900);

  delay(5000);
  analogWrite(MotorSpeed, 0);


}
