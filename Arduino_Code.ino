#define BLYNK_PRINT Serial

#define BLYNK_TEMPLATE_ID "TMPL6jX5uYplK"
#define BLYNK_TEMPLATE_NAME "Dht11"
#define BLYNK_AUTH_TOKEN "4v1zUzuR5XDsHoR74-LtPFY2xYZ5bZE4"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp32.h>

#include <dht11.h>
#include <Blynk.h>
// #include <WiFi.h>
#include "MAX30100_PulseOximeter.h"
#include <Wire.h>
// #include <WiFiClient.h>

#define REPORTING_PERIOD_MS 1000
#define REPORTING_PERIOD_MS_2 2000


// Your WiFi credentials.
// Set password to "" for open networks.
char auth[] = "4v1zUzuR5XDsHoR74-LtPFY2xYZ5bZE4";
char ssid[] = "a12";
char pass[] = "abcd1234";

PulseOximeter pox;

float BPM, SpO2;
uint32_t tsLastReport = 0;
uint32_t tsLastReport2 = 0;

#define DHTPIN 2
#define DHTTYPE DHT11
dht11 DHT11;
BlynkTimer timer;

void onBeatDetected() {
  Serial.println("Beat Detected!");
}

void setup() {
  // Debug console
  // Serial.begin(9600);
  Serial.begin(115200);
  delay(1000);

  //dht.begin();

  //timer.setInterval(1000L, sendSensor);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  Serial.print("Initializing Pulse Oximeter..");

  if (!pox.begin()) {
    Serial.println("FAILED");
    for (;;)
      ;
  } else {
    Serial.println("SUCCESS");
    pox.setOnBeatDetectedCallback(onBeatDetected);
  }
  // Configure sensor to use 7.6mA for LED drive
  pox.setIRLedCurrent(MAX30100_LED_CURR_7_6MA);

  // Register a callback routine
}


