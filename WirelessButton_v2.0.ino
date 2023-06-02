#include <EEPROM.h>

byte ina = 12;
byte inb = 13;
byte inc = 14;

byte outa = 2;
byte outb = 4;
byte outc = 5;

unsigned long cur_timeA, old_timeA, cur_timeB, old_timeB, cur_timeC, old_timeC;
int stateA, stateB, stateC;
int serialNumberAddress = 0, lineAddress = 25, machineNameAdddress = 50;
String serialNumber, line, machineName;

void setup() {
  //begin serial and EEPROM
  Serial.begin(9600);
  EEPROM.begin(512);

  //read value from EEPROM
  serialNumber = read_EEPROM(serialNumberAddress);
  line = read_EEPROM(lineAddress);
  machineName = read_EEPROM(machineNameAdddress);
  Serial.print("Serial Number :");
  Serial.println(serialNumber);
  Serial.print("Line :");
  Serial.println(line);
  Serial.print("Machine Name :");
  Serial.println(machineName);
  Serial.println("----------------------------------");

  //initialize IO
  pinMode(ina, INPUT);
  pinMode(inb, INPUT);
  pinMode(inc, INPUT);
  pinMode(outa, OUTPUT);
  pinMode(outb, OUTPUT);
  pinMode(outc, OUTPUT);
  delay(5000);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(ina) == LOW) {
    digitalWrite(outa, LOW);
    Serial.print("Lamp A Active \t");
    stateA = 1;
  } else {
    digitalWrite(outa, HIGH);
    Serial.print("Lamp A InActive \t");
    stateA = 0;
  }

  if (digitalRead(inb) == LOW) {
    digitalWrite(outb, HIGH);
    Serial.print("Lamp B Active \t");
    stateB = 1;
  } else {
    digitalWrite(outb, LOW);
    Serial.print("Lamp B InActive \t");
    stateB = 0;
  }

  if (digitalRead(inc) == LOW) {
    digitalWrite(outc, HIGH);
    Serial.println("Lamp C Active");
    stateC = 1;
  } else {
    digitalWrite(outc, LOW);
    Serial.println("Lamp C InActive");
    stateC = 0;
  }
}
