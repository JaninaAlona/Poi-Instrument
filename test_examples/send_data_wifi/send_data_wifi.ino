#include "wifi_pw.h"
#include <WiFiNINA.h>
#include <Arduino_LSM6DS3>

char ssid[] = SECRET_SSID;                
char pass[] = SECRET_PASS;  

int status = WL_IDLE_STATUS;

WiFiSSLClient client;

void connectToAP() {
  // Connect to Wifi Access Point
  
  while ( status != WL_CONNECTED) {
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);
    
    // Connect to WPA/WPA2 network
    status = WiFi.begin(ssid, pass);
 
    // wait 1 second for connection:
    delay(1000);
    Serial.println("Connected...");
  }
}
 
void printWifiStatus() {
  // Print results to serial monitor  
 
 // Network SSID  
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());
  
  // Device IP address
  IPAddress ip = WiFi.localIP(); 
  Serial.print("IP Address: ");
  Serial.println(ip);
}


void setup() {
  Serial.begin(9600);
  while (!Serial);
 
  // Check for the WiFi module:
  if (WiFi.status() == WL_NO_MODULE) {
    Serial.println("WiFi module failed!");
    while (true);
  }
   
  connectToAP();  
    
  printWifiStatus();

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