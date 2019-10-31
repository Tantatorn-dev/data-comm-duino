#include <Wire.h>
#include <Adafruit_MCP4725.h>
Adafruit_MCP4725 dac;

#define defaulFreq 1700 //DAC speed (Hz)

#define freq0 1000

const float A[4] = {1, 2, 3, 4};
const uint16_t S_DAC[4] = {500, 1000, 1500, 2000};
const uint16_t zeta[4] = {0, 90, 180, 270};
const uint16_t vRef = 2047;
int delay0;
char inData[20];
float pi = 3.1415;

void setup()
{
  Serial.begin(115200);

  dac.begin(0x64); // set to default
  delay0 = (1000000 / (freq0 * 4)) - 150;
  //delay for sampling period of sine
  // (Tsine - delayfrom DAC processing speed)

  Serial.flush(); // clear buffer
}

void loop()
{
  if (Serial.available() > 0)
  {

    int i = 0;
    delay(5);
    while (Serial.available())
    {
      inData[i] = Serial.read();
      i++;
    }

    for (int j = 0; j < i; j++)
    {
  
  for (int k = 7; k >= 0; k -= 2)
  {
    int tmp = inData[j] & 3; // 00, 01, 10, 11
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
    }
    inData[j] >>= 2;
  }
    }
  //Serial.println();
  dac.setVoltage(vRef, false);


  }
}
