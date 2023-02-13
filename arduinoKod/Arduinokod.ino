#include <FirebaseESP8266.h>
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

#define FIREBASE_HOST "https://waxteras-default-rtdb.europe-west1.firebasedatabase.app"
#define FIREBASE_AUTH "AIzaSyBslwY7gKcIWTltrOcEeDooZWzSRRcSBUg"
#define WIFI_SSID "ABBgym_2.4"
#define WIFI_PASSWORD "mittwifiarsabra"


//Define Firebase Data objects
FirebaseData firebaseData1;
FirebaseData firebaseData2;

const int ledPin = 4; //GPIO4 or D2 for LED
const int swPin = 5;  //GPIO5 or D1 for Switch
bool swState = false;
String path = "/Nodes";
String nodeID = "Node2";      //This is this node ID to receive control
String otherNodeID = "Node1"; //This is other node ID to control


void setup()
{

    Serial.begin(9600);

    pinMode(ledPin, OUTPUT);
    pinMode(swPin, INPUT);

    Serial.println("aaaa");
    Serial.println("uhu");

    WiFi.begin(WIFI_SSID, WIFI_PASSWORD );
    Serial.print("Connecting to Wi-Fi");
    while (WiFi.status() != WL_CONNECTED)
    {
        Serial.print("h");
        delay(300);
    }
    Serial.println("nu");
    Serial.print("Connected with IP: ");
    Serial.println(WiFi.localIP());
    Serial.println("när");

    Firebase.begin(FIREBASE_HOST,FIREBASE_AUTH );
    Firebase.reconnectWiFi(true);

    if (!Firebase.beginStream(firebaseData1, path + "/" + nodeID))
    {
        Serial.println("Could not begin stream");
        Serial.println("REASON: " + firebaseData1.errorReason());
        Serial.println("bre");
    }
}

void loop()
{
    if (!Firebase.readStream(firebaseData1))
    {
        Serial.println("hum");
        Serial.println("Can't read stream data");
        Serial.println("REASON: " + firebaseData1.errorReason());
        Serial.println("skum");
    }

    if (firebaseData1.streamTimeout())
    {
        Serial.println("fusk");
        Serial.println("Stream timeout, resume streaming...");
        Serial.println("tusk");
    }

  Firebase.setInt(firebaseData2, "/seb/sim",82);
}
