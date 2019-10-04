#include <Arduino.h>
#include "GenPulseWave.h"
#include "DACWave.h"

DACWave* myDac;

#define PWM_PIN 3

void setup() {
  myDac = new DACWave();
  myDac->computeSine();
  myDac->computeS_Dac();
  myDac->printDebug();
}

void loop() {
  myDac->writeSignal();
}