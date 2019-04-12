#ifndef _BANCO_DE_DADOS_H
#define _BANCO_DE_DADOS_H

#include <arduino.h>
#include <Headers\StructData.h>
#include <Headers\FuncoesUteis.h>
#include <EEPROM.h>

#define _EEPROM_POS 0
#define _CONFIGURACAO_POS sizeof(formEEPROM)
#define _CONFIG_REDE_POS sizeof(formConfiguracao) + sizeof(formEEPROM)
#define _WATCHDOG_POS sizeof(formConfiguracao) + sizeof(formEEPROM) + sizeof(formConfiguracaoDaRede)
#define _CONTROLE_SAIDAS_POS sizeof(formConfiguracao) + sizeof(formEEPROM) + sizeof(formConfiguracaoDaRede) + sizeof(formWatchdog)
#define _STATUS_POS sizeof(formConfiguracao) + sizeof(formEEPROM) + sizeof(formConfiguracaoDaRede) + sizeof(formWatchdog) + sizeof(formControleSaidas)
#define _LOGIN_POS sizeof(formConfiguracao) + sizeof(formEEPROM) + sizeof(formConfiguracaoDaRede) + sizeof(formWatchdog) + sizeof(formControleSaidas) + sizeof(formStatus)
#define _CONFIG_PING_POS sizeof(formConfiguracao) + sizeof(formEEPROM) + sizeof(formConfiguracaoDaRede) + sizeof(formWatchdog) + sizeof(formControleSaidas) + sizeof(formStatus) + sizeof(formLogin)
#define _TOTAL_POS sizeof(formConfiguracao) + sizeof(formEEPROM) + sizeof(formConfiguracaoDaRede) + sizeof(formWatchdog) + sizeof(formControleSaidas) + sizeof(formStatus) + sizeof(formLogin)+ sizeof(formConfiguracaoDoPing)

class BancoDeDados
{
  public:
    void RestaurarDadosDeFabrica(int cod_rst, bool rst);
    void SalvarformLogin(formLogin frmLogin);
    void SalvarformStatus(formStatus frmStatus);
    void SalvarformControleSaidas(formControleSaidas frmControle);
    void SalvarformWatchdog(formWatchdog frmWD);
    void SalvarformConfiguracaoDaRede(formConfiguracaoDaRede frmConfigRede);
    void SalvarformConfiguracao(formConfiguracao frmConfig);
    void SalvarformConfiguracaoDoPing(formConfiguracaoDoPing frmConfiguracaoDoPing);
    void SalvarformEEProm(formEEPROM frmEEProm);
    formLogin CarregarFormLogin();
    formStatus CarregarFormStatus();
    formControleSaidas CarregarFormControleSaidas();
    formWatchdog CarregarFormWatchDog();
    formConfiguracaoDaRede CarregarFormConfiguracaoDeRede();
    formConfiguracao CarregarFormConfiguracao();
    formConfiguracaoDoPing CarregarFormConfiguracaoDoPing();
    formEEPROM CarregarFrmEEProm();
    bool VerificarStatusDoBancoDeDados();
    void ModificarFlagDeAlteracaoNoBancoDeDados(bool status);
    void ImprimirMemoriaEEPROM(uint16_t tamanhoDaMemoria);

  private:
    bool _bancoDeDadosFoiAlterado = false;
 };

extern BancoDeDados MemoriaEEPROM;

#endif