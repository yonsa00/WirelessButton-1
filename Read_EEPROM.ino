String read_EEPROM(int addrOffset) {
  int newStrLen = EEPROM.read(addrOffset);
  Serial.println(newStrLen);
  char data[newStrLen + 1];
  for (int i = 0; i < newStrLen; i++) {
    data[i] = EEPROM.read(addrOffset + 1 + i);
    Serial.println(data[i]);
  }
  data[newStrLen] = '\0';  // !!! NOTE !!! Remove the space between the slash "/" and "0" (I've added a space because otherwise there is a display bug)
  return String(data);
}