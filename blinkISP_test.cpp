#include <Arduino.h>
#include <Wire.h>
#include <LowPower.h>
#include <TinyGPSplusplus.h>  //gps lib
#include <ReceiveOnlySoftwareSerial.h>
#include <INA219.h>
ReceiveOnlySoftwareSerial gpsSer(6); // RX

void i2C_Scanner() { //scans i2c bus line
  byte error, address;
  int nDevices;
  Serial.println("Scanning...");
  nDevices = 0;
  for (address = 1; address < 127; address++ ) {
    // The i2c_scanner uses the return value of
    // the Write.endTransmisstion to see if
    // a device did acknowledge to the address.
    Wire.beginTransmission(address);
    error = Wire.endTransmission();
    if (error == 0) {
      Serial.print("I2C device found at address 0x");
      if (address < 16)
        Serial.print("0");
      Serial.print(address, HEX);
      Serial.println("  !");
      nDevices++;
    }
    else if (error == 4) {
      Serial.print("Unknown error at address 0x");
      if (address < 16)
        Serial.print("0");
      Serial.println(address, HEX);
    }
  }
  if (nDevices == 0)
    Serial.println("No I2C devices found\n");
  else
    Serial.println("done\n");
};


int main(void){
  init();
  Wire.begin();
  Serial.begin(9600);
  pinMode(4,OUTPUT);
  Serial.println("Start");
  delay(3000);
  
  for (;;) {
  /*i2C_Scanner();
  digitalWrite(4, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);              
  digitalWrite(4, LOW);    // turn the LED off by making the voltage LOW
  delay(100); 
  digitalWrite(4, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(200);
  Serial.println(analogRead(A0)*5.0/1023);
  Serial.print("\t");
  Serial.println(analogRead(A1)*5.0/1023);
  Serial.print("\t");
  Serial.println(analogRead(A2)*5.0/1023);
  Serial.print("\t");
  Serial.println(analogRead(A3)*5.0/1023);
  Serial.print("\t");
  Serial.println(analogRead(A4)*5.0/1023);
  Serial.print("\t");
  Serial.println(analogRead(A5)*5.0/1023);
  Serial.print("\t");
  Serial.println(analogRead(A6)*5.0/1023);
  Serial.print("\t");
  Serial.println(analogRead(A7)*5.0/1023);
  delay(1000);*/
  }
  return 0;
}    

