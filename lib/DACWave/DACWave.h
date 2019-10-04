#include <Wire.h>
#include <Adafruit_MCP4725.h>

#define defaultFreq 1700
#define freq0 2000
#define angleAmount 16

class DACWave
{
public:
    DACWave();
    float *computeSine();
    long *computeS_Dac();
    void writeSignal();
    void printDebug();

private:
    Adafruit_MCP4725 dac;
    float zeta[angleAmount] = {0.0, 22.5, 45.0, 67.5, 90.0, 112.5, 135.0, 157.5, 180.0, 202.5, 225.0, 247.5, 270.0, 292.5, 315.0, 337.5};
    float S[angleAmount];
    long S_DAC[angleAmount];
    int delay0;
};