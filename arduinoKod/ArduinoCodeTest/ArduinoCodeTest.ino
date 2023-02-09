
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
const byte pumpDir = 2;

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
int months = 1;
int timesec;
int monthDay;
int monthDayRound = llround(monthDay) + 1;

int fanVal;
int pumpVal;

float earthHum;

bool fanState;
bool pumpState;
bool gateOpen;

int hum;
int temp;

void setup() {
  // put your setup code here, to run once:
  
    Serial.begin(9600);
    servot.attach(D1);
    servot2.attach(D2);
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

void loop() {
  // put your main code here, to run repeatedly:
  
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



   if (Firebase.getInt(firebaseData2, "LiveData/Fan-speed")) {
    if (firebaseData2.dataType()== "int"){
      fanVal = firebaseData2.intData();   
    }
   }
   if (Firebase.getBool(firebaseData2, "LiveData/fanON")) {
    if (firebaseData2.dataType()== "boolean"){
      fanState = firebaseData2.boolData();
    }
   }



  if (fanState) {
    fanOn();
  }
  else {
    fanOff();
  }


   if (Firebase.getInt(firebaseData2, "LiveData/pumpSpeed")) {
    if (firebaseData2.dataType()== "int"){
      pumpVal = firebaseData2.intData();
    }
   }
   if (Firebase.getBool(firebaseData2, "LiveData/HumidifyerOn")) {
     if (firebaseData2.dataType()== "boolean"){
      pumpState = firebaseData2.boolData();
    }
   }

   if (pumpState) {
    pumpOn();
   }
   else {
    pumpOff();
   }



   
   if (Firebase.getBool(firebaseData2, "LiveData/GateOpen")) {
      Serial.println(firebaseData2.dataType());
    if (firebaseData2.dataType()== "boolean"){
       gateOpen = firebaseData2.boolData();
    }
  }


  if (gateOpen) {
   fanHatchOpen();
   bigHatchOpen();
  }
  else {
   fanHatchClosed();
   bigHatchClosed();
  }

   
}

//fan functions
void fanOn(){
  digitalWrite(fanDir, LOW);
  analogWrite(fanSpeed, fanVal);
}

void fanOff(){
  analogWrite(fanSpeed, 0);
}


//Waterpump functions
void pumpOn(){
  digitalWrite(pumpDir, LOW);
  analogWrite(pumpSpeed, pumpVal);
}
void pumpOff(){
  analogWrite(pumpSpeed, 0);
}


//fanhatch functions
void fanHatchOpen(){
   servot.write(0);
}
void fanHatchClosed(){
   servot.write(180);
}


//Big hatch functions
void bigHatchOpen(){
   servot2.write(180);
}
void bigHatchClosed(){
   servot2.write(0);
}
