#include "piezo.h"


PiezoSensor::PiezoSensor(uint8_t pin, int thresh) : piezoPin(pin), threshold(thresh) {}

String PiezoSensor::readPiezo(){
    int newValue = analogRead(piezoPin);
    if(newValue - lastValue > 200){
        Serial.println("Slag!");
        lastValue = newValue;
        return("1");
    }
    lastValue = newValue;
    return("0");
}