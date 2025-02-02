#ifndef WIFI_MANAGER_HPP
#define WIFI_MANAGER_HPP

#include <Arduino.h>
#include <WiFi.h>

class WiFiManager
{
private:
    bool connected = false;
    String ssid = "";
    String password = "";
public:
    WiFiManager(const String& ssid, const String& password);
    void connect();
};

#endif