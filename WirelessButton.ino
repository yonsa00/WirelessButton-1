#include <EEPROM.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <String.h>
#include <ArduinoJson.h>  //https://github.com/bblanchon/ArduinoJson


struct EEPROMAddress {
  int serialNumberAddress = 0;
  int ssidAddress = 25;
  int passwordAddress = 50;
  int hostAddress = 75;
  int portAddress = 100;
  int lineAddress = 110;
  int machineNameAddress = 135;
};
struct IOAddress {
  byte ina = 14;
  byte inb = 13;
  byte inc = 12;

  byte outa = 5;
  byte outb = 4;
  byte outc = 2;
};
int curStateA = 0, curStateB = 0, curStateC = 0, oldStateA, oldStateB, oldStateC;

String serialNumber, line, machineName;
String ssid, password, host, port;

int current_stateA = 0, current_stateB = 0, current_stateC = 0;
int previous_stateA = 0, previous_stateB = 0, previous_stateC = 0;
IOAddress ioAddress;

// Define the size of the JSON buffer
const size_t JSON_BUFFER_SIZE = 512;

// Create a buffer to hold the JSON payload
StaticJsonDocument<JSON_BUFFER_SIZE> jsonBuffer;


void setup() {
  //begin serial and EEPROM
  Serial.begin(9600);


  EEPROM.begin(512);
  EEPROMAddress Address;
  //read value from EEPROM
  serialNumber = read_EEPROM(Address.serialNumberAddress);
  Serial.println(read_EEPROM(Address.ssidAddress));
  ssid = read_EEPROM(Address.ssidAddress);
  password = read_EEPROM(Address.passwordAddress);
  host = read_EEPROM(Address.hostAddress);
  port = read_EEPROM(Address.portAddress);
  line = read_EEPROM(Address.lineAddress);
  machineName = read_EEPROM(Address.machineNameAddress);

  Serial.print("Serial Number :");
  Serial.println(serialNumber);
  Serial.print("Line :");
  Serial.println(line);
  Serial.print("Machine Name :");
  Serial.println(machineName);
  Serial.println("----------------------------------");
  machineName.replace(" ", "%20");
  Serial.println(machineName);
  //initialize IO
  IOAddress ioAddress;
  pinMode(ioAddress.ina, INPUT_PULLUP);
  pinMode(ioAddress.inb, INPUT_PULLUP);
  pinMode(ioAddress.inc, INPUT_PULLUP);
  pinMode(ioAddress.outa, OUTPUT);
  pinMode(ioAddress.outb, OUTPUT);
  pinMode(ioAddress.outc, OUTPUT);

  _connectToWIFI();
  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:

  _databaseRead();
  LED_State();
  current_stateA = digitalRead(ioAddress.ina);
  current_stateB = digitalRead(ioAddress.inb);
  current_stateC = digitalRead(ioAddress.inc);

  if (current_stateA != previous_stateA) {
    if (current_stateA == HIGH && curStateA == 0) {
      curStateA = 1;
      _databaseSend();
    } else if (current_stateA == HIGH && curStateA == 1) {
      curStateA = 0;
      _databaseSend();
    }
  }

  if (current_stateB != previous_stateB) {
    if (current_stateB == HIGH && curStateB == 0) {
      curStateB = 1;
      _databaseSend();
    } else if (current_stateB == HIGH && curStateB == 1) {
      curStateB = 0;
      _databaseSend();
    }
  }

  if (current_stateC != previous_stateC) {
    if (current_stateC == HIGH && curStateC == 0) {
      curStateC = 1;
      _databaseSend();
    } else if (current_stateC == HIGH && curStateC == 1) {
      curStateC = 0;
      _databaseSend();
    }
  }


  previous_stateA = current_stateA;
  previous_stateB = current_stateB;
  previous_stateC = current_stateC;

}
