#include <Arduino.h>
#include "rio.h"

RIO::RIO() {
    cb = buffer;

    cb++;
}

void RIO::update(){
    if (Serial.available() >= MSG_SIZE)
    {
        Serial.readBytes(buffer,MSG_SIZE);

        if (verifyChecksum())
        {
            Serial.write(0x00);
            fnlut[buffer[0] & 0x0f](&cb);
        }else{
            Serial.write(0x00);
        }
    }
}

bool RIO::verifyChecksum() {
    byte checksum = 0x00;
    for (int i = 0; i < MSG_SIZE; i++) {
        checksum ^= buffer[i];
    }
    // If the final checksum is 0, the message is valid
    return (checksum == 0x00);
}

void RIO::set_activate(uint8_t id,void (*func)(byte *data[PAYLOD_SIZE])){
    fnlut[id & 0x0f] = func;
}

void default_fn(byte *data[PAYLOD_SIZE]){}

