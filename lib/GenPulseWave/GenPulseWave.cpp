#include "GenPulseWave.h"

void GenPulseWave::init(int pin_number)
{
    Serial.begin(115200);
    pinMode(pin_number, OUTPUT);
}

float *GenPulseWave::computeSine()
{
    for (int i = 0; i < 4; i++)
    {
        this->S[i] = sin(zeta[i] * (PI / 180));
    }
    return S;
}

uint16_t *GenPulseWave::computePWMDuty()
{
    for (int i = 0; i < 4; i++)
    {
        
    }
}
