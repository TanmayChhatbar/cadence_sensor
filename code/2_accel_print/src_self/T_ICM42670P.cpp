/*!   @file ICM42670P.cpp
 */
#include "Arduino.h"

/*!
 *    @brief  Instantiates a new ICM20948 class!
 */

ICM42670P::ICM42670P(void) {}

bool begin_SPI(TODO) {

  return init_success;
}

void ICM42670P::scaleValues(void) {
  // TODO
}

icm42670p_accel_range_t ICM42670P::getAccelRange(void) {
  // TODO
  icm42670p_accel_range_t accelRange = 0;
  return accelRange;
}

void ICM42670P::setAccelRange(icm42670p_accel_range_t new_accel_range) {
  // TODO
}

icm42670p_gyro_range_t ICM42670P::getGyroRange(void) {
  // TODO
  icm42670p_gyro_range_t gyroRange = 0;
  return gyroRange;
}

void ICM42670P::setGyroRange(icm42670p_gyro_range_t new_gyro_range) {
  // TODO
}