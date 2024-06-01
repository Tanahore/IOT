#include <OneWire.h>
#include <DallasTemperature.h>

// Data wire is connected to pin D0 on the Wemos D1 R32
#define ONE_WIRE_BUS D0
#define LightIntensity A1
#define Humidity A0
#define Acidity A2
// Setup a oneWire instance to communicate with any OneWire devices
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature.
DallasTemperature sensors(&oneWire); 

void setup(void) {
  // Start serial communication for debugging purposes
  Serial.begin(115200);
  Serial.println("Dallas Temperature Sensor Example");

  // Start up the library
  sensors.begin();
}

void loop(void) {
  // Request temperature readings
  sensors.requestTemperatures();

  // Fetch and print the temperature in Celsius
  float temperatureC = sensors.getTempCByIndex(0);
  int lightIntensity = analogRead(LightIntensity);
  int humidity = analogRead(Humidity);
  float phInput = analogRead(Acidity);

  float ph = (-0.0139*phInput)+7.7851;

  if(ph>1){
    Serial.print("Temperature: ");
    Serial.print(temperatureC);
    Serial.println("°C");

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

  // Wait 1 second before the next loop
  delay(1000);
}
