#ifndef WIFI_MANAGER_HPP
#define WIFI_MANAGER_HPP

#include <WiFi.h>

class WiFiManager
{
private:
    String ssid = "";
    String password = "";
public:
    WiFiManager(const String& ssid, const String& password);
    void connect();
};

#endif