#include <Arduino.h>
#include "rio.h"

RIO::RIO() {
    cb = &buffer;

    cb++;
}

void RIO::update(){
    if (Serial.available() >= MSG_SIZE)
    {
        Serial.readBytes(buffer,MSG_SIZE);

        

        fnlut[buffer[0] & 0x0f](&cb);
    }
}

void RIO::set_activate(uint8_t id,void (*func)(byte *data[PAYLOD_SIZE])){
    fnlut[id & 0x0f] = func;
}

void default_fn(byte *data[PAYLOD_SIZE]){}

