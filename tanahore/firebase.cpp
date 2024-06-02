#include "firebase.h"
#include "config.h"

FirebaseData firebaseData;
FirebaseAuth auth;
FirebaseConfig config;

void setupFirebase(){
  config.host = FIREBASE_HOST;
  config.api_key = FIREBASE_AUTH;
  auth.user.email = "";
  auth.user.password = "";

  Firebase.begin(&config, &auth);
  Firebase.reconnectWiFi(true);

  String path = "/devices/" + String(DEVICE_ID);

  if (Firebase.beginStream(firebaseData, path.c_str())) {
    Serial.println("Connected to Firebase");
  } else {
    Serial.printf("Could not connect to Firebase: %s\n", firebaseData.errorReason().c_str());
  }
}