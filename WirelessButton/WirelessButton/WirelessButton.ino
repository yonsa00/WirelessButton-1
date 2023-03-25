#include <PCF8574.h>
#include <Wire.h>
// #if defined(ESP32)
// #include "HTTPClient.h"
// #include <WiFi.h>
// #elif defined(ESP8266)
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
// #endif

PCF8574 pcf1(0x21);
PCF8574 pcf2(0x20);

PCF8574 pcf[2] = { pcf1, pcf2 };

//WiFi MAST - PMST 006
// const char* ssid = "MAST-Group";
// const char* password = "jlsrbz20@3";
// const char* localhost = "192.168.0.148";
//WiFi Parallax - Laptop Adhia
const char* ssid = "Parallax";
const char* password = "KmzWay87AA";
const char* localhost = "192.168.54.29";

int PCFValue1, previousPCFValue1;
int PCFValue2, previousPCFValue2;
int MasterValue = 1;
int x = 0, y = 0;
String LineName = "sub_assy";
String PCFString1, PCFString2;
String ConvertPCF;

WiFiClient client;
HTTPClient http;

void setup() {
  Serial.begin(115200);
  Wire.begin();
  //PCF starting
  pcf1.begin();
  pcf2.begin();
  //WiFi Connecting
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("Connected");
}

void loop() {
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 8; j = j + 2) {
        ConvertPCF += pcf[i].readButton(j);
        // x += 2;
        // y += 2;
      }
    }
    for (int k = 0; k < 2; k++) {
      for (int l = 1; l < 8; l = l + 2) {
        ConvertPCF += pcf[k].readButton(l);
        // x += 2;
        // y += 2;
      }
    }
    // x = 2;
    // y = 1;
  
  Serial.println(ConvertPCF);
  delay(500);
  // if (PCFString2 != previousPCFValue1) {

    Updated();
  //   previousPCFValue1 = PCFString2;
  // }
  ConvertPCF = "";
}
