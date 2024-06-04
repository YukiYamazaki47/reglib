#include <Arduino.h>

#ifndef LIB_REGLIB
#define LIB_REGLIB
#define N_REGS 16
#define PAYLOD_SIZE 2
#define MSG_SIZE PAYLOD_SIZE + 2

void default_fn(byte data[]);

class rio {
public:
    rio();
    void init(HardwareSerial& serial);
    void update();
    void set_update();
private:
    byte buffer[MSG_SIZE];
    void (*fnlut[N_REGS])(byte data[PAYLOD_SIZE]) = {default_fn};
};

#endif // LIB_REGLIB