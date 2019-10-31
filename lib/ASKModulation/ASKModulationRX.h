#include <Wire.h>
#include <Adafruit_MCP4725.h>

// define parameters
#define defaultFreq 1700 // DAC speed
#define freq0 1000       // carrier sine wave

/*
#define a0min 2250
#define a0max 2700
#define a1min 2750
#define a1max 3200
#define a2min 3250
#define a2max 3700
#define a3min 3750
#define a3max  4090
*/

#define a0min 206
#define a0max 412
#define a1min 413
#define a1max 617
#define a2min 618
#define a2max 822
#define a3min 823
#define a3max 1024

#define r_slope 80

class ASKModulationRX
{
public:
    ASKModulationRX();
    void receive();

private:
    Adafruit_MCP4725 dac;

    // for TX
    const float A[4] = {1, 2, 3, 4};                   // ASK amplitude (0,5]
    const uint16_t S_DAC[4] = {500, 1000, 1500, 2000};
    int delay0;

    // for RX
    int sum = 0;
    int max = 0;
    int prev = 0;
    int check = false;
    int output = -1;
    int count = 0;

    char input[8];
    int index = 7;
    int eiei = 0;
    int dataIn = -1;
    int s = 0;
};