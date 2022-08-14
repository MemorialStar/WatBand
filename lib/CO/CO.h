#ifndef _CO_H_
#define _CO_H_

class CO{
    public :
        CO(int pin);
        float readValue();
    private :
        int _pin;
        float _ValueCO;
};

#endif