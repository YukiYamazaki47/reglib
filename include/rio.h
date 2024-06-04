#include <Arduino.h>

#ifndef LIB_REGLIB
#define LIB_REGLIB
#define N_REGS 16
#define PAYLOD_SIZE 2
#define MSG_SIZE PAYLOD_SIZE + 2

void default_fn(byte *data[PAYLOD_SIZE]);

class RIO {
public:
    RIO();
    void init(HardwareSerial& serial);
    void update();
    void set_activate(uint8_t id,void (*func)(byte *data[PAYLOD_SIZE]));
private:
    byte buffer[MSG_SIZE];
    void (*fnlut[N_REGS])(byte *data[PAYLOD_SIZE]) = {default_fn};
    HardwareSerial& userial;
};

#endif // LIB_REGLIB