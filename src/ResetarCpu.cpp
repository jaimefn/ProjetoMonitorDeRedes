#include <Headers\ResetarCpu.h>

ResetarCpu resetarCpu;

bool ResetarCpu::reset = false;

void ResetarCpu::InitWdt(){
    wdt_enable(WDTO_8S);
}

void ResetarCpu::ZerarWdt()
{
    if (!reset)
        wdt_reset();
}
void ResetarCpu::ResetCpu(bool state)
{
    reset = state;
}
