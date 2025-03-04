#include <wiringPi.h>
#include <iostream>
#include <thread>
#include <unistd.h>
#include "fire_sensor.h"


int main() {
    if (wiringPiSetupGpio() == -1) {
        std::cerr << "⚠️ Lỗi khởi tạo GPIO!" << std::endl;
        return 1;
    }

    detectFire();
    return 0;
}
