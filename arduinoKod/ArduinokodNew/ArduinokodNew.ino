//includes al needed libraries

#include <FirebaseESP8266.h>
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <NTPClient.h>
#include <Wire.h>
#include <AM2320.h>
#include <Servo.h>

AM2320 sensor;
Servo servot;
Servo servot2;

//defines where we should conect to firebase via the webb with the wifi name and pasword

#define FIREBASE_HOST "https://waxteras-default-rtdb.europe-west1.firebasedatabase.app"
#define FIREBASE_AUTH "AIzaSyBslwY7gKcIWTltrOcEeDooZWzSRRcSBUg"
#define WIFI_SSID "ABBgym_2.4"
#define WIFI_PASSWORD "mittwifiarsabra"

//#define WIFI_SSID "Almesbo_wifi"
//#define WIFI_PASSWORD "KottenAlmesbo"

//Define Firebase Data objects
FirebaseData firebaseData1;
FirebaseData firebaseData2;

const byte fanSpeed = 5;
const byte fanDir = 0;
const byte pumpSpeed = 4;
const byte PumpDir = 2;

const int ledPin = 4; //GPIO4 or D2 for LED
const int swPin = 5;  //GPIO5 or D1 for Switch
bool swState = false;
String path = "/Nodes";
String nodeID = "Node2";      //This is this node ID to receive control
String otherNodeID = "Node1"; //This is other node ID to control

//setting up time and timezone

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org", 7200, 60000);

String Time;
int days;
int hours;
int minutes;
int timeEpoche;
float monthDay;
int months = 1;
int timesec;

int potVal;
int pumpVal;

float earthHum;

bool fanOn;
bool pumpOn;
bool gateOpen;

int hum;
int temp;



void setup()
{

    Serial.begin(9600);
    servot.attach(D1);
    servot2.attach(D1);
    Wire.begin(14,12);

    WiFi.begin(WIFI_SSID, WIFI_PASSWORD );
    Serial.print("Connecting to Wi-Fi");
    while (WiFi.status() != WL_CONNECTED){
        delay(300);
    }

    Serial.print("Connected with IP: ");
    Serial.println(WiFi.localIP());

    pinMode(fanDir, OUTPUT);
    digitalWrite(fanDir, HIGH);
    

    Firebase.begin(FIREBASE_HOST,FIREBASE_AUTH );
    Firebase.reconnectWiFi(true);

    timeClient.begin();
    if (!Firebase.beginStream(firebaseData1, path + "/" + nodeID))
    {
        Serial.println("Could not begin stream");
        Serial.println("REASON: " + firebaseData1.errorReason());
    }
}



void loop()
{
    if (!Firebase.readStream(firebaseData1)){
        Serial.println("Can't read stream data");
        Serial.println("REASON: " + firebaseData1.errorReason());
    }
    if (firebaseData1.streamTimeout()){
        Serial.println("Stream timeout, resume streaming...");
    }

  timeClient.update();
  
  minutes = timeClient.getMinutes();
  hours = timeClient.getHours() - 1;
  timeEpoche = timeClient.getEpochTime();
  timesec = timeEpoche - 1672517078;
  monthDay = ((timesec)/86400);
  int monthDayRound = llround(monthDay) + 1;

  int potVal = Firebase.getInt(firebaseData2, "LiveData/Fan-speed");

    if (Firebase.getInt(firebaseData2, "LiveData/Fan-speed")) {
    if (firebaseData2.dataType()== "int"){
      potVal = firebaseData2.intData();   
    }}
    if (Firebase.getBool(firebaseData2, "LiveData/FanOn")) {
    if (firebaseData2.dataType()== "boolean")
    {
      fanOn = firebaseData2.boolData();
    }
  }
  Serial.println(pumpVal);
  if (fanOn) {
    digitalWrite(fanDir, LOW);
    analogWrite(fanSpeed, potVal);
  }
  digitalWrite(fanDir, LOW);
  analogWrite(fanSpeed, potVal);

  if (Firebase.getInt(firebaseData2, "LiveData/pumpSpeed")) {
    if (firebaseData2.dataType()== "int"){
      pumpVal = firebaseData2.intData();
    }
  }
    if (Firebase.getBool(firebaseData2, "LiveData/HumidifyerOn")) {
      if (firebaseData2.dataType()== "boolean"){
      pumpOn= firebaseData2.boolData();
    }}
    
  Serial.println(potVal);
  if (pumpOn) {
    digitalWrite(PumpDir, HIGH);
    analogWrite(pumpSpeed, pumpVal);
  }
  if (Firebase.getBool(firebaseData2, "LiveData/GateOpen")) {
      Serial.println(firebaseData2.dataType());
    if (firebaseData2.dataType()== "boolean"){
       gateOpen = firebaseData2.boolData();
    }}


  Serial.print("Gate:");
  Serial.println(gateOpen);
  
  Serial.print("monthDayRound");
  Serial.println(monthDayRound);
  Serial.print("hours");
  Serial.println(hours);
  Serial.print("minutes");
  Serial.println(minutes);
 
  if (monthDay >= 30) {
  months = months + 1;
  }
  
  if (sensor.measure()) {
    Serial.println("nice");
  }
  else{
    Serial.print("error:");
    Serial.println(sensor.getErrorCode());
  }
  temp = sensor.getTemperature();
  hum = sensor.getHumidity();
  Serial.print("temp:");
  Serial.println(temp);
  Serial.print("hum");
  Serial.println(hum);


  if (gateOpen == 0) {
    servot.write(180);
    servot2.write(180);
  }
  else {
    servot.write(360);
    servot2.write(360);
  }
    

  Firebase.setInt(firebaseData2, "/TempHum/Month" + String(months) + "/days" + String(monthDayRound) + "/Hour-" + String(hours) + "/Minute" + String(minutes) + "/humidity", hum);
  Firebase.setInt(firebaseData2, "LiveData/LiveLuft", hum);
  
  Firebase.setInt(firebaseData2, "/TempHum/Month" + String(months) + "/days" + String(monthDayRound) + "/Hour-" + String(hours) + "/Minute" + String(minutes) + "/temperature", temp);
  Firebase.setInt(firebaseData2, "LiveData/LiveTemp", temp);
  Firebase.setInt(firebaseData2, "/TempHum/Month" + String(months) + "/days" + String(monthDayRound) + "/Hour-" + String(hours) + "/Minute" + String(minutes) + "/EarthHumidity", 34);
  Firebase.setInt(firebaseData2, "LiveData/LiveJord", 34);

  
  delay(500);
}
