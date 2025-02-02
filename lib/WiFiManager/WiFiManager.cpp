#include "WiFiManager.hpp"

WiFiManager::WiFiManager(const String& ssid, const String& password) :
    ssid(ssid), password(password)
{}

void WiFiManager::connect()
{
    if (!this->connected)
    {
        WiFi.begin(this->ssid.c_str(), this->password.c_str());
        while (WiFi.status() != WL_CONNECTED)
        {
            this->connected = false;
            Serial.println("Connecting to WiFi..");
            delay(1000);
        }
        this->connected = true;
    }
    while (WiFi.status() != WL_CONNECTED) {
        this->connected = false;
        Serial.println("Connecting to WiFi..");
        delay(1000);
    }
}