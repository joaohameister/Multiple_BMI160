#include <BMI160Gen.h>

const int select_pin = 10;
const int i2c_addr = 0x68;

void setup() {
  Serial.begin(9600); // initialize Serial communication
  while (!Serial);    // wait for the serial port to open
  Wire.begin();
  // initialize device
  TCA9548A(2);
  BMI160.begin(BMI160GenClass::I2C_MODE);

  TCA9548A(4);
  BMI160.begin(BMI160GenClass::I2C_MODE);

  TCA9548A(7);
  BMI160.begin(BMI160GenClass::I2C_MODE);

}

void loop() {
  int16_t gx1, gy1, gz1;         // raw gyro values
  int16_t gx2, gy2, gz2;
  int16_t gx3, gy3, gz3;
  // read raw gyro measurements from device
  TCA9548A(2);
  BMI160.readAccelerometer(gx1, gy1, gz1);
  // display tab-separated gyro x/y/z values
  Serial.print("g1: ");
  Serial.print(gx1);
  Serial.print("//");
  Serial.print(gy1);
  Serial.print("//");
  Serial.print(gz1);
  Serial.println();

  TCA9548A(4);
  BMI160.readAccelerometer(gx2, gy2, gz2);

  Serial.print("g2: ");
  Serial.print(gx2);
  Serial.print("//");
  Serial.print(gy2);
  Serial.print("//");
  Serial.print(gz2);
  Serial.println();

  TCA9548A(7);
  BMI160.readAccelerometer(gx3, gy3, gz3);

  Serial.print("g3: ");
  Serial.print(gx3);
  Serial.print("//");
  Serial.print(gy3);
  Serial.print("//");
  Serial.print(gz3);
  Serial.println();

  delay(1000);
}

void TCA9548A(uint8_t bus){
  Wire.beginTransmission(0x70);  // TCA9548A address is 0x70
  Wire.write(1 << bus);          // send byte to select bus
  Wire.endTransmission();
}