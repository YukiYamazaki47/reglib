#include <Arduino.h>

#ifndef LIB_REGLIB
#define LIB_REGLIB

class rio {
public:
    rio();
    void init();
    void update();
private:
    byte buffer[4];
};

#endif // LIB_REGLIB