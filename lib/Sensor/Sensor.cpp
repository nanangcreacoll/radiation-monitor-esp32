#include "Sensor.hpp"

Sensor::Sensor(int pin) : pin(pin), dht(pin, DHT22)
{
}

void Sensor::begin()
{
    this->dht.begin();
}

double Sensor::getTemperature()
{
    return this->dht.readTemperature();
}

double Sensor::getHumidity()
{
    return this->dht.readHumidity();
}