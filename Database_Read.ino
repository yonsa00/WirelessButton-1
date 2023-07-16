String _generateUrlRead() {

  String apiUrl = "http://";
  apiUrl += String(host);
  apiUrl += "/IGP/";
  apiUrl += "WirelessButton";
  apiUrl += ".php?";
  apiUrl += "mode=read";
  apiUrl += "&Line=" + line;
  apiUrl += "&Machine=M-1%20(D-14)";
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
    if (httpCode == HTTP_CODE_OK) {
      const String& payload = http.getString();
      Serial.println("received payload:\n<<");
      Serial.println(payload);
      // Serial.println(">>");
      DeserializationError error = deserializeJson(jsonBuffer, payload);
      if (error) {
        Serial.print("Failed to parse JSON payload! Error code: ");
        Serial.println(error.c_str());
        return;
      }
      JsonArray data = jsonBuffer["data"];
      for (JsonVariant department : data) {
        // Extract department name and status
        const char* deptName = department["Departement"];
        int deptStatus = department["status"];

        if (strcmp(deptName, "Maintenance") == 0) {
          curStateA = deptStatus;
        }
        if (strcmp(deptName, "QC") == 0) {
          curStateB = deptStatus;
        }
        if (strcmp(deptName, "Supply") == 0) {
          curStateC = deptStatus;
        }
      }
    }
  } else {
    ESP.restart();
  }
  http.end();
}