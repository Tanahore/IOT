#include "firebase.h"
#include "config.h"

FirebaseData firebaseData;
FirebaseAuth auth;
FirebaseConfig config;

void setupFirebase() {
  config.host = FIREBASE_HOST;
  config.signer.tokens.legacy_token = FIREBASE_AUTH;
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

String getDeviceStatus() {
  Firebase.begin(&config, &auth);
  Firebase.reconnectWiFi(true);
  
  if (!Firebase.ready()) {
    Serial.println("Firebase not ready!");
    delay(1000);
  }
  
  String path = "/devices/" + String(DEVICE_ID) + "/deviceStatus";
  String result = "";
  if (Firebase.getString(firebaseData, path.c_str())) { // Menggunakan Firebase.getString()
    result = firebaseData.stringData();
    Serial.println("Data retrieved successfully");
  } else {
    Serial.printf("Failed to get data: %s\n", firebaseData.errorReason().c_str());
  }
  return result;
}

void updateDeviceStatus(String status) {
  String path = "devices/"+String(DEVICE_ID)+"/deviceStatus";
  if (Firebase.setString(firebaseData, path.c_str(), status)) {
    Serial.println("Device status updated successfully");
  } else {
    Serial.printf("Failed to update device status: %s\n", firebaseData.errorReason().c_str());
  }
}

void updateDeviceInput(float ph, int humidity, float temperature, int lightIntensity) {
  String path = "devices/"+String(DEVICE_ID)+"/input";
  FirebaseJson json;
  json.set("ph", ph);
  json.set("kelembapan", humidity);
  json.set("suhu", temperature);
  json.set("instensitasCahaya", lightIntensity);

  if (Firebase.updateNode(firebaseData, path.c_str(), json)) {
    Serial.println("Device input updated successfully");
  } else {
    Serial.printf("Failed to update device input: %s\n", firebaseData.errorReason().c_str());
  }
}
