#ifndef _RESETAR_CPU_H
#define _RESETAR_CPU_H

#include <avr/wdt.h>

class ResetarCpu{
public:
    void InitWdt();
    void ZerarWdt();
    void ResetCpu(bool state);

private:
    static bool reset;    
};

extern ResetarCpu resetarCpu;

#endif