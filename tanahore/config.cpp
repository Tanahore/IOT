#include "config.h"

const char *ssid = "Tanahore-DT11";
const char *password = "";

WebServer server(80);

String ssidNew = "";
String passNew = "";

void initSetup() {
  Serial.begin(115200);
  delay(1000);
  WiFi.softAP(ssid, password);
  IPAddress IP = WiFi.softAPIP();

  Serial.print("IP Address: ");
  Serial.println(IP);
}