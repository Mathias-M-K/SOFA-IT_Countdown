#include <NTPClient.h>
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <TimeLib.h>

//Wifi information
const char *ssid     = "Martin Router King";
const char *password = "password";

const long utcOffsetInSeconds = 3600;

// Define NTP Client to get time
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org", utcOffsetInSeconds);

//Creating list with the dates on which the fridge will be emptied
time_t dates[30];
int nrOfDates = 0;

//byte Day = 6;
//byte Month = 3;
//int Year = 2020;

//tmElements_t tm;

void setup() {
  addDate(26, 2, 2020, 01, 30, 00);
  addDate(26, 2, 2020, 15, 30, 00);
  addDate(27, 2, 2020, 15, 30, 00);
  addDate(20, 2, 2020, 14, 52, 00);
  addDate(20, 2, 2020, 17, 52, 00);
  addDate(29, 4, 2020, 14, 52, 00);
  addDate(30, 11, 2020, 14, 52, 00);
  addDate(21, 2, 2020, 14, 52, 00);
  addDate(6, 3, 2020, 14, 52, 00);
  addDate(20, 3, 2020, 14, 52, 00);
  addDate(3, 4, 2020, 14, 52, 00);
  addDate(17, 4, 2020, 14, 52, 00);
  addDate(1, 5, 2020, 14, 52, 00);

  Serial.begin(115200);
  Serial.println("");
  Serial.println("");

  WiFi.begin(ssid, password);
  Serial.print("Connecting to "); Serial.println(ssid);
  Serial.print("WiFi Status: "); Serial.println(wl_status_to_string(WiFi.status()));

  Serial.print("Searching...");

  while ( WiFi.status() != WL_CONNECTED ) {
    delay ( 500 );
    Serial.print ( "." );
  }

  Serial.println();
  Serial.print("WiFi Status: "); Serial.println(wl_status_to_string(WiFi.status()));
  Serial.print("MAC: "); Serial.println(WiFi.macAddress());
  Serial.print("IP: "); Serial.println(WiFi.localIP());
  Serial.println();

  timeClient.begin();
}

void loop() {
  timeClient.update();

  Serial.print("Time Now : ");
  printDate(timeClient.getEpochTime());
  Serial.println("");

  Serial.print("Time Next: ");
  printDate(getEarliestDate());
  Serial.println("");

  Serial.print("Time to 0: ");
  Serial.println(howLongTilDate(dates[0]));

  Serial.print("Time to 1: ");
  Serial.println(howLongTilDate(dates[1]));

  Serial.print("Time to 2: ");
  Serial.println(howLongTilDate(dates[2]));




  delay(5000);
  //time_t nextMakeTime;


  //tm.Second = in;
  //tm.Hour = in;
  //tm.Minute = in;
  //tm.Day = Day;
  //tm.Month = Month;
  //tm.Year = Year - 1970;

  //nextMakeTime = makeTime(tm);

  //float secondsToNextEmpty = nextMakeTime - timeClient.getEpochTime();

  //Serial.print("Days til next fridge purge: ");
  //Serial.println(round(secondsToNextEmpty / 60 / 60 / 24));

  return;

  if (WiFi.status() != WL_CONNECTED) {
    Serial.print("Wifi Status: ");
    Serial.println(wl_status_to_string(WiFi.status()));
    Serial.print("Connecting to ");
    Serial.println(ssid);

    while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
    }
  }

  delay(500);
}

//in seconds
String howLongTilDate(time_t date) {
  String text;
  float numberToPrint;
  float secondsToTime = getTimeToDate(date);

  

  text = "";
  numberToPrint = secondsToTime;
  Serial.print("numberToPrint1: ");Serial.println(numberToPrint);

  if ((secondsToTime / 60) > 1) {
    text = " minutes left";
    numberToPrint = round((secondsToTime / 60) - 0.5);

    if ((secondsToTime / 60 / 60) > 1) {
      text = " hours left";
      numberToPrint = round((secondsToTime / 60 / 60) - 0.5);

      if ((secondsToTime / 60 / 60 / 24) > 1) {
        text = " Days left";
        numberToPrint = round((secondsToTime / 60 / 60 / 24) + 0.5);
      }
    }
  }else{
    Serial.print("numberToPrint2: ");Serial.println(numberToPrint);
    return (String)numberToPrint;
  }
  Serial.print("numberToPrint3: ");Serial.println(numberToPrint);
  int i = (int) numberToPrint;

  String number = (String)i;
  return number + text;
}

float getTimeToDate(time_t date) {
  float nextDate = date;
  float timeNow = timeClient.getEpochTime();

  return nextDate - timeNow;
}

time_t getEarliestDate() {

  time_t earliestDate = 301195;

  for (int i = 0; i <= nrOfDates; i++) {
    float timeNow = timeClient.getEpochTime();
    float date = dates[i];

    if (date - timeNow < 0) {
      continue;
    }
    if (earliestDate == 301195) {
      earliestDate = date;
      continue;
    }
    if (date - timeNow < earliestDate - timeNow) {
      earliestDate = date;
    } else {
    }
  }
  return earliestDate;
}

void addDate(byte _day, byte _month, int _year, int _hour, int _minute, int _second) {
  tmElements_t tm;
  tm.Second = _second;
  tm.Hour = _hour;
  tm.Minute = _minute;
  tm.Day = _day;
  tm.Month = _month;
  tm.Year = _year - 1970;

  time_t t = makeTime(tm);

  dates[nrOfDates] = t;

  nrOfDates++;
}

void printDate(time_t _time) {
  Serial.print("Date: "); Serial.print(day(_time));
  Serial.print("/"); Serial.print(month(_time));
  Serial.print("-"); Serial.print(year(_time));
  Serial.print(" "); Serial.print(hour(_time));
  Serial.print(":"); Serial.print(minute(_time));
  Serial.print(":"); Serial.print(second(_time));
}

const char* wl_status_to_string(wl_status_t status) {
  switch (status) {
    case WL_NO_SHIELD: return "WL_NO_SHIELD";
    case WL_IDLE_STATUS: return "WL_IDLE_STATUS";
    case WL_NO_SSID_AVAIL: return "WL_NO_SSID_AVAIL";
    case WL_SCAN_COMPLETED: return "WL_SCAN_COMPLETED";
    case WL_CONNECTED: return "WL_CONNECTED";
    case WL_CONNECT_FAILED: return "WL_CONNECT_FAILED";
    case WL_CONNECTION_LOST: return "WL_CONNECTION_LOST";
    case WL_DISCONNECTED: return "WL_DISCONNECTED";
  }
}
