#include "stats.h"


// initializations
stats accStats;
SPIClass spi;
ICM42670 icm(spi,SPI_CS);
TaskHandle_t normalOP;
volatile bool wake = false;
inv_imu_sensor_event_t imu_event;
const int outputDataRate = 100;                       // [Hz] [12.5,25,50,100,200,400,800,1600] output data rate
const int fullScaleRange = 16;                        // [g] [2,4,8,16] full scale range

//function declarations
void wake_handler(void);
void routine(void *pvParameters);
void print_wakeup_reason();
void icmSetup();

// function definitions
void routine(void *pvParameters) {
    // get acc data
    icm.getDataFromRegisters(imu_event);
    accStats.update_stats(imu_event.accel[0]);  // update stat with new data, only one channel for reducing load
    Serial.print("AccelX: ");
    Serial.println(imu_event.accel[0]);
    Serial.print("Variance: ");
    Serial.println(accStats.get_variance());

    // check if stationary
    if (accStats.is_stationary()) {
        vTaskSuspend(normalOP);                 // suspend current task
        icm.startWakeOnMotion(2,wake_handler);  // enable wake on motion (wil   l put IMU into low power mode)
        esp_deep_sleep_start();                 // go to sleep
    }
}

void print_wakeup_reason(){
  esp_sleep_wakeup_cause_t wakeup_reason;
  wakeup_reason = esp_sleep_get_wakeup_cause();

  switch(wakeup_reason) {
    case ESP_SLEEP_WAKEUP_EXT0 : Serial.println("Wakeup caused by external signal using RTC_IO"); break;
    // case ESP_SLEEP_WAKEUP_EXT1 : Serial.println("Wakeup caused by external signal using RTC_CNTL"); break;
    // case ESP_SLEEP_WAKEUP_TIMER : Serial.println("Wakeup caused by timer"); break;
    // case ESP_SLEEP_WAKEUP_TOUCHPAD : Serial.println("Wakeup caused by touchpad"); break;
    // case ESP_SLEEP_WAKEUP_ULP : Serial.println("Wakeup caused by ULP program"); break;
    default : Serial.printf("Wakeup was not caused by deep sleep: %d\n",wakeup_reason); break;
  }
}

void wake_handler(void) {
  wake = true;
  vTaskResume(normalOP);
  print_wakeup_reason();
  icm.startAccel(outputDataRate, fullScaleRange);  // put IMU into low noise mode TODO should reset to low nosie mode
}

void icmSetup() {
  // begin SPI and IMU
  spi.begin(SPI_SPC, SPI_MISO, SPI_MOSI, SPI_CS); // begin SPI with specified pins
  icm.begin();                                    // begin IMU over SPI
  icm.startAccel(outputDataRate, fullScaleRange); // start accelerometer with the specified settings

  esp_sleep_enable_ext0_wakeup(ACC_INT,1);          // enable interrupt wake up for ESP32
  accStats.begin(20, 0.01); // initialize stats with 20 samples and 0.01 threshold
}