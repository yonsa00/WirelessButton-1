String _generateUrlUpdate() {

  String apiUrl = "http://";
  apiUrl += String(host);
  apiUrl += "/IGP/";
  apiUrl += "WirelessButton";
  apiUrl += ".php?";
  apiUrl += "mode=update";
  apiUrl += "&Line=" + line;
  apiUrl += "&Status=" + String(curStateA) + String(curStateB) + String(curStateC);
  apiUrl += "&Machine=" + machineName ;
  Serial.println(apiUrl);
  return apiUrl;
}

void _databaseSend() {
  if (WiFi.status() != WL_CONNECTED) {
    _connectToWIFI();
  }
  WiFiClient client;
  HTTPClient http;
  http.begin(client, _generateUrlUpdate());
  int httpCode = http.GET();

  if (httpCode > 0) {
    // HTTP header has been send and Server response header has been handled
    Serial.printf("[HTTP] GET... code: %d\n", httpCode);
    // if (httpCode == HTTP_CODE_OK) {
    //   const String& payload = http.getString();
    //   Serial.println("received payload:\n<<");
    //   Serial.println(payload);
    //   Serial.println(">>");

    //   oldStateA = curStateA;
    //   oldStateB = curStateB;
    //   oldStateC = curStateC;
    // }
  }
  http.end();
}