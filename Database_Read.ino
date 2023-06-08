String _generateUrlRead() {

  String apiUrl = "http://";
  apiUrl += String(host);
  apiUrl += "/IGP/";
  apiUrl += "WirelessButton";
  apiUrl += ".php?";
  apiUrl += "mode=read";
  apiUrl += "&Line=" + line;
  apiUrl += "&Machine=S-1%20(NEW)" ;
  Serial.println(apiUrl);
  return apiUrl;
}

void _databaseRead() {
  if (WiFi.status() != WL_CONNECTED) {
    _connectToWIFI();
  }
  WiFiClient client;
  HTTPClient http;
  http.begin(client, _generateUrlRead());
  int httpCode = http.GET();

  if (httpCode > 0) {
    // HTTP header has been send and Server response header has been handled
    Serial.printf("[HTTP] GET... code: %d\n", httpCode);
    if (httpCode == HTTP_CODE_OK) {
      const String& payload = http.getString();
      Serial.println("received payload:\n<<");
      Serial.println(payload);
      Serial.println(">>");

      oldStateA = curStateA;
      oldStateB = curStateB;
      oldStateC = curStateC;
    }
  }
  http.end();
}