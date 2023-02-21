
#include <FirebaseESP8266.h>
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <NTPClient.h>
#include <Wire.h>
#include <AM2320.h>
#include <Servo.h>

AM2320 sensor;
Servo bigHatchServo;
Servo fanHatchServo;

// defines where we should conect to firebase via the webb with the wifi name and pasword

#define FIREBASE_HOST "https://waxteras-default-rtdb.europe-west1.firebasedatabase.app"
#define FIREBASE_AUTH "AIzaSyBslwY7gKcIWTltrOcEeDooZWzSRRcSBUg"
#define WIFI_SSID "ABBgym_2.4"
#define WIFI_PASSWORD "mittwifiarsabra"

// #define WIFI_SSID "Almesbo_wifi"
// #define WIFI_PASSWORD "KottenAlmesbo"

// Define Firebase Data objects
FirebaseData firebaseData1;

const byte fanSpeed = 5;
const byte fanDir = 0;
const byte pumpSpeed = 4;
const byte pumpDir = 2;

String path = "/Nodes";
String nodeID = "Node2";      // This is this node ID to receive control
String otherNodeID = "Node1"; // This is other node ID to control

// setting up time and timezone

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org", 7200, 60000);

String Time;
int days;
int hours;
int minutes;
int seconds;
int timeEpoche;
int months = 1;
int timesec;
int monthDay;
int monthDayRound = llround(monthDay) + 1;
float monthFloat;

int liveJord;
int liveLuft;
int liveTemp;
int FlaktTempSetting;
int luckaTempSetting;

bool fanState;
bool pumpState;
bool hatchState;
bool fanOnWeb;

bool oken;
bool grasmark;
bool regnskog;

int hum;
int temp;
float earthHum;


int TargetTemp;

void setup()
{
  // put your setup code here, to run once:
  timeClient.begin();
  if (!Firebase.beginStream(firebaseData1, path + "/" + nodeID))
  {
    Serial.println("Could not begin stream");
    Serial.println("REASON: " + firebaseData1.errorReason());
  }

  Serial.begin(9600);

  bigHatchServo.attach(D3, 544, 2400);
  fanHatchServo.attach(D4, 544, 2400);
  Wire.begin(14, 12);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(300);
  }

  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());

  pinMode(pumpDir, OUTPUT);
  digitalWrite(pumpDir, HIGH);

  pinMode(fanDir, OUTPUT);
  digitalWrite(fanDir, HIGH);

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);
}

void checkAll()
{
  if (fanState == true)
  {
    if (liveLuft >= FlaktTempSetting) {
      Serial.println("fan-ON");
      analogWrite(fanSpeed, 1023);
      Firebase.setBool(firebaseData1, "/LiveData/fanOnWeb", true);
    }
    else {
      Serial.println("fan-OFF");
      analogWrite(fanSpeed, 0);
      Firebase.setBool(firebaseData1, "/LiveData/fanOnWeb", false);
    }
  }
  else
  {
    Serial.println("fan-OFF");
    analogWrite(fanSpeed, 0);
    Firebase.setBool(firebaseData1, "/LiveData/fanOnWeb", false);
  }

  if (pumpState == true)
  {
    Serial.println("hello");
    if (oken == true)
    {
      if (hours == 15)
      {
        if (minutes == 18)
        {
          Serial.println("pump-ON-Oken");
          digitalWrite(pumpDir, HIGH);
          analogWrite(pumpSpeed, 1023);
        }
        else
        {
          Serial.println("pump-OFF-oken");
          analogWrite(pumpSpeed, 0);
        }
      }
      else
      {
        Serial.println("pump-OFF-oken2");
        analogWrite(pumpSpeed, 0);
      }
    }
    else if (grasmark == true)
    {
      if (liveLuft < 70) {

        if (minutes == 10 || minutes == 30 || minutes == 50)
        {
          Serial.println("pump-ON-Grasmark");
          digitalWrite(pumpDir, HIGH);
          analogWrite(pumpSpeed, 1023);
        }
        else
        {
          Serial.println("pump-OFF");
          analogWrite(pumpSpeed, 0);
        }
      }
      else
      {
        Serial.println("pump-OFF");
        analogWrite(pumpSpeed, 0);
      }
    }
    else if (regnskog == true)
    {
      if (liveLuft < 95) {
        Serial.println(minutes);
        if (minutes == 0 || minutes == 5 || minutes == 10 || minutes == 15 || minutes == 20 || minutes == 25 || minutes == 30 || minutes == 35 || minutes == 40 || minutes == 45 || minutes == 50 || minutes == 55)
        {
          Serial.println(minutes);
          Serial.println("pump-ON-Regnskog");
          digitalWrite(pumpDir, HIGH);
          analogWrite(pumpSpeed, 1023);
        }
        else
        {
          Serial.println("pump-OFF 1");
          analogWrite(pumpSpeed, 0);
          Serial.println(minutes);
        }
      }
      else
      {
        Serial.println("pump-OFF 1");
        analogWrite(pumpSpeed, 0);
        Serial.println(minutes);
      }
    }
  }
  else
  {
    Serial.println("pump-OFF 2");
    analogWrite(pumpSpeed, 0);
    Serial.println(minutes);
  }


  if (hatchState == true)
  {
    if (liveTemp >= luckaTempSetting || fanOnWeb == true) {
      Serial.println("hatch-ON");
      bigHatchServo.write(0);
      fanHatchServo.write(0);
      Firebase.setBool(firebaseData1, "/LiveData/hatchStateWeb", true);
    }
    else {
      Serial.println("hatch-OFF");
      bigHatchServo.write(110);
      fanHatchServo.write(140);
      Firebase.setBool(firebaseData1, "/LiveData/hatchStateWeb", false);
    }
  }
  else
  {
    Serial.println("hatch-OFF");
    bigHatchServo.write(110);
    fanHatchServo.write(140);
    Firebase.setBool(firebaseData1, "/LiveData/hatchStateWeb", false);
  }
}


