#include "ASKModulation.h"

ASKModulation::ASKModulation(){
    dac.begin(0x62);
    delay0 =(1000000/freq0 - 1000000/defaultFreq) / 4;
    Serial.flush();
}

void ASKModulation::sendDataTX(){
    if(Serial.available()>0) {
        for(int i=0;i<20;i++){
            inData[i] = Serial.read();
        }
    }

    for(int i=0;i<8;i++){
        for(int k=7;k>=0;k-=2){
            int tmp = inData[i] & 3;
            for(int s1=0;s1<5;s1++){
                for(int s=0;s<4;s++){
                    dac.setVoltage(,false);
                    delayMicroseconds(delay0);
                }
            }
            inData[i] >>= 2;
        }
    }
    dac.setVoltage(0,false);
}

void ASKModulation::sendDataRX(){
    int tmp = analogRead(A0);
    if(tmp-prev > r_slope && check == false){
        max =0 ;
        check = true;
    }
    if(tmp>max){
        max=tmp;
    }
    if(max-tmp >r_slope){
        if(check == true){
            if(a0min<max &&max <a0max){
                Serial.print("0 0 ");
                count++;
            }
            else if(a1min<max && max<a1max){
                Serial.print("0 1 ");
                count++;
            }
            else if(a2min<max && max<a2max){
                Serial.print("1 0 ");
                count++;
            }
            else if(a3min<max && max<a3max){
                Serial.print("1 1 ");
                count ++;
            }
            if (count == 5){
                Serial.println();
                count = 0;
            }
        }
        check = false;
    } 
    prev = tmp;
}
