#line 1 "/Users/martinflataker/Desktop/Prog_Semester_4/Elsys_semester_4_samlet/7_april/Arduino/testfisk_organisert_7_april_copy_2/gyAc.cpp"
#include "gyAc.h"

static float offgx = 0.01, offgy = -0.63, offgz = -0.19;
static float offax = -0.08, offay = -0.12, offaz = 8.79;

const int BUFFER_SIZE = 100;  // Sett en passende størrelse

const char* GyAc() {
    static char buffer[BUFFER_SIZE];  // Statisk buffer (overlever retur)
    sensors_event_t a, g, temp;
    mpu.getEvent(&a, &g, &temp);

    snprintf(buffer, BUFFER_SIZE, "%.2f,%.2f,%.2f,%.2f,%.2f,%.2f",
             a.acceleration.x - offax, a.acceleration.y - offay, a.acceleration.z - offaz,
             g.gyro.x - offgx, g.gyro.y - offgy, g.gyro.z - offgz);
    
    return buffer;  // Retur av statisk buffer (unngår heap-problemer)
}


/*
String GyAc() {
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);

  String Data = String(a.acceleration.x - offax) + "," + String(a.acceleration.y - offay) + "," + 
                String(a.acceleration.z - offaz) + "," + String(g.gyro.x - offgx) + "," + 
                String(g.gyro.y - offgy) + "," + String(g.gyro.z - offgz);
  return Data;
}
*/