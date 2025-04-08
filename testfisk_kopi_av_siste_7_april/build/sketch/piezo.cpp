#line 1 "/Users/martinflataker/Desktop/Prog_Semester_4/Elsys_semester_4_samlet/7_april/Arduino/testfisk_organisert_7_april_copy_2/piezo.cpp"
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