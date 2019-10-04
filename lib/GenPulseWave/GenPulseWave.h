#include <Arduino.h>

#define angleAmount 8

class GenPulseWave{
    public:
        GenPulseWave(int pin_number);
        float* computeSine();
        uint16_t* computePWMDuty();
        void writeSignal(int pin_number);
        void printDebug();
    private:
        float S[angleAmount];
        float zeta[angleAmount] = {0.0,45.0,90.0,135.0,180.0,225.0 ,270.0,315.0};
        uint16_t pwmDuty[angleAmount];
};