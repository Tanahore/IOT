#ifndef CONFIG_H
#define CONFIG_H

#include <WebServer.h>
#include <WiFi.h>

// Declare external variables

extern const char *ssid;
extern const char *password;

extern WebServer server;

extern String ssidNew;
extern String passNew;

void initSetup();

#endif
