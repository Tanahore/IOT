#include <OneWire.h>
#include <DallasTemperature.h>
#include <WiFi.h>
#include <WebServer.h>
#include "ServerRoutes.h"

#define ONE_WIRE_BUS D0
#define LightIntensity A1
#define Humidity A0
#define Acidity A2

#define WIFI_SSID "RINA"
#define WIFI_PASS "16012012Dharma"

const char *ssid = "Tanahore-DT11";
const char *password = "";

WebServer server(80);

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire); 

String ssidNew = "";
String passNew = "";

void setup(void) {
  Serial.begin(115200);
  delay(1000);
  WiFi.softAP(ssid, password);
  IPAddress IP = WiFi.softAPIP();

  Serial.print("IP Address: ");
  Serial.println(IP);

  // WiFi.begin(WIFI_SSID, WIFI_PASS);
  // while (WiFi.status() != WL_CONNECTED) {
  //       delay(100);
  //       Serial.print(".");
  // }
  // if (WiFi.status() != WL_CONNECTED) {
  //     Serial.println("Failed to co cpnnect to wifi");
  // } else {
  //     Serial.println("connected");
  //     Serial.println(WiFi.localIP());
  // }

  setupRoutes(server);  // Tidak perlu ssidNew dan passNew
  sensors.begin();
  server.begin();

  Serial.println("HTTP server started");
}

void loop(void) {
  if (ssidNew == "") {
    server.handleClient();
  } else {
    Serial.println("Yeay Terhubung!!!!");
    float temperatureC = sensors.getTempCByIndex(0);
    int lightIntensity = analogRead(LightIntensity);
    int humidity = analogRead(Humidity);
    float phInput = analogRead(Acidity);
    float ph = (-0.0139 * phInput) + 7.7851;
    sensors.requestTemperatures();
    delay(1000);
  }
}
