#include <Arduino_LSM9DS1.h>
#ifndef _Gyro_H_
#define _Gyro_H_

typedef enum{
    X,
    Y,
    Z
}axis;

class Gyro{
    public :
        Gyro();
        float sampleRate();
        float readValue(axis);
    private :
        float _ValueX;
        float _ValueY;
        float _ValueZ;
};
#endif
