#include "CO.h"
#include "Arduino.h"

CO::CO(int pin)
{
    pinMode(pin, OUTPUT);
    _pin = pin;
}

float CO::readValue(){
  _ValueCO = analogRead(_pin);
  return _ValueCO;
}
