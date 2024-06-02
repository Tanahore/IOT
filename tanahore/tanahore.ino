#include "ServerRoutes.h"
#include "config.h"
#include "firebase.h"

void setup(void) {
  initSetup();
  setupRoutes(server);
  sensors.begin();
  server.begin();
  setupFirebase();

  Serial.println("HTTP server started");
}

void loop(void) {
  if (ssidNew == "") {
    server.handleClient();
  } else {
    Serial.println("Yeay Terhubung!!!!");
    sensors.requestTemperatures();
    float temperatureC = sensors.getTempCByIndex(0);
    int lightIntensity = analogRead(LightIntensity);
    int humidity = analogRead(Humidity);
    float phInput = analogRead(Acidity);
    float ph = (-0.0139 * phInput) + 7.7851;
    delay(1000);
  }
}
