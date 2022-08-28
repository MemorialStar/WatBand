#include <ArduinoBLE.h>
#ifndef _Bluetooth_H_
#define _Bluetooth_H_

static const int WRITE_BUFFER_SIZE =                   256;
static const bool WRITE_BUFFER_FIZED_LENGTH =          false;
static const std::string uuidService =                 "1A01";
static const char16_t *uuidGyroX =                     u"2A01";
static const char16_t *uuidGyroY =                     u"2A02";
static const char16_t *uuidGyroZ =                     u"2A03";
static const char16_t *uuidCo =                        u"3A01";
static const char16_t *uuidEcg =                       u"4A01";
static const char16_t *uuidBattery =                   u"AA01";


typedef enum{
    GYROX,
    GYROY,
    GYROZ,
    CO,
    ECG,
    BAT
}dataType;


class Bluetooth{
    public :
        Bluetooth(char* localName);
        void begin();
        void transmit(dataType type, float value);
        bool IsConnected();
    private :
        const char* _localName;
        const char* _charService;
        const char* _charGyroX;
        const char* _charGyroY;
        const char* _charGyroZ;
        const char* _charCo;
        const char* _charEcg;
        const char* _charBattery;
        const BLEService _Service;
};
#endif