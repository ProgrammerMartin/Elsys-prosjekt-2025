#line 1 "/Users/martinflataker/Desktop/Prog_Semester_4/Elsys_semester_4_samlet/7_april/Arduino/testfisk_organisert_7_april_copy_2/testfisk_organisert_7_april_copy_2.ino"
#include <Wire.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include "wifi_config.h"
#include <WiFi.h>
#include "gyAc.h"
#include "piezo.h"
#include <Arduino.h>


// Oppretter et Queue-objekt for å sende data mellom tasks
QueueHandle_t wifiQueue;

// Objekter
WiFiServer server(80);  // Oppretter et WiFi-server objekt som lytter på port 80 for HTTP-forespørsler
Adafruit_MPU6050 mpu;  // Definerer et objekt av Adafruit_MPU6050-klassen


// Variabler
const uint8_t piezoPin1 = 3;
const uint8_t piezoPin2 = 4;
const int threshold = 700;
float volt;
const float V_REF = 0.707; 
unsigned long lastTime = 0;
int lastValue = 0;
int newValue = 0;
int sensor_value;
TaskHandle_t TaskHandle1 = NULL;  // Deklarer en handle for tasken, en referanse til en task som kjører



#line 33 "/Users/martinflataker/Desktop/Prog_Semester_4/Elsys_semester_4_samlet/7_april/Arduino/testfisk_organisert_7_april_copy_2/testfisk_organisert_7_april_copy_2.ino"
void wifiServerTask(void *pvParameters);
#line 57 "/Users/martinflataker/Desktop/Prog_Semester_4/Elsys_semester_4_samlet/7_april/Arduino/testfisk_organisert_7_april_copy_2/testfisk_organisert_7_april_copy_2.ino"
void mpu6050Task(void *pvParameters);
#line 71 "/Users/martinflataker/Desktop/Prog_Semester_4/Elsys_semester_4_samlet/7_april/Arduino/testfisk_organisert_7_april_copy_2/testfisk_organisert_7_april_copy_2.ino"
void setup();
#line 113 "/Users/martinflataker/Desktop/Prog_Semester_4/Elsys_semester_4_samlet/7_april/Arduino/testfisk_organisert_7_april_copy_2/testfisk_organisert_7_april_copy_2.ino"
void loop();
#line 33 "/Users/martinflataker/Desktop/Prog_Semester_4/Elsys_semester_4_samlet/7_april/Arduino/testfisk_organisert_7_april_copy_2/testfisk_organisert_7_april_copy_2.ino"
void wifiServerTask(void *pvParameters){
  while (true) {
    char dataToSend[100];  // Buffer for mottak

    // Sjekk om vi har data i køen
    if (xQueueReceive(wifiQueue, dataToSend, portMAX_DELAY)){

      // Sjekker om en klient har koblet seg til serveren. 
      // Hvis det er en tilkobling, opprettes et WiFiClient-objekt kalt client.
      // Objektet client brukes til å kommunisere med den klienten.
      WiFiClient client = server.available();

      if (client) {
        client.flush();  // Tømmer mottaksbufferet til klienten
        client.print(dataToSend);   // Sender innholdet av data tilbake til klienten
        client.stop();  // Kobler fra klienten etter at dataene er sendt
      }
    }

    vTaskDelay(20 / portTICK_PERIOD_MS);  // 50 ms 
  }
}


void mpu6050Task(void *pvParameters){
  while (true){
    char data[100];  // Buffer for å lagre strengen
    snprintf(data, sizeof(data), "%s", GyAc());  // Kopierer resultatet fra GyAc()

    if (xQueueSend(wifiQueue, data, portMAX_DELAY) != pdPASS) {
      Serial.println("Feil ved sending til køen!");
  }  

    vTaskDelay(100 / portTICK_PERIOD_MS);  // 100 ms delay
  }
}


void setup() {
  Serial.begin(115200);  // Starter seriell kommunikasjon med baudrate på 115200

  analogReadResolution(12);  // Oppløsningen til ADC-en

  Wire.begin(25, 26);  // Initialiserer I2C-kommunikasjonen på ESP-en, 
                       // og angir de spesifikke pinnene som skal brukes for SDA (Serial Data) og SCL (Serial Clock).
                       // Nødvendig for å hente data fra MPU6050-sensoren

  // Prøver å starte MPU6050-sensoren ved å initialisere kommunikasjonen over I2C
  if (!mpu.begin()) {
      Serial.println("MPU6050 init error!");
      while (1);
  }

  Serial.println("MPU6050 OK!");  // Går videre hvis MPU6050-sensoren er initialisert riktig

  setupWifi();  // Kobler til WiFi

  server.begin();  // Starter serveren, slik at den kan begynne å motta forespørsler
  Serial.println("Server startet.");

  Serial.println("Prøver å opprette kø.");
  // Opprett en kø
  wifiQueue = xQueueCreate(10, sizeof(char[100]));  // Maks 100 tegn per melding

  if (wifiQueue == NULL) {
      Serial.println("Feil: Kunne ikke opprette kø!");
      while (1);
  }
  else {
    Serial.println("Kø opprettet.");
  }

  xTaskCreate(wifiServerTask, "wifiServerTask", 20000, NULL, 10, &TaskHandle1);
  Serial.println("wifiServerTask opprettet.");
  xTaskCreate(mpu6050Task, "mpu6050Task", 20000, NULL, 5, NULL);
  Serial.println("mpu650Task opprettet.");
}



void loop() {

}

