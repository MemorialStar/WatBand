#include "Gyro.h"
#include "Arduino.h"

Gyro::Gyro()
{
}

float Gyro::sampleRate(){
    return IMU.accelerationSampleRate();
}

float Gyro::readValue(axis ax){
    float x, y, z;
    if(IMU.accelerationAvailable()) {
        IMU.readAcceleration(x,y,z);
    }
    switch(ax){
        case X : return x; break;
        case Y : return y; break;
        case Z : return z; break;
    }
}
