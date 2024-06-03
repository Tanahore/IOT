#ifndef CONFIG_H
#define CONFIG_H

#include <WebServer.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <WiFi.h>

#define ONE_WIRE_BUS D0
#define LightIntensity A1
#define Humidity A0
#define Acidity A2

#define FIREBASE_HOST "tanahore-2-527b8-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "JEfq64LfZ6EVwfdNlOl0pSXbEr7WDDgnKLfTYHXj"
#define DEVICE_ID "DT11"
#define API_ADDRESS "https://tanahore-model-api-srzz6vflpq-as.a.run.app"

// Declare external variables

extern const char *ssid;
extern const char *password;

extern WebServer server;

extern OneWire oneWire;
extern DallasTemperature sensors;

extern String ssidNew;
extern String passNew;

void initSetup();

#endif
