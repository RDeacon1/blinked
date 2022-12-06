#include "mbed.h"
#include "constants.h"
#include "lightLevel.h"

extern things_t myData;


AnalogIn lightLevelV( lightOut );
DigitalOut test(P12_3);
void readLight() {
  while(true) {
    myData.lightLevel = lightLevelV.read() * 100; // Range of light level 0 to 100%
    ThisThread::sleep_for(100ms);
    test = !test;
  }
}