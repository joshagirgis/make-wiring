#include <Arduino.h>
int main(void){
  init();
  Serial.begin(9600);
  pinMode(8, OUTPUT);    
  for (;;) {
  digitalWrite(8, HIGH);   // turn the LED on (HIGH is the voltage level)
  Serial.println("ON");
  delay(1000);              
  Serial.println("OFF");  // wait for a second
  digitalWrite(8, LOW);    // turn the LED off by making the voltage LOW
  delay(1000); 
  }
  return 0;
}    

