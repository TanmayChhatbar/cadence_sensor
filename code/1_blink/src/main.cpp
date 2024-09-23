#include <Arduino.h>
#include "pindef.h"

void blinkTask(void *pvParameters);

void setup() {
  xTaskCreate(blinkTask, "Blink Task", 128, NULL, 1, NULL);
  vTaskStartScheduler();
}

void loop() {
}

void blinkTask(void *pvParameters) {
  pinMode(LED_R, OUTPUT);
  while (1) {
    digitalWrite(LED_R, HIGH);
    vTaskDelay(500 / portTICK_PERIOD_MS);
    digitalWrite(LED_R, LOW);
    vTaskDelay(500 / portTICK_PERIOD_MS);
  }
}