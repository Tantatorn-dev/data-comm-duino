#include <Wire.h>
#include <Adafruit_MCP4725.h>

Adafruit_MCP4725 dac;

// define parameters
#define defaultFreq 1700  // DAC speed
#define freq0 2000 // carrier sine wave

#define a0min
#define a0max
#define a1min
#define a1max
#define a2min
#define a2max
#define a3min
#define a3max

#define r_slope 1

class ASKModulation{
    public:
        ASKModulation();
        void sendDataTX();
        void sendDataRX();
    private:
    // for TX
        const float A[4] = {}; // ASK amplitude (0,5]
        const uint16_t S_DAC[4] = {}; // Amplitude of sine wave at 0,90,180,270
        int delay0;
        char inData[20];

    // for RX
    int sum =0;
    int max = 0;
    int prev=0;
    int check = false;
    int output = -1;
    int count =0;
};