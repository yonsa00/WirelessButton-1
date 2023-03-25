void Updated() {
  String serverName = "http://";
  serverName += localhost;
  serverName += "/WirelessButton/WirelessButton.php?";
  serverName += "&mode=save";
  serverName += "&Device=" + String(LineName);
  serverName += "&Status=" + String(ConvertPCF);
  serverName += "&Master=" + String(MasterValue);
  http.begin(client, serverName);
  Serial.println(serverName);
  client.print(serverName);
  int httpCode = http.GET();
  String payload = "";
  payload = http.getString();
}