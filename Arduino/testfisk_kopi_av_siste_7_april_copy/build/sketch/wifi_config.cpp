#line 1 "/Users/martinflataker/Desktop/Prog_Semester_4/Elsys_semester_4_samlet/7_april/Arduino/testfisk_organisert_7_april_copy_2/wifi_config.cpp"
#include "wifi_config.h"


// WiFi-innstillinger
const char* ssid = "Elsys11";
const char* password = "12345678";

// Variabel
int tryes = 0;

void setupWifi(){
  WiFi.disconnect(true);
  delay(100);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
      delay(1000);
      Serial.println("Kobler til WiFi...");
      tryes += 1;
      if (tryes > 10) {
        Serial.println("Kunne ikke koble til WiFi, restart ESP...");
        delay(200);
        ESP.restart();
      }
  }
  tryes = 0;
  Serial.println("WiFi tilkoblet!");
  Serial.print("IP-adresse: ");
  Serial.println(WiFi.localIP());
}