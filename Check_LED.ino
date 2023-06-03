void _checkLED() {
  IOAddress ioAddress;
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