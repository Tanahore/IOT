#include "ServerRoutes.h"
#include "config.h"
#include "firebase.h"

#define LightIntensity A1
#define Humidity A0
#define Acidity A2

void setup(void) {
  initSetup();
  setupRoutes(server);
  setupFirebase();
  Serial.begin(115200);
  Serial.println("Dallas Temperature Sensor Example");
}

void loop(void) {
  int lightIntensity = analogRead(LightIntensity);
  int humidity = analogRead(Humidity);
  float phInput = analogRead(Acidity);

  float ph = (-0.0139*phInput)+7.7851;
  if(ph>1){
    // Serial.print("Temperature: ");
    // // Serial.print(temperatureC);
    // Serial.println("°C");

    Serial.print("Humidity: ");
    Serial.print(humidity/10);
    Serial.println("%");

    Serial.print("Light Intensity: ");
    Serial.println(lightIntensity/2);

    Serial.print("pH: ");
    Serial.println(ph);
  } else {
      Serial.print("pH off: ");
      Serial.println(ph);
  }
  if (ssidNew == "") {
      server.handleClient();
  } else {
      String status = getDeviceStatus();
      if(status == "on") {
      Serial.println("Yeay Terhubung!!!!");
      status = "off";
      if(ph > 1){
        updateDeviceInput(ph, humidity, 33.5, lightIntensity);
        updateDeviceStatus(status);
      }
    }
  // Wait 1 second before the next loop
  delay(2000);
  }
  delay(2000);
}