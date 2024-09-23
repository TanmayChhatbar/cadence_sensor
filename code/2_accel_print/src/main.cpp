#include <Arduino.h>
#include "pindef.h"
#include <Adafruit_ICM20X.h>
#include <Adafruit_ICM20948.h>
#include <Adafruit_Sensor.h>
// #include <Wire.h>
Adafruit_ICM20948 icm;
uint16_t measurement_delay_us = 65535; // Delay between measurements for testing

void printAccelData(void *pvParameters);

void setup() {
  Serial.begin(115200);
  if (!icm.begin_SPI(SPI_CS, SPI_SPC, SPI_MISO, SPI_MOSI)) {
    Serial.println("Failed to find ICM20948 chip");
    while (1) {
      delay(100);
    }
  }
  xTaskCreate(printAccelData, "Blink Task", 128, NULL, 1, NULL);
  vTaskStartScheduler();
}

void loop() {
  delay(1e3);
}

void printAccelData(void *pvParameters) {
  
}