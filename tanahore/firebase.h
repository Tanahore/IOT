#ifndef FIREBASE_H
#define FIREBASE_H

#include "config.h"
#include <FirebaseESP32.h>

extern FirebaseData firebaseData;
extern FirebaseAuth auth;
extern FirebaseConfig config;

void setupFirebase();

#endif
