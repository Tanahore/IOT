#ifndef FIREBASE_H
#define FIREBASE_H

#include "config.h"
#include <FirebaseESP32.h>

extern FirebaseData firebaseData;
extern FirebaseAuth auth;
extern FirebaseConfig config;

void setupFirebase();
String getDeviceStatus();
void updateDeviceStatus(String status);
void updateDeviceInput(float ph, int humidity, float temperature, int lightIntensity);

#endif