void updateTime()
{
  timeClient.update();

  minutes = timeClient.getMinutes();
  seconds = timeClient.getSeconds();
  hours = timeClient.getHours() - 1;
  timeEpoche = timeClient.getEpochTime();
  timesec = timeEpoche - 1672517078;
  monthFloat = ((timesec) / 86400);


  for (int i = 0; i < 32; i++) {
    if (monthFloat > i) {
      monthDay = i;
    }
  }

  if (monthDay >= 31 && monthDay <= 59)
  {
    months = 2;
    monthDayRound = llround(monthDay) - 30;
  }
  else if (monthDay >= 59 && monthDay <= 90)
  {
    months = 3;
    monthDayRound = llround(monthDay) - 58;
  }
}

void getTempHum()
{
  if (sensor.measure()) {
    Serial.println("AM2320Working");
  }
  else {
    Serial.print("error:");
    Serial.println(sensor.getErrorCode());
  }
  temp = sensor.getTemperature();
  hum = sensor.getHumidity();
  Serial.print("temp:");
  Serial.println(temp);
  Serial.print("hum");
  Serial.println(hum);

  Firebase.setInt(firebaseData1, "/TempHum/Month" + String(months) + "/days" + String(monthDayRound) + "/Hour" + String(hours) + "/Minute" + String(minutes) + "/humidity", hum);
  Firebase.setInt(firebaseData1, "LiveData/LiveLuft", hum);

  Firebase.setInt(firebaseData1, "/TempHum/Month" + String(months) + "/days" + String(monthDayRound) + "/Hour" + String(hours) + "/Minute" + String(minutes) + "/temperature", temp);
  Firebase.setInt(firebaseData1, "LiveData/LiveTemp", temp);
  Firebase.setInt(firebaseData1, "/TempHum/Month" + String(months) + "/days" + String(monthDayRound) + "/Hour" + String(hours) + "/Minute" + String(minutes) + "/EarthHumidity", 34);
  Firebase.setInt(firebaseData1, "LiveData/LiveJord", 34);

}

void loop()
{
  // put your main code here, to run repeatedly:
  updateTime();

  if (!Firebase.readStream(firebaseData1))
  {
    Serial.println("Can't read stream data");
    Serial.println("REASON: " + firebaseData1.errorReason());
  }
  if (firebaseData1.streamTimeout())
  {
    Serial.println("Stream timeout, resume streaming...");
  }

  if (Firebase.getBool(firebaseData1, "LiveData/fanON"))
  {
    if (firebaseData1.dataType() == "boolean")
    {
      fanState = firebaseData1.boolData();
    }
  }

  if (Firebase.getBool(firebaseData1, "LiveData/HumidifyerOn"))
  {
    if (firebaseData1.dataType() == "boolean")
    {
      pumpState = firebaseData1.boolData();
    }
  }

  if (Firebase.getBool(firebaseData1, "LiveData/hatchState"))
  {
    if (firebaseData1.dataType() == "boolean")
    {
      hatchState = firebaseData1.boolData();
    }
  }
  if (Firebase.getBool(firebaseData1, "dataSettings/grasmark"))
  {
    if (firebaseData1.dataType() == "boolean")
    {
      grasmark = firebaseData1.boolData();
    }
  }
  if (Firebase.getBool(firebaseData1, "dataSettings/regnskog"))
  {
    if (firebaseData1.dataType() == "boolean")
    {
      regnskog = firebaseData1.boolData();
    }
  }
  if (Firebase.getBool(firebaseData1, "dataSettings/oken"))
  {
    if (firebaseData1.dataType() == "boolean")
    {
      oken = firebaseData1.boolData();
    }
  }
  if (Firebase.getInt(firebaseData1, "LiveData/LiveJord") )
  {
    if (firebaseData1.dataType() == "int")
    {
      liveJord = firebaseData1.intData();
    }
  }
  if (Firebase.getInt(firebaseData1, "LiveData/LiveLuft") )
  {
    if (firebaseData1.dataType() == "int")
    {
      liveLuft = firebaseData1.intData();
    }
  }
  if (Firebase.getInt(firebaseData1, "LiveData/LiveTemp") )
  {
    if (firebaseData1.dataType() == "int")
    {
      liveTemp = firebaseData1.intData();
    }
  }
  if (Firebase.getInt(firebaseData1, "dataSettings/FlaktTempSetting") )
  {
    if (firebaseData1.dataType() == "int")
    {
      FlaktTempSetting = firebaseData1.intData();
    }
  }
  if (Firebase.getInt(firebaseData1, "dataSettings/luckaTempSetting") )
  {
    if (firebaseData1.dataType() == "int")
    {
      luckaTempSetting = firebaseData1.intData();
    }
  }
  if (Firebase.getBool(firebaseData1, "LiveData/fanOnWeb"))
  {
    if (firebaseData1.dataType() == "boolean")
    {
      fanOnWeb = firebaseData1.boolData();
    }
  }

  delay(2000);
  checkAll();
  getTempHum();

  delay(2000);
  checkAll();
}
