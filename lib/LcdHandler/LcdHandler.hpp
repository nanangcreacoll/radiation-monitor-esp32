#ifndef LCD_HANDLER_HPP
#define LCD_HANDLER_HPP

#include <Arduino.h>

class LcdHandler {
public:
    void begin();
    void printValue(String label, double value);
    void printValue(String label, int value);
    void printValue(String label, float value);
    void printMessage(String label, String message);
};

#endif