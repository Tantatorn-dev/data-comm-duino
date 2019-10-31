#include <Wire.h>
#include <Adafruit_MCP4725.h>

#define freq0 1000

class ASKModulationTX
{
public:
    ASKModulationTX();
    void send();

private:
    Adafruit_MCP4725 dac;

    const float A[4] = {1, 2, 3, 4};
    const uint16_t S_DAC[4] = {500, 1000, 1500, 2000};
    const uint16_t zeta[4] = {0, 90, 180, 270};
    int delay0;
    char inData[20];
    float pi = 3.1415;
    const uint16_t vRef = 2047;
};