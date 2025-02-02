#ifndef SENSOR_HPP
#define SENSOR_HPP

#include <DHT.h>
#define DHT_PIN 15

class Sensor
{
private:
    int pin;
    DHT dht;
public:
    Sensor(int pin = DHT_PIN);
    void begin();
    double getTemperature();
    double getHumidity();
};

#endif