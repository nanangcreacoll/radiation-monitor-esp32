#include "WiFiManager.hpp"

WiFiManager::WiFiManager(const String& ssid, const String& password) :
    ssid(ssid), password(password)
{}

void WiFiManager::connect()
{
    WiFi.begin(this->ssid, this->password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
    }
}