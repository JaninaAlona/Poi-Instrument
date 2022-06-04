#include <Arduino_LSM6DS3>


void setup() {
  Serial.begin(9600);
  while (!Serial);
 
  if (!IMU.begin()) {
    Serial.println("Failed to initialize IMU!");
 
    while (1);
  }
 
  Serial.print("Accelerometer sample rate = ");
  Serial.print(IMU.accelerationSampleRate());
  Serial.println(" Hz");
  Serial.println();
  Serial.println("Acceleration in G's");
  Serial.println("X\tY\tZ");

  Serial.print("Gyroscope sample rate = ");
  Serial.print(IMU.gyroscopeSampleRate());
  Serial.println(" Hz");
  Serial.println();
  Serial.println("Gyroscope in degrees/second");
  Serial.println("X\tY\tZ");
}
 
void loop() {
  float xA, yA, zA;
  float xG, yG, zG;
 
  if (IMU.accelerationAvailable()) {
    IMU.readAcceleration(xA, yA, zA);
    Serial.println("Accelerometer:");
    Serial.print("xA: ");
    Serial.print(xA);
    Serial.print("'\t'");
    Serial.print("yA: ")
    Serial.print(yA);
    Serial.print("'\t'");
    Serial.print("zA: ");
    Serial.println(zA);
  }
 
  if (IMU.gyroscopeAvailable()) {
    IMU.readGyroscope(xG, yG, zG);
    Serial.println("Gyroscope:");
    Serial.print("xG: ");
    Serial.print(xG);
    Serial.print("'\t'");
    Serial.print("yG: ")
    Serial.print(yG);
    Serial.print("'\t'");
    Serial.print("zG: ");
    Serial.println(zG);
  }
}