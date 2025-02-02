#include "main.hpp"

void IRAM_ATTR impulse()
{
    gmCounter.impulse();
}

void TaskSensor(void *pvParameters)
{
    while (true)
    {
        double temperature = sensor.getTemperature();
        double humidity = sensor.getHumidity();
        double doseRate = gmCounter.getDoseRate();
        httpHandler.sendData(temperature, humidity, doseRate);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}

void TaskGMCounter(void *pvParameters)
{
    while (true)
    {
        gmCounter.processCounts();
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}

void TaskLcd(void *pvParameters)
{
    while (true)
    {
        lcdHandler.printValue("suhu1", sensor.getTemperature());
        lcdHandler.printValue("kelembapan1", sensor.getHumidity());
        lcdHandler.printValue("doseRate1", gmCounter.getDoseRate());
        if (gmCounter.getDoseRate() > 1)
        {
            lcdHandler.printMessage("status", "Laju Dosis Tinggi");
        }
        else
        {
            lcdHandler.printMessage("status", "Laju Dosis Normal");
        }
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}

void TaskWiFi(void *pvParameters)
{
    while (true)
    {
        wifiManager.connect();
        if (WiFi.status() == WL_CONNECTED)
        {
            lcdHandler.printMessage("wifiConnect", "Connected");
        }
        else
        {
            lcdHandler.printMessage("wifiConnect", "Disconnected");
        }
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}

void setup()
{
    Serial.begin(115200);
    
    lcdHandler.begin();

    sensor.begin();
    wifiManager.connect();
    
    pinMode(12, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(12), impulse, FALLING);

    xTaskCreate(TaskSensor, "TaskSensor", 8192, NULL, 1, NULL);
    xTaskCreate(TaskGMCounter, "TaskGMCounter", 8192, NULL, 1, NULL);
    xTaskCreate(TaskLcd, "TaskLcd", 8192, NULL, 1, NULL);
    xTaskCreate(TaskWiFi, "TaskWiFi", 8192, NULL, 1, NULL);
}

void loop()
{
    vTaskDelete(NULL);
}
