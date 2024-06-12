#include <WiFi.h>
#include <WebServer.h>
#include "ServerRoutes.h"
#include "config.h"
#include "firebase.h"

#define LightIntensity A1
#define Humidity A0
#define Acidity A2

void setup(void) {
  initSetup();
  setupRoutes(server);
  Serial.println("Dallas Temperature Sensor Example");
  server.begin();  // Start the server
}

void loop(void) {
  if (ssidNew == "") {
    server.handleClient();
    Serial.println("Handling client");
  } else {
    WiFi.mode(WIFI_OFF);
    delay(10);
    
    int lightIntensity = analogRead(LightIntensity);
    int humidity = analogRead(Humidity);
    float phInput = analogRead(Acidity);
    float ph = (-0.0139*phInput)+7.7851;

    Serial.print("pH off: ");
    Serial.println(ph);

    Serial.print("Humidity: ");
    Serial.print(humidity / 10);
    Serial.println("%");

    Serial.print("Light Intensity: ");
    Serial.println(lightIntensity / 2);

    WiFi.begin(ssidNew.c_str(), passNew.c_str());
    setupFirebase();
    String status = getDeviceStatus();
    if (status == "on") {
      Serial.println("Yeay Terhubung!!!!");
      status = "off";
      if (ph > 1) {
        updateDeviceInput(ph, humidity/10, 33.5, lightIntensity/2);
        updateDeviceStatus(status);
      }
    }
  }
  delay(1000);
}
