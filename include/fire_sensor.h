#ifndef FIRE_SENSOR_H
#define FIRE_SENSOR_H

#include <wiringPi.h>
#include <iostream>
#include "Saver.h"

#define IR_SENSOR_PIN 14  // GPIO14 trong WiringPi

void createDirectory(const std::string &path);
void detectFire();

#endif // FIRE_SENSOR_H
