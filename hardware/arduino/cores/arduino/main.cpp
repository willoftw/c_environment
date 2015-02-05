#include <Arduino.h>
#include "Serial.h"

int argc;
char **argv;
#ifndef ISLIB
extern void setup(void);
extern void loop(void);
#endif
int main(int _argc, char **_argv)
{

    argc = _argc;
    argv = _argv;
#ifndef ISLIB
    init();
    setup();
#endif
    
    for (;;) {
#ifndef ISLIB
        loop();
#endif
        if (serialEventRun) serialEventRun();
    }
        
    return 0;
}

