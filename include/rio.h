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
    void update();
    void set_activate(uint8_t id,void (*func)(byte *data[PAYLOD_SIZE]));
private:
    byte buffer[MSG_SIZE];
    byte *cb;
    void (*fnlut[N_REGS])(byte *data[PAYLOD_SIZE]) = {default_fn};
    bool verifyChecksum(byte* message);
};

#endif // LIB_REGLIB