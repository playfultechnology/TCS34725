/**
 * Demonstration of how to differentiate between and identify colours
 * using a machine-learning model.
 * 1.) Training data (an array of RGB float values) is captured from the Arduino serial monitor
 * 2.) This is used to train a model in Python using the SciKit-Learn library (https://scikit-learn.org)
 * 3.) The model is then converted into Arduino C code using MicroMLgen https://eloquentarduino.com/libraries/micromlgen/
 */

// INCLUDES
#include <Wire.h>
#include "TCS34725.h"
// The trained SciKit-Learn model, converted using MicroMLGen
#include "model.h"

// CONSTANTS
// Address of TCA9548A multiplexer set by setting A0-A2 lines HIGH/LOW
// LLL=0x70 (default), HLL=0x71, LHL=0x72, HHL=0x73, LLH=0x74, HLH=0x75, LHH=0x76, HHH=0x77
const byte multiAddress = 0x70;
const byte numSensors = 3;

// GLOBALS
// Initialise an array of TCS sensor objects
TCS34725 tcs[numSensors] = {TCS34725(), TCS34725(), TCS34725()};
// Keep an array of the most recent colour detected by each sensor
char lastColourSeen[numSensors][10] = {};

// Grab a reference to the model's classifier function
Eloquent::ML::Port::RandomForest classifier;

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
  bool newColourSeen = false;
  for(int i=0; i<numSensors; i++) {
    // Select the appropriate channel on the I2C multiplexer
    selectBus(i);
    if (tcs[i].available()) {
      TCS34725::Color color = tcs[i].color();
      float features[4] = { tcs[i].color().r, tcs[i].color().g, tcs[i].color().b, tcs[i].lux() };
      char* colourSeen = (char*)classifier.predictLabel(features);
      //Serial.print(colourSeen);
      if(strcmp(lastColourSeen[i], colourSeen) != 0) {
        newColourSeen = true;
        strncpy(lastColourSeen[i], colourSeen, 10);
      }
    }
  }

  if(newColourSeen) {
    for(int i=0; i<numSensors; i++) {
      Serial.print(lastColourSeen[i]);
      if(i<numSensors-1) { Serial.print(","); }
      else Serial.println("");
    }
  }


  delay(1000);
}