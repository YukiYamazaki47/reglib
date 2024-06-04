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

        

    }
    
}

void set_activate(){
    
}

