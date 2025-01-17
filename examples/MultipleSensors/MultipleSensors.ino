/**
 * Demonstration of reading multiple TCS34725 colour sensors
 * using a TCA9548A I2C multiplexer
 */

// INCLUDES
#include <Wire.h>
#include "TCS34725.h"

// CONSTANTS
// Address of TCA9548A multiplexer set by setting A0-A2 lines HIGH/LOW
// LLL=0x70 (default), HLL=0x71, LHL=0x72, HHL=0x73, LLH=0x74, HLH=0x75, LHH=0x76, HHH=0x77
const byte multiAddress = 0x70;
const byte numSensors = 3;

// GLOBALS
// Initialise an array of TCS sensor objects
TCS34725 tcs[numSensors] = {TCS34725(), TCS34725(), TCS34725()};

// Select the appropriate bus from the I2C multiplexer
void selectBus(uint8_t bus){
    Wire.beginTransmission(multiAddress);
    Wire.write(1 << bus);
    Wire.endTransmission();
}

void setup(void) {
  // Used for debugging
  Serial.begin(115200);
  Serial.println(__FILE__ __DATE__);

  // Start the I2C interface
  Wire.begin();

  // Initialise the array of sensors  
  for(int i = 0; i < numSensors; i++) {
    Serial.print(F("Initialising sensor #"));
    Serial.print(i);
    // Set the multiplexer to the appropriate channel
    selectBus(i);
    // Configure sensor
    if (tcs[i].attach(Wire)) {
      tcs[i].integrationTime(50); // ms
      tcs[i].gain(TCS34725::Gain::X16);
      Serial.println(F(" OK!"));
    }
    else {
      Serial.println(F(" ERROR: TCS34725 NOT FOUND"));
    }
    delay(100);
  }
}

void loop(void) {
  for(int i=0; i<numSensors; i++) {
    // Select the appropriate channel on the I2C multiplexer
    selectBus(i);
    if (tcs[i].available()) {
		char buffer[50];
		snprintf(buffer, 50, "Sensor #%d: {%.f,%.f,%.f,%.f}", i, tcs[i].color().r, tcs[i].color().g, tcs[i].color().b, tcs[i].lux());
		Serial.println(buffer);
    }
  }
  delay(1000);
}