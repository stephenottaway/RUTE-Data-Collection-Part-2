#include "HX711.h"

#define calibration_factor -1000 
#define DAT  13
#define CLK  12

HX711 scale;

void setup() {
  Serial.begin(115200);
  Serial.println("HX711 scale demo");

  scale.begin(DAT, CLK);
  scale.set_scale(calibration_factor); 
  scale.tare();	//Assuming there is no weight on the scale at start up, reset the scale to 0

  Serial.println("Readings:");
}

void loop() {
  Serial.print("Reading: ");
  double weight = scale.get_units();
  Serial.print(weight); 
  Serial.print(" lbs"); 
  Serial.println();
  delay(1000);
}
