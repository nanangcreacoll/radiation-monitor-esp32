#ifndef GM_COUNTER_HPP
#define GM_COUNTER_HPP

#include <Arduino.h>
#define MAX_PERIOD 60000
#define LOG_PERIOD 30000

class GMCounter
{
private:
  unsigned long counts;
  unsigned long previousMillis;
  unsigned int multiplier;
  double pencacahanArray[256];
  int currentCPM;
  double rerataCPM;
  double sdCPM;
  double doseRate;

public:
  GMCounter();
  void IRAM_ATTR impulse();
  void processCounts();
  double calculateSieverts(double x);
  double getDoseRate();
};

#endif
