/*!   @file ICM42670P.h
 */
#ifndef _ICM42670P_H
#define _ICM42670P_H

#include <SPI.h>
// if pins are not defined already, define them
#ifndef SPI_SPC
    #define SPI_SPC 10      // clock
    #define SPI_MISO 11     // master out slave in
    #define SPI_MOSI 12     // master in slave out 
    #define SPI_CS  13      // chip select
    #define ACC_INT 3       // accelerometer interrupt
#endif

#define ICM42670P_UT_PER_LSB TODO // mag data LSB value (fixed)

typedef enum {
  ICM42670P_ACCEL_RANGE_2_G,
  ICM42670P_ACCEL_RANGE_4_G,
  ICM42670P_ACCEL_RANGE_8_G,
  ICM42670P_ACCEL_RANGE_16_G,
} icm42670p_accel_range_t;

typedef enum {
  ICM42670P_GYRO_RANGE_250_DPS,
  ICM42670P_GYRO_RANGE_500_DPS,
  ICM42670P_GYRO_RANGE_1000_DPS,
  ICM42670P_GYRO_RANGE_2000_DPS,
} icm42670p_gyro_range_t;


class ICM42670P {
public:
  ICM42670P();
  ~ICM42670P(){};
  bool begin(int pinCS, SPI *spi = &spi, int32_t sensor_id = 0)
  bool begin_SPI();

  icm42670p_accel_range_t getAccelRange(void);
  void setAccelRange(icm42670p_accel_range_t new_accel_range);

  icm42670p_gyro_range_t getGyroRange(void);
  void setGyroRange(icm42670p_gyro_range_t new_gyro_range);

  bool writeRegister(nt8_t subAddress, uint8_t data);

  uin8_t readRegisters(uint8_t subAddress, uint8_t count, uint8_t* dest);

private:
  void scaleValues(void);
};

#include "ICM42670P.cpp"

#endif  // _ICM42670P_H