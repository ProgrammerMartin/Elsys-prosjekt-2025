#line 1 "/Users/martinflataker/Desktop/Prog_Semester_4/Elsys_semester_4_samlet/7_april/Arduino/testfisk_organisert_7_april_copy_2/piezo.h"
#ifndef PIEZO_H
#define PIEZO_H

#include <Arduino.h>

class PiezoSensor {
    private:
        const uint8_t piezoPin;
        const int threshold;
        int16_t lastValue = 0;

    public:
        // Konstruktør
        PiezoSensor(uint8_t pin, int thresh);

        String readPiezo();
};

#endif