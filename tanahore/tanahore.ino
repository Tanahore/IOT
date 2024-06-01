#include <OneWire.h>
#include <DallasTemperature.h>
#include <WiFi.h>

#define ONE_WIRE_BUS D0
#define LightIntensity A1
#define Humidity A0
#define Acidity A2

#define WIFI_SSID "RINA"
#define WIFI_PASS "16012012Dharma"

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire); 

void setup(void) {
  Serial.begin(115200);
  WiFi.begin(WIFI_SSID, WIFI_PASS);
  while (WiFi.status() != WL_CONNECTED) {
        delay(100);
        Serial.print(".");
  }
  if (WiFi.status() != WL_CONNECTED) {
      Serial.println("Failed to co cpnnect to wifi");
  } else {
      Serial.println("connected");
      Serial.println(WiFi.localIP());
  }
  sensors.begin();
}

void loop(void) {
  sensors.requestTemperatures();

  float temperatureC = sensors.getTempCByIndex(0);
  int lightIntensity = analogRead(LightIntensity);
  int humidity = analogRead(Humidity);
  float phInput = analogRead(Acidity);
  float ph = (-0.0139 * phInput) + 7.7851;

  delay(1000);
}