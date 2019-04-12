#ifndef _CONTROLE_DAS_SAIDAS
#define _CONTROLE_DAS_SAIDAS

#include <arduino.h>
#include <Headers\StructData.h>
#include <Headers\BancoDeDados.h>

#define PIN_SAIDA_1 8  //12
#define PIN_SAIDA_2 9  // 11
#define PIN_SAIDA_3 10 //10
#define PIN_SAIDA_4 11 //9

class CtrlSaidas
{
public:
  CtrlSaidas();
  void AtualizarRelogio();
  void Ativar(uint8_t saida);
  void Desativar(uint8_t saida, uint16_t _tempo);
  bool RetornarStatusDasSaidas(uint8_t saida);

private:
  unsigned long bfTempoReset[4] = {0,0,0,0};
  unsigned long  tempo[4] = {0,0,0,0};
  bool bfStatusSaida[4] = {false,false,false,false};


  formControleSaidas frmControleDasSaidas;
  bool TempoDeResetDaRedeOk(uint8_t saida);
  void AtualizarRelogioTempoDeResetDaRede(uint8_t saida, uint16_t _tempo);
  void AtivarSaida(uint8_t pinoSaida);
  void DesativarSaida(uint8_t pinoSaida);
  uint8_t RetornarPinoDeSaida(uint8_t saida);
};

extern CtrlSaidas controleDasSaidas;

#endif