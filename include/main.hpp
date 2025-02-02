#include <Arduino.h>
#include "env.hpp"

#include <Sensor.hpp>
#include <GMCounter.hpp>
#include <WiFiManager.hpp>
#include <HTTPHandler.hpp>
#include <LcdHandler.hpp>

Sensor sensor;
GMCounter gmCounter;
WiFiManager wifiManager(WIFI_SSID, WIFI_PASSWORD);
HTTPHandler httpHandler(SERVER_POST, SERVER_LOGIN, API_USERNAME, API_PASSWORD);
LcdHandler lcdHandler;