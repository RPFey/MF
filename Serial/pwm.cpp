//
// Created by tkm36 on 2021/3/28.
//
#include <iostream>
#include "wiringPi.h"
#include <softPwm.h>
#include "unistd.h"

int main(){
    wiringPiSetup();
    std::cout<<"set value \n";
    softPwmCreate(2, 0, 100);
    for(int i = 0; i < 20; i++){
        softPwmWrite(2, 5 * i);
        std::cout<<"set value to" << (5*i) << std::endl;
        sleep(5);
    }
    return 0;
}
