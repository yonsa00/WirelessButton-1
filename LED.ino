void _checkLED() {
  digitalWrite(ioAddress.outa, LOW);
  delay(150);
  digitalWrite(ioAddress.outb, HIGH);
  delay(150);
  digitalWrite(ioAddress.outc, HIGH);
  delay(500);
  digitalWrite(ioAddress.outa, HIGH);
  digitalWrite(ioAddress.outb, LOW);
  digitalWrite(ioAddress.outc, LOW);
}

void LED_State() {
  if(curStateA == 1){
    digitalWrite(ioAddress.outa, HIGH);
    Serial.print("Lamp A Active \t");
  } else if(curStateA == 0){
    digitalWrite(ioAddress.outa, LOW);
    Serial.print("Lamp A Inactive \t");
  }
  if(curStateB == 1){
    digitalWrite(ioAddress.outb, HIGH);
    Serial.print("Lamp B Active \t");
  } else if(curStateB == 0){
    digitalWrite(ioAddress.outb, LOW);
    Serial.print("Lamp B Inactive \t");
  }
  if(curStateC == 1){
    digitalWrite(ioAddress.outc, HIGH);
    Serial.print("Lamp C Active \t");
  } else if(curStateC == 0){
    digitalWrite(ioAddress.outc, LOW);
    Serial.print("Lamp C Inactive \t");
  }
}