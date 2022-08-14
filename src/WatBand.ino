#include "Bluetooth.h"
#include "CO.h"
#include "Gyro.h"

//Init.
CO co(A0);
Gyro gyro();
Bluetooth ble("WatBand");

short sampleBuffer[WRITE_BUFFER_SIZE]
volatile int samplesRead;
#define led                             false

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  while (!Serial);
  ble.begin();
}

void loop() {
  // put your main code here, to run repeatedly:

  // save function in local BLE
  
  // send to bluetooth
  while (ble.IsConnected()){
    ble.transmit(CO, co.readValue());
    ble.transmit(GyroX, gyro.readValue(X));
    ble.transmit(GyroY, gyro.readValue(Y));
    ble.transmit(GyroZ, gyro.readValue(Z));
    digitalWrite(LED_BUILTIN, !WatBand::led);
    delay(500);
  }
}
