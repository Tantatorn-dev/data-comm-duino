#include "DACWave.h"

DACWave::DACWave(){
    Serial.begin(9600);
    dac.begin(0x64); 
    delay0 = (1000000/freq0 - 1000000/defaultFreq)/4;

    Serial.print("delay0 is ");
    Serial.println(delay0);
}

float* DACWave::computeSine() {
    for (int i = 0; i < angleAmount; i++) {
        this->S[i] = sin(zeta[i] * (PI / 180));
    }
    return S;
}

long* DACWave::computeS_Dac(){
    for(int i=0;i<angleAmount;i++){
        S_DAC[i] = S[i]* (4095/2) + (4095/2);
    }
    return S_DAC;
}

void DACWave::writeSignal()
{
    for (int i = 0; i < angleAmount; i++)
    {
        dac.setVoltage(S_DAC[i],false);
        delayMicroseconds(delay0);
    }
}

void DACWave::printDebug()
{
    for (int i = 0; i < angleAmount; i++)
    {
        Serial.print(zeta[i]);
        Serial.print(" ");
        Serial.print(S[i]);
        Serial.print(" ");
        Serial.print(S_DAC[i]);
        Serial.print(" ");
        Serial.println();
    }
}