#include <NTPClient.h>
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

const char *ssid     = "internet";
const char *password = "password";

const long utcOffsetInSeconds = 3600;

char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

// Define NTP Client to get time
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org", utcOffsetInSeconds);

float startTime = 0;


/*
    WL_NO_SHIELD        = 255,   // for compatibility with WiFi Shield library
    WL_IDLE_STATUS      = 0,
    WL_NO_SSID_AVAIL    = 1,
    WL_SCAN_COMPLETED   = 2,
    WL_CONNECTED        = 3,
    WL_CONNECT_FAILED   = 4,
    WL_CONNECTION_LOST  = 5,
    WL_DISCONNECTED     = 6
*/

void setup() {
  Serial.begin(115200);
  Serial.println("");
  Serial.println("");

  pinMode(LED_BUILTIN, OUTPUT);

  WiFi.begin(ssid, password);

  Serial.println("");
  Serial.print("WiFi Status: ");
  Serial.println(WiFi.status());

  Serial.print("Searching...");

  while ( WiFi.status() != WL_CONNECTED ) {

    screamForWifi();
  }

  Serial.println("");
  Serial.print("WiFi Status: ");
  Serial.println(WiFi.status());

  Serial.println();
  Serial.print("MAC: ");
  Serial.println(WiFi.macAddress());
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());

  Serial.println("");
  Serial.println("");
  
  timeClient.begin();
}

void loop() {
  timeClient.update();
  Serial.print(daysOfTheWeek[timeClient.getDay()]);
  Serial.print(", ");
  Serial.print(timeClient.getHours());
  Serial.print(":");
  Serial.print(timeClient.getMinutes());
  Serial.print(":");
  Serial.println(timeClient.getSeconds());
  //Serial.println(timeClient.getFormattedTime());

  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("");
    Serial.println("Searching");
    startTime = millis();

    while (WiFi.status() != WL_CONNECTED) {
      screamForWifi();
      Serial.print("Wifi Status: ");
      Serial.println(WiFi.status());
    }
  }

  Blink();
  delay(10000);
}

void screamForWifi() {
  

  if (millis() - startTime > 1000) {
    startTime = millis();
    Serial.print(".");
  }


  Led(true);
  delay(100);
  Led(false);
  delay(100);
}

void Blink() {
  Led(true);
  delay(50);
  Led(false);
}

void Led(bool onOff) {
  digitalWrite(LED_BUILTIN, !onOff);
}
