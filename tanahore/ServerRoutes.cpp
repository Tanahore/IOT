#include "ServerRoutes.h"
#include "index.h"
#include <WiFi.h>

extern String ssidNew;
extern String passNew;

void handleForm(WebServer &server) {
  ssidNew = server.arg("ssidNew");
  passNew = server.arg("passNew");

  server.send(200, "text/html", "Data received successfully!");  // Ubah sukses_html menjadi string langsung

  delay(2000);    // Agar perangkat dapat mengirimkan data sebelum disconnect

  WiFi.softAPdisconnect(true);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssidNew.c_str(), passNew.c_str());

  // Tunggu sampai terhubung
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("Terhubung Ke Jaringan");
}

void handleRoot(WebServer &server) {
  server.send(200, "text/html", index_html);
}

void setupRoutes(WebServer &server) {
  server.on("/", [&server](){ handleRoot(server); });
  server.on("/handleForm", [&server](){ handleForm(server); });
}
