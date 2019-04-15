#ifndef _JSON_H
#define _JSON_H

#include <ethercard.h>
#include <Headers\Login.h>
#include <Headers\CtrlResets.h>
#include <Headers\CtrlSaidas.h>
#include <Headers\colecao.h>
#include <Headers\RelogioRTC.h>


class JSon
{
public:
  void EnviarStatusEId(char statusLogin);
  void EnviarStatus(char btn, char valor);
  void EnviarStatus();
  void EnviarDadosDoLog();
  void EnviarDateTime();

private:
  void Cabecalho();
};

extern JSon json;

#endif