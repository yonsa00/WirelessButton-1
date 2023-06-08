#include <EEPROM.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <String.h>


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
int curStateA, curStateB, curStateC, oldStateA, oldStateB, oldStateC;

String serialNumber, line, machineName;
String ssid, password, host, port;

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
  machineName.replace(" ","%20");
  Serial.println(machineName);
  //initialize IO
  IOAddress ioAddress;
  pinMode(ioAddress.ina, INPUT);
  pinMode(ioAddress.inb, INPUT);
  pinMode(ioAddress.inc, INPUT);
  pinMode(ioAddress.outa, OUTPUT);
  pinMode(ioAddress.outb, OUTPUT);
  pinMode(ioAddress.outc, OUTPUT);

  _connectToWIFI();
  _checkLED();
  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
  IOAddress ioAddress;

  if (digitalRead(ioAddress.ina) == LOW) {
    digitalWrite(ioAddress.outa, HIGH);
    Serial.print("Lamp A Active \t");
    curStateA = 1;
  } else {
    digitalWrite(ioAddress.outa, LOW);
    Serial.print("Lamp A InActive \t");
    curStateA = 0;
  }

  if (digitalRead(ioAddress.inb) == LOW) {
    digitalWrite(ioAddress.outb, HIGH);
    Serial.print("Lamp B Active \t");
    curStateB = 1;
  } else {
    digitalWrite(ioAddress.outb, LOW);
    Serial.print("Lamp B InActive \t");
    curStateB = 0;
  }

  if (digitalRead(ioAddress.inc) == LOW) {
    digitalWrite(ioAddress.outc, LOW);
    Serial.println("Lamp C Active");
    curStateC = 1;
  } else {
    digitalWrite(ioAddress.outc, HIGH);
    Serial.println("Lamp C InActive");
    curStateC = 0;
  }


  // if (curStateA != oldStateA || curStateB != oldStateB || curStateC != oldStateC) {
  //   _databaseSend();
  // }
  _databaseSend();
}
