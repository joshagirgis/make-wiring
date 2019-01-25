#include <Arduino.h>
#include <Wire.h>
#include <TinyGPSplusplus.h>  //gps lib
#include <ReceiveOnlySoftwareSerial.h>
#include <INA219.h>
#include <EEPROM.h> 
#include <CN0349.h>
#include <avr/io.h> 
#include <avr/sleep.h>
#include <avr/wdt.h>
#include <avr/power.h>
#include <util/delay.h>
#include <stdlib.h>
ReceiveOnlySoftwareSerial gpsSer(PB2); // RX
TinyGPSPlus gps; //intialize GPS

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

String gpsSensor() {
  String deg_latCoord;
  String deg_lonCoord;
  String latCoord;
  String lonCoord;
  String latCoord1;
  String lonCoord1;
  double decimal_degrees;
  double minutes_lon;
  double minutes_lat;
  double seconds;
  double tenths;
  int lat_degr;
  int lon_degr;
  String coord;
  unsigned long howLong = 3000;
  unsigned long startedAt = millis();
  while (millis() - startedAt < howLong) {
    if (gpsSer.available()) {
      char c = gpsSer.read();
      gps.encode(c);
      //Serial.write(c);
      if (gps.location.isUpdated()) {
        deg_latCoord = String(gps.location.lat(), 10);
        deg_lonCoord = String(gps.location.lng(), 10);
        //lat
        decimal_degrees = deg_latCoord.toFloat();
        lat_degr = int(decimal_degrees);
        minutes_lat = fabs(((decimal_degrees) - (lat_degr)) * 60.0);

        latCoord1 = String(int(lat_degr)) + String((minutes_lat), 4);
        //lon
        decimal_degrees = deg_lonCoord.toFloat();
        lon_degr = int(decimal_degrees);
        minutes_lon = fabs(((decimal_degrees) - (lon_degr)) * 60.0);

        lonCoord1 = String(int(lon_degr)) + String((minutes_lon), 4);
        coord = latCoord1 + "_" + lonCoord1;
        return coord;
        break;

      }
    }
  }
  // transmitGPS = "4488.7667_-6870.3348";
}

int main(){
	init();
	DDRD |= 1 << PIND6;  //set Port D -> PD6 to OUTPUT without changing current settings
	PORTD |= 1 << PIND6; //SET PD6 to HIGH -> turns ON onboard 4 Volt and 3.3v volt Regulators
	DDRD |= 1 << PIND4;  //set Port D -> PD4 to OUTPUT without changing current settings
	Serial.begin(9600);
	Wire.begin();
	while (1){
		PORTD ^= 1 << PIND4; //FLIP onboard LED output
		_delay_ms(100);
		Serial.println("HIjoshai");
		i2C_Scanner();
		delay(1000);
	}
   return(0);

}