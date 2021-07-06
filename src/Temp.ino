#include "oled-wing-adafruit.h"
SYSTEM_MODE(MANUAL);
SYSTEM_THREAD(ENABLED);
OledWingAdafruit oled;
// setup() runs once, when the device is first turned on.
void setup() {
  double temp = 0; // initialize temperature
  pinMode(A4, INPUT); // set pin to an input pin
  Serial.begin(9600); // cereal begin
  oled.setup(); // set up oled
	oled.display(); // push to oled

}

// loop() runs over and over again, as quickly as it can execute.
void loop() {
  temp = (((analogRead(A4) * 3.3) / 4095.0)- 0.5) * 100;
  oled.clearDisplay();
  oled.setCursor(0,0);
  oled.print(temp);
  oled.display();

}