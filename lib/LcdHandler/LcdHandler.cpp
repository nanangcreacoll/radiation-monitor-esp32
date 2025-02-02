#include "LcdHandler.hpp"

void LcdHandler::begin()
{
    Serial.write(0xff);
    Serial.write(0xff);
    Serial.write(0xff);
}

void LcdHandler::printMessage(String label, String message)
{
    Serial.print(label+".txt=");
    Serial.print("\""+message+"\"");
    Serial.write(0xff);
    Serial.write(0xff);
    Serial.write(0xff);
}

void LcdHandler::printValue(String label, double value)
{
    Serial.print(label+".txt=");
    Serial.print("\""+String(value)+"\"");
    Serial.write(0xff);
    Serial.write(0xff);
    Serial.write(0xff);
}

void LcdHandler::printValue(String label, int value)
{
    Serial.print(label+".txt=");
    Serial.print("\""+String(value)+"\"");
    Serial.write(0xff);
    Serial.write(0xff);
    Serial.write(0xff);
}

void LcdHandler::printValue(String label, float value)
{
    Serial.print(label+".txt=");
    Serial.print("\""+String(value)+"\"");
    Serial.write(0xff);
    Serial.write(0xff);
    Serial.write(0xff);
}