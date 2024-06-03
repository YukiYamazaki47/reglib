#include <Arduino.h>

#ifndef LIB_REGLIB
#define LIB_REGLIB

void default_fn(byte data[]);

class rio {
public:
    rio();
    void init();
    void update();
    void set_update();
private:
    byte buffer[4];
    void (*fnlut[16])(byte data[2]) = {default_fn};
};

#endif // LIB_REGLIB