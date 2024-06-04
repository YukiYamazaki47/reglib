#include <Arduino.h>
#include "rio.h"

RIO::RIO() {

}

void init(HardwareSerial& serial = Serial){
    userial = serial;
}

void update(){
    if (userial.available() >= MSG_SIZE)
    {
        userial.readBytes(buffer,MSG_SIZE);

        fnlut[buffer[0] & 0x0f](buffer + 1);
    }
}

void set_activate(uint8_t id,void (*func)(byte *data[PAYLOD_SIZE])){
    fnlut[id & 0x0f] = func;
}

