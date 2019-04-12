#ifndef _CTRL_RESETS_H
#define _CTRL_RESETS_H

#include <Headers\BancoDeDados.h>
#include <Headers\StructData.h>

class Reset
{
  public:
    Reset();
    void Zerar();
    void Incrementar(byte rede);
    uint8_t GetResets(uint8_t rede);

  private:
    formStatus frmStatus;
};

extern Reset CtrlResets;

#endif