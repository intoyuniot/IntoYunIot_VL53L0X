/*!
 * @file vl53L0x.ino
 * @brief IntoYun's Laser rangefinder library
 * @n This example provides the VL53L0X laser rangefinder API function

 * @copyright	[IntoYun](www.intoyun.com), 2018
 * @copyright	GNU Lesser General Public License

 * @author [robin]
 * @version  V1.0
 * @date  2018-8-10
 * @https://github.com/intoyuniot/IntoYunIot_VL53L0X
 */

#include "Arduino.h"
#include "Wire.h"
#include "IntoYunIot_VL53L0X.h"

/*****************Keywords instruction*****************/
//Continuous--->Continuous measurement model
//Single------->Single measurement mode
//High--------->Accuracy of 0.25 mm
//Low---------->Accuracy of 1 mm
/*****************Function instruction*****************/
//setMode(ModeState mode, PrecisionState precision)
  //*This function is used to set the VL53L0X mode
  //*mode: Set measurement mode       Continuous or Single
  //*precision: Set the precision     High or Low
//void start()
  //*This function is used to enabled VL53L0X
//float getDistance()
  //*This function is used to get the distance
//uint16_t getAmbientCount()
  //*This function is used to get the ambient count
//uint16_t getSignalCount()
  //*This function is used to get the signal count
//uint8_t getStatus();
  //*This function is used to get the status
//void stop()
  //*This function is used to stop measuring

IntoYunIot_VL53L0X sensor;

void setup() {
    //initialize serial communication at 9600 bits per second:
    Serial.begin(115200);
    //join i2c bus (address optional for master)
    Wire.begin();
    //Set I2C sub-device address
    sensor.begin(0x50);
    //Set to Back-to-back mode and high precision mode
    sensor.setMode(Continuous,High);
    //Laser rangefinder begins to work
    sensor.start();
}

void loop()
{
    //Get the distance
    Serial.print("Distance: ");Serial.println(sensor.getDistance());
    //The delay is added to demonstrate the effect, and if you do not add the delay,
    //it will not affect the measurement accuracy
    delay(500);
}
