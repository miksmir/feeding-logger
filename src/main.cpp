#include "hardware_definitions.h"

#include <Arduino.h>
#include <WiFi.h>
#include "time.h"

//#include <catlog.h>

void printLocalTime()
{
  struct tm timeinfo;
  if(!getLocalTime(&timeinfo)){
    Serial.println("Failed to obtain time");
    return;
  }
  Serial.println(&timeinfo, "%A, %B %d %Y %H:%M:%S");
}

void setup()
{

  Serial.begin(BAUD_RATE);
  pinMode(BUTTON_PIN, INPUT_PULLUP); // For button

  //connect to WiFi
  Serial.printf("Connecting to %s ", SSID);
  WiFi.begin(SSID, password);

  uint8_t timeout_counter = 0;
  while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
      timeout_counter++;
      if(timeout_counter > 59){ // After 30 seconds,
        Serial.print("ERROR: WIFI Connection Attempt Timed Out");
      }
  }
  Serial.println("WIFI CONNECTED");
  
  //init and get the time
  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
  printLocalTime();

  //disconnect WiFi as it's no longer needed
  // After receiving the time from the NTP server, the device stores it locally in its internal clock.
  WiFi.disconnect(true);
  WiFi.mode(WIFI_OFF);
}

void loop()
{
  //delay(1000);
  //printLocalTime();
  delay(100);
  if(digitalRead(BUTTON_PIN)){
    Serial.println("Button Released");
  }
  else{
    Serial.println("Button Pressed");
  }
  Serial.println(digitalRead(BUTTON_PIN)); // 1 if released, 0 if pressed

  /*
  while(button==NOTPRESSED){
    delay(1000);
    printLocalTime();
  }
  */

  /*
  Serial.println("Logging current time");
  int connected = checkConnection();
  delay(1000);

  if(connected == 1){
    refreshTime();
  }
  else {
    Serial.println("Connection timed out");
    delay(3000;)
    //Wifi.disconnect();
    //Wifi.reconnect();
    Serial.println("Please reset with "\EN"\.");
  }

  */
}

/*
  int checkConnection(){
    if(Wifi.status()==WL_Connected){
      return 1;
    }
    else {
      return 0;
    }
  }
*/
