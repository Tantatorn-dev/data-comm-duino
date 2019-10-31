#include "ASKModulationRX.h"

ASKModulationRX::ASKModulationRX()
{
    dac.begin(0x64);
    delay0 = (1000000 / (freq0 * 4)) - 150;
    Serial.begin(9600);
    Serial.flush();
}

void ASKModulationRX::receive()
{
    /*
    int tmp = analogRead(A0);
    if (tmp - prev > r_slope && check == false)
    {
        max = 0;
        check = true;
    }
    if (tmp > max)
    {
        max = tmp;
    }
    if (max - tmp > r_slope)
    {
        if (check == true)
        {
            if (a0min < max && max < a0max )
            {
                Serial.print("| 0 0 |");
                count++;
            }
            else if (a1min < max && max < a1max )
            {
                Serial.print("| 0 1 |");
                count++;
            }
            else if (a2min < max && max < a2max )
            {
                Serial.print("| 1 0 |");
                count++;
            }
            else if (a3min < max && max < a3max )
            {
                Serial.print("| 1 1 |");
                count++;
            }
            if (count == 4)
            {
                Serial.println();
                count = 0;
            }
        }
        check = false;
    }
    prev = tmp;
    */

    int tmp = analogRead(A0);
    if (tmp - prev > r_slope && check == false)
    {
        max = 0;
        check = true;
        eiei++;
    }
    if (tmp > max)
    {
        max = tmp;
    }
    if (max - tmp > r_slope)
    {
        if (check == true)
        {
            if (a0min < max && max < a0max)
            {
                //Serial.print("0 0 ,");
                if (eiei == 3)
                {
                    input[index--] = '0';
                    input[index--] = '0';
                }
                count++;
            }
            else if (a1min < max && max < a1max)
            {
                //Serial.print("0 1 ,");
                if (eiei == 3)
                {
                    input[index--] = '1';
                    input[index--] = '0';
                }
                count++;
            }
            else if (a2min < max && max < a2max)
            {
                //Serial.print("1 0 ,");
                if (eiei == 3)
                {
                    input[index--] = '0';
                    input[index--] = '1';
                }
                count++;
            }
            else if (a3min < max && max < a3max)
            {
                //Serial.print("1 1 ,");
                if (eiei == 3)
                {
                    input[index--] = '1';
                    input[index--] = '1';
                }
                count++;
            }
            if (count == 5)
            {
                //Serial.println();
                s++;
                eiei = 0;
                count = 0;
            }

            if (s == 4)
            {
                long value = strtol(input, NULL, 2);
                Serial.println(input);
                //Serial.print((char)value);
                index = 7;
                for (int i = 0; i < 8; i++)
                    input[i] = ' ';
                s = 0;
            }
        }
        check = false;
    }
    prev = tmp;
}
