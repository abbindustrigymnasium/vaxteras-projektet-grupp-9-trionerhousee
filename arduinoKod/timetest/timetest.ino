#include <time.h>

const char *ssid = "ABBgym_2 .4#";
const char *password = "mittwifiarsabra";
const char *ntpServer = "pool.ntp.org";
const long gmtOffset_sec = 0;     // Replace with your GMT offset (seconds)
const int daylightOffset_sec = 0; // Replace with your daylight offset (seconds)

void setup()
{
  Serial.begin(115200);
  Serial.printf("Connecting to %s ", ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("CONNECTED to WIFI");

  // init and get the time
  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
  printLocalTime();

  // disconnect WiFi as it's no longer needed
  WiFi.disconnect(true);
  WiFi.mode(WIFI_OFF);
}

void loop()
{
  delay(1000);
  printLocalTime();
}
void printLocalTime()
{
  time_t rawtime;
  struct tm *timeinfo;
  time(&rawtime);
  timeinfo = localtime(&rawtime);
  Serial.println(asctime(timeinfo));
  delay(1000);
}
