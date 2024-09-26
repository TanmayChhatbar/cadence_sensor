#include <Arduino.h>
#include "pindef.h"
#include "ICM42670P.h"
#include "esp_sleep.h"
#include "utils.h"

void setup() {
  Serial.begin(115200);
  icmSetup();   // setup SPI and IMU
  xTaskCreate(routine, "normal_operation", 128, NULL, 1, &normalOP);  // create routine task for reading and analysing acc data
  vTaskStartScheduler();
}

void loop() {
  delay(1e3); // do nothing in loop. task scheduler will handle everything
}