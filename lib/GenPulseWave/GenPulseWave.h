#include <Arduino.h>

float zeta[4] ={0,90,180,270};

class GenPulseWave{
    public:
        void init(int pin_number);
        float* computeSine();
        uint16_t* computePWMDuty();
    private:
        float S[];
        uint16_t pwmDuty[];
};