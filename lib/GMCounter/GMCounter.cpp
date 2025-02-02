#include "GMCounter.hpp"

GMCounter::GMCounter() : counts(0), previousMillis(0), currentCPM(0), rerataCPM(0), sdCPM(0), doseRate(0) 
{
    this->multiplier = MAX_PERIOD / LOG_PERIOD;
}

void IRAM_ATTR GMCounter::impulse() 
{
    this->counts++;
}

void GMCounter::processCounts()
{
    unsigned long currentMillis = millis();
    if (currentMillis - this->previousMillis > LOG_PERIOD) {
        this->previousMillis = currentMillis;
        this->pencacahanArray[this->currentCPM] = this->counts * this->multiplier;
        this->counts = 0;
        this->rerataCPM = 0;
        this->sdCPM = 0;
        for (int x = 0; x <= this->currentCPM; x++) {
            this->rerataCPM += this->pencacahanArray[x];
        }
        this->rerataCPM /= (this->currentCPM + 1);
        for (int x = 0; x <= this->currentCPM; x++) {
            this->sdCPM += sq(this->pencacahanArray[x] - this->rerataCPM);
        }
        this->sdCPM = sqrt(this->sdCPM / this->currentCPM) / sqrt(this->currentCPM + 1);
        this->doseRate = this->calculateSieverts(this->pencacahanArray[this->currentCPM]);
        this->currentCPM++;
    }
}

double GMCounter::calculateSieverts(double x)
{
    return x * 0.00571;
}

double GMCounter::getDoseRate()
{
    return this->doseRate;
}
