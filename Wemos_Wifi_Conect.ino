#ifdef ESP8266 //Pilih Board Lolin (Wemos) D1 R1
#include <ESP8266WiFi.h> 
#else // ESP32
#include <WiFi.h>
#endif

#define LedPin 2

#ifndef STASSID
#define STASSID "Experia"
#define STAPSK "12345678"
#endif

const int minValue = 0;
const int maxValue = 10;

const int Tegangan = 370;
const int Arus = 120;

const char* ssid = STASSID;
const char* password = STAPSK;

void setup() {
  Serial.begin(115200);
  pinMode(LedPin, OUTPUT);

  //Mode Wifi Ke Station
  WiFi.mode(WIFI_STA);

  //Konek Wifi
  WiFi.begin(ssid, password);
  Serial.print(F("Connecting to "));
  Serial.println(ssid);
  delay(1000);

  while(WiFi.status() != WL_CONNECTED) {
    digitalWrite(LedPin, HIGH);
    delay(500);
    Serial.print(".");
  }

  //Tampilkan pada Serial Monitor jika dapat terhubung
  Serial.println("");
  Serial.println("WiFi terhubung");
  Serial.println("Alamat IP: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {
    digitalWrite(LedPin, LOW);
  }
  
  //Dummy nilai sensor
  int sensor1 = random(minValue, maxValue + 1);
  int sensor2 = random(minValue, maxValue + 1);
  
  //Tampilkan nilai Dummy Sensor
  Serial.print("Sensor1: ");
  Serial.println(Tegangan + sensor1);
  Serial.print("Sensor2: ");
  Serial.println( Arus + sensor2);

  delay(1000);
}
