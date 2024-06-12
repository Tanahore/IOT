#ifndef FIREBASE_H
#define FIREBASE_H

#include "config.h"
#include <FirebaseESP32.h>


#define FIREBASE_HOST "tanahore-2-527b8-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "JEfq64LfZ6EVwfdNlOl0pSXbEr7WDDgnKLfTYHXj"
#define DEVICE_ID "DT11"

extern FirebaseData firebaseData;
extern FirebaseAuth auth;
extern FirebaseConfig config;

void setupFirebase();
String getDeviceStatus();
void updateDeviceStatus(String status);
void updateDeviceInput(float ph, int humidity, float temperature, int lightIntensity);

#endif
