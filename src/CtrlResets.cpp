#include <Headers\CtrlResets.h>

Reset CtrlResets;

    Reset::Reset(){
        frmStatus = MemoriaEEPROM.CarregarFormStatus();
    }
    void Reset::Zerar(){
        for(uint8_t i=0;i<4;i++)
        frmStatus.numeroDeResetRede[i] = 0x00;
        MemoriaEEPROM.SalvarformStatus(frmStatus);   
    }
    void Reset::Incrementar(byte rede){
        if(rede > 3) return;
        frmStatus.numeroDeResetRede[rede]++;
        MemoriaEEPROM.SalvarformStatus(frmStatus);
    }
    uint8_t Reset::GetResets(uint8_t rede){
        return frmStatus.numeroDeResetRede[rede];
    }