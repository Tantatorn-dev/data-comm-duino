#include <Arduino.h>
#include "ASKModulationTX.h"

ASKModulationTX *ask;


void setup() {
  ask = new ASKModulationTX();
}

void loop() {
  ask->send();
}