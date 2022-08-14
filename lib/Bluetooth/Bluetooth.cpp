#include "Bluetooth.h"

Bluetooth::Bluetooth(char* localName)
{
    _localName = localName;
    _Service(uuidService);
    BLEUnsignedCharCharacteristic _charGyroX(&uuidGyroX, BLERead | BLENotify | BLEBroadcast);
    BLEUnsignedCharCharacteristic _charGyroY(&uuidGyroY, BLERead | BLENotify | BLEBroadcast);
    BLEUnsignedCharCharacteristic _charGyroZ(&uuidGyroZ, BLERead | BLENotify | BLEBroadcast);
    BLEUnsignedCharCharacteristic _charCo(&uuidCo, BLERead | BLENotify | BLEBroadcast);
    BLEUnsignedCharCharacteristic _charEcg(&uuidEcg, BLERead | BLENotify | BLEBroadcast);
    BLEUnsignedCharCharacteristic _charBattery(&uuidBattery, BLERead | BLENotify | BLEBroadcast);

}

void Bluetooth::begin(){

    if(!BLE.begin()){
        Serial.println("starting BLE failed!");
        while(1);
    }

    BLE.setLocalName(_localName);
    BLE.setAdvertisedService(_Service);

    _Service.addCharacteristic(_charGyroX);
    _Service.addCharacteristic(_charGyroY);
    _Service.addCharacteristic(_charGyroZ);
    _Service.addCharacteristic(_charCo);
    _Service.addCharacteristic(_charEcg);
    _Service.addCharacteristic(_charBattery);

    BLE.addService(_Service);

    //Start advertising
    BLE.advertise();
    Serial.print("Peripheral device MAC: ");
    Serial.println(BLE.address());
    Serial.println("Bluetooth device activate, waiting for connections...");
}

void Bluetooth::transmit(dataType type, float value){
    switch(type){
        case GYROX : _charGyroX.writeValue(value);  break;
        case GYROY : _charGyroY.writeValue(value);  break;
        case GYROZ : _charGyroZ.writeValue(value);  break;
        case CO : _charCo.writeValue(value);        break;
        case ECG : _charEcg.writeValue(value);      break;
        case BAT : _charBattery.writeValue(value);  break;
        default : Serial.println(1/0);
    }
}

bool Bluetooth::IsConnected(){
    return BLE.central().connected();
}