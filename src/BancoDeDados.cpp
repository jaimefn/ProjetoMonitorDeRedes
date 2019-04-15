#include <Headers\BancoDeDados.h>


BancoDeDados MemoriaEEPROM;

void BancoDeDados::RestaurarDadosDeFabrica(int cod_rst, bool rst)
{
    
    formEEPROM frmEEProm = CarregarFrmEEProm();
   formConfiguracao frmConfiguracao;
        formConfiguracaoDaRede frmConfiguracaoDeRede;
        formWatchdog frmWatchDog;
        formControleSaidas frmControleDeSaidas;
        formStatus frmStatus;
        formLogin frmLogin;
        formConfiguracaoDoPing frmConfiguracaoDoPing;
        formNtp frmNtp;

    if (rst == true && cod_rst == 0xA5)
    {

        for (uint16_t i = 0; i < _TOTAL_POS; i++)
            EEPROM.write(i, 0x00);

      
        uint8_t ipNulo[] = {0, 0, 0, 0};
                                            //ultimo mac foi o 21
        uint8_t macDefault[] = {0x54, 0x55, 0x58, 0x31, 0x22, 0x21};
        uint8_t ipDefault[] = {192, 168, 2, 110};
        uint8_t gwipDefault[] = {192, 168, 2, 1};
        uint8_t dnsDefault[] = {8, 8, 8, 8};
        uint8_t maskDefault[] = {255, 255, 255, 0};
        uint8_t ntpDefault[] = {192, 168, 2, 1};

        //Restaurar dados de fabrica
        //Login
        FuncoesUteis::copiarArray("admin", frmLogin.Usuario, 5,20);
        FuncoesUteis::copiarArray("admin", frmLogin.Senha, 5,20);

        //Configuracao
        FuncoesUteis::copiarArray("Interface de Controle", frmConfiguracao.nomeInterface, 21,40);
        FuncoesUteis::copiarArray("Saida 1", frmConfiguracao.nomeRede[0], 7,40);
        FuncoesUteis::copiarArray("Saida 2", frmConfiguracao.nomeRede[1], 7,40);
        FuncoesUteis::copiarArray("Saida 3", frmConfiguracao.nomeRede[2], 7,40);
        FuncoesUteis::copiarArray("Saida 4", frmConfiguracao.nomeRede[3], 7,40);

        FuncoesUteis::copiarIp(ipNulo, frmConfiguracao.ipRede[0], 4);
        FuncoesUteis::copiarIp(ipNulo, frmConfiguracao.ipRede[1], 4);
        FuncoesUteis::copiarIp(ipNulo, frmConfiguracao.ipRede[2], 4);
        FuncoesUteis::copiarIp(ipNulo, frmConfiguracao.ipRede[3], 4);

        //configuracao de rede
        FuncoesUteis::copiarIp(macDefault, frmConfiguracaoDeRede.macAdrress, 6);
        FuncoesUteis::copiarIp(ipDefault, frmConfiguracaoDeRede.ipAdrress, 4);
        FuncoesUteis::copiarIp(dnsDefault, frmConfiguracaoDeRede.dnsAdrress, 4);
        FuncoesUteis::copiarIp(gwipDefault, frmConfiguracaoDeRede.gwIpAdrress, 4);
        FuncoesUteis::copiarIp(maskDefault, frmConfiguracaoDeRede.subMascara, 4);
        
        //configurar NTP
        FuncoesUteis::copiarIp(ntpDefault, frmNtp.ntpAdrress, 4);
        frmNtp.status = 1;

        //configuracao do ping
        frmConfiguracaoDoPing.numeroDeBytesDoPing = 1500;
        frmConfiguracaoDoPing.NumeroDePercaDePacotes = 10;
        frmConfiguracaoDoPing.QuantidadeDePingParaEnvio = 100;
        frmConfiguracaoDoPing.TimeOut = 2;


        //WatchDog
        frmWatchDog.maximaQuantidadeDeResets = 5;
        frmWatchDog.tempoDeAcionamento = 30;
        frmWatchDog.tempoDeVarredura = 5;
        frmWatchDog._flagAtivarWD[0] = 0;
        frmWatchDog._flagAtivarWD[1] = 0;
        frmWatchDog._flagAtivarWD[2] = 0;
        frmWatchDog._flagAtivarWD[3] = 0;

        //Status
        frmStatus.numeroDeResetRede[0] = 0;
        frmStatus.numeroDeResetRede[1] = 0;
        frmStatus.numeroDeResetRede[2] = 0;
        frmStatus.numeroDeResetRede[3] = 0;
        frmStatus.tensao = 0;

        //Controles de saidas
        frmControleDeSaidas._flagStatusRede[0] = 1;
        frmControleDeSaidas._flagStatusRede[1] = 1;
        frmControleDeSaidas._flagStatusRede[2] = 1;
        frmControleDeSaidas._flagStatusRede[3] = 1;

        //flag
        frmEEProm._flagRestaurarPadrao = 0x00;
        
        SalvarformEEProm(frmEEProm);
        SalvarformConfiguracao(frmConfiguracao);
        SalvarformControleSaidas(frmControleDeSaidas);
        SalvarformLogin(frmLogin);
        SalvarformNtp(frmNtp);
        SalvarformStatus(frmStatus);
        SalvarformWatchdog(frmWatchDog);
        SalvarformConfiguracaoDaRede(frmConfiguracaoDeRede);
        SalvarformConfiguracaoDoPing(frmConfiguracaoDoPing);

        Serial.println(F("dados de fabrica restaurados com sucesso!!!"));
    }

    
   // ImprimirMemoriaEEPROM(_TOTAL_POS);
}

formEEPROM BancoDeDados::CarregarFrmEEProm()
{
    formEEPROM frmEEProm;
    EEPROM.get(_EEPROM_POS, frmEEProm);

    return frmEEProm;
}

formConfiguracao BancoDeDados::CarregarFormConfiguracao()
{

    formConfiguracao frmConfiguracao;
    EEPROM.get(_CONFIGURACAO_POS, frmConfiguracao);
    return frmConfiguracao;
}

formConfiguracaoDoPing BancoDeDados::CarregarFormConfiguracaoDoPing()
{
    formConfiguracaoDoPing frmConfiguracaoDoPing;
    EEPROM.get(_CONFIG_PING_POS, frmConfiguracaoDoPing);
    return frmConfiguracaoDoPing;
}

formConfiguracaoDaRede BancoDeDados::CarregarFormConfiguracaoDeRede()
{
    formConfiguracaoDaRede frmConfiguracaoDeRede;
    EEPROM.get(_CONFIG_REDE_POS, frmConfiguracaoDeRede);
    return frmConfiguracaoDeRede;
}

formWatchdog BancoDeDados::CarregarFormWatchDog()
{
    formWatchdog frmWatchDog;
    EEPROM.get(_WATCHDOG_POS, frmWatchDog);
    return frmWatchDog;
}

formControleSaidas BancoDeDados::CarregarFormControleSaidas()
{
    formControleSaidas frmControleDeSaidas;
    EEPROM.get(_CONTROLE_SAIDAS_POS, frmControleDeSaidas);
    return frmControleDeSaidas;
}

formStatus BancoDeDados::CarregarFormStatus()
{
    formStatus frmStatus;
    EEPROM.get(_STATUS_POS, frmStatus);
    return frmStatus;
}

formLogin BancoDeDados::CarregarFormLogin()
{
    formLogin frmLogin;
    EEPROM.get(_LOGIN_POS, frmLogin);
    return frmLogin;
}

formNtp BancoDeDados::CarregarFormNtp()
{
    formNtp frmNtp;
    EEPROM.get(_NTP_POS, frmNtp);
    return frmNtp;
}

void BancoDeDados::ModificarFlagDeAlteracaoNoBancoDeDados(bool status)
{
    _bancoDeDadosFoiAlterado = status;
}

void BancoDeDados::SalvarformEEProm(formEEPROM frmEEProm)
{
    EEPROM.put(0, frmEEProm);
    ModificarFlagDeAlteracaoNoBancoDeDados(true);
}

void BancoDeDados::SalvarformConfiguracao(formConfiguracao frmConfiguracao)
{
    EEPROM.put(_CONFIGURACAO_POS, frmConfiguracao);
    ModificarFlagDeAlteracaoNoBancoDeDados(true);
}

void BancoDeDados::SalvarformConfiguracaoDoPing(formConfiguracaoDoPing frmConfiguracaoDoPing)
{
    EEPROM.put(_CONFIG_PING_POS, frmConfiguracaoDoPing);
    ModificarFlagDeAlteracaoNoBancoDeDados(true);
}

void BancoDeDados::SalvarformConfiguracaoDaRede(formConfiguracaoDaRede frmConfiguracaoDeRede)
{
    EEPROM.put(_CONFIG_REDE_POS, frmConfiguracaoDeRede);
}

void BancoDeDados::SalvarformWatchdog(formWatchdog frmWatchDog)
{
    EEPROM.put(_WATCHDOG_POS, frmWatchDog);
    ModificarFlagDeAlteracaoNoBancoDeDados(true);
}

void BancoDeDados::SalvarformControleSaidas(formControleSaidas frmControleDeSaidas)
{
    EEPROM.put(_CONTROLE_SAIDAS_POS, frmControleDeSaidas);
    ModificarFlagDeAlteracaoNoBancoDeDados(true);
}
void BancoDeDados::SalvarformStatus(formStatus frmStatus)
{
    EEPROM.put(_STATUS_POS, frmStatus);
}
void BancoDeDados::SalvarformLogin(formLogin frmLogin)
{
    EEPROM.put(_LOGIN_POS, frmLogin);
}

void BancoDeDados::SalvarformNtp(formNtp frmNtp)
{
    EEPROM.put(_NTP_POS, frmNtp);
}

bool BancoDeDados::VerificarStatusDoBancoDeDados()
{
    return _bancoDeDadosFoiAlterado;
}

void BancoDeDados::ImprimirMemoriaEEPROM(uint16_t tamanhoDaMemoria)
{

    uint8_t j = 0;

    for (uint16_t i = 0; i < tamanhoDaMemoria; i++)
    {
        Serial.print(EEPROM.read(i));
        Serial.print(' ');
        j++;
        if (j == 20)
        {
            Serial.println();
            j = 0;
        }
    }
}