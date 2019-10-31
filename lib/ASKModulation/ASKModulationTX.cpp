#include "ASKModulationTX.h"

ASKModulationTX::ASKModulationTX()
{
    Serial.begin(9600);

    dac.begin(0x64);
    delay0 = (1000000 / (freq0 * 4)) - 150;
    //delay for sampling period of sine
    // (Tsine - delayfrom DAC processing speed)

    Serial.flush(); // clear buffer
}

void ASKModulationTX::send()
{
    int a =1;
    for (int k = 7; k >= 0; k -= 2)
    {
        int tmp = a & 3; // 00, 01, 10, 11
        //Serial.print(tmp);
        //Serial.print(" ");
        /*use a cycle loop sl to send 5 cycle/baud*/
        for (int sl = 0; sl < 5; sl++)
        {
            /*use a cycle loop s to send 4 sample/cycle*/
            for (int s = 0; s < 4; s++)
            {
                float rad = (zeta[s] * pi) / 180;
                float si = sin(rad);
                float v_out = (si * S_DAC[tmp]) + vRef;
                //Serial.print("[" + String(si) + ", " + String(v_out) + "] : " );
                dac.setVoltage(v_out, false);
                delayMicroseconds(delay0); // sampling delay
            }
            //Serial.println();
        }
        a >>= 2;
    }
    //Serial.println();
    dac.setVoltage(vRef, false);
}
