#include "GenPulseWave.h"

GenPulseWave::GenPulseWave(int pin_number)
{
    Serial.begin(9600);
    pinMode(pin_number, OUTPUT);
}

float *GenPulseWave::computeSine()
{
    for (int i = 0; i < angleAmount; i++)
    {
        this->S[i] = sin(zeta[i] * (PI / 180.0));
    }
    return S;
}

uint16_t *GenPulseWave::computePWMDuty()
{
    for (int i = 0; i < angleAmount; i++)
    {
        uint16_t out = S[i] * (255 / 2) + (255 / 2);
        pwmDuty[i] = out;
    }
}

void GenPulseWave::writeSignal(int pin_number)
{
    for (int i = 0; i < angleAmount; i++)
    {
        analogWrite(pin_number, pwmDuty[i]);
        delayMicroseconds(4000);
    }
}

void GenPulseWave::printDebug()
{
    for (int i = 0; i < angleAmount; i++)
    {
        Serial.print(zeta[i]);
        Serial.print(" ");
        Serial.print(S[i]);
        Serial.print(" ");
        Serial.print(pwmDuty[i]);
        Serial.print(" ");
        Serial.println();
    }
}
