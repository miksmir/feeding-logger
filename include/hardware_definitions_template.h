#ifndef HARDWARE_DEFINITIONS_H
#define HARDWARE_DEFINITIONS_H

// NOTE: This is a template for hardware_definitions.h
// Please fill in your own SSID and password here and rename the file to hardware_definitions.h in the main file. 

#define BUTTON_PIN 23

#define OLED

#define BAUD_RATE 921600

const char* SSID = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PASSWORD";

const char* ntpServer = "pool.ntp.org";
const long  gmtOffset_sec = 18000;
const int   daylightOffset_sec = 3600;















#endif // End the definition-ing of the hardware if this header was not defined/included perviously