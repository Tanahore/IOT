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
    String status = getDeviceStatus();
    if(status == "on") {
      float temperatureC = sensors.getTempCByIndex(0);
      int lightIntensity = analogRead(LightIntensity);
      int humidity = analogRead(Humidity);
      float phInput = analogRead(Acidity);
      float ph = (-0.0139 * phInput) + 7.7851;

      Serial.println("suhu :" + String(temperatureC));
      Serial.println("cahaya :" + String(lightIntensity));
      Serial.println("kelembapan :" + String(humidity));
      Serial.println("ph: " + String(ph));

      status = "off";
      updateDeviceStatus(status);
      updateDeviceInput(ph, humidity, temperatureC, lightIntensity);
    }
    delay(2000);
  }
}
