

#ifndef _GERENCIADOR_DE_COMANDOS_HTTP_H
#define _GERENCIADOR_DE_COMANDOS_HTTP_H

#include <EtherCard.h>
#include <Headers\Login.h>
#include <Headers\FuncoesUteis.h>
#include <Headers\BancoDeDados.h>
#include <Headers\paginas_html.h>
#include <Headers\ResetarCpu.h>
#include <Headers\CtrlSaidas.h>
#include <Headers\json.h>
#include <Headers\RelogioRTC.h>
#include <Headers\LogDeFalha.h>

class GerenciadorDeComandosHTTP
{
  public:
    
    void GerenciarComandosHTTP();
    void SendNtpRequest();    
  private:

    static uint8_t ntpMyPort;
  
    char *PularCampoSession(char *url);
    char *UrlRetornarId(char *url);
    bool RequisicaoHttpNaoSuportada(char *url);
    char *ApontarParaInicioDosDadosDaUrl(char *url);
    bool UrlGetPagina1Htm(char *url);
    bool UrlGetPagina2Htm(char *url);
    bool UrlGetPagina3Htm(char *url);
    bool UrlGetPagina4Htm(char *url);
    bool UrlGetPagina5Htm(char *url);
    bool UrlGetPagina6Htm(char *url);
    bool UrlGetPagina7Htm(char *url);
    bool UrlGetPagina8Htm(char *url);
    bool UrlGetPagina9Htm(char *url);
    bool UrlGetStatus(char *url);
    bool UrlGetMenuCss(char *url);
    bool UrlGetCodeJs(char *url);
    bool UrlGetJQueryJs(char *url);
    bool UrlGetFavIcon(char *url);
    bool UrlGetReset(char *url);
    bool UrlGetDadosParaGrafico(char *url);
    bool UrlRgBar(char *url);
    bool UrlBtnClearLog(char *url);
    bool UrlSolicitaPaginaDeLogin(char *url);
    bool UrlSolicitaHomePage(char *url);
    bool UrlSalvarWatchDog(char *url);
    bool UrlSalvarConfiguracoes(char *url);
    bool UrlSalvarConfiguracoesDeRede(char *url);
    bool UrlSalvarConfiguracoesDoPing(char *url);
    bool UrlSalvarControleDasSaidas(char *url);
    bool UrlSalvarLogin(char *url);
    bool UrlSalvarRelogio(char *url);
    bool Urlrgckey(char *url);
    bool Urlrgline(char *url);
    bool Urlrgccore(char *url);
    bool Urlrgcajax(char *url);
    char  *FiltrarId(char *url);
    bool UrlValidarId(char *id);
    bool UrlValidarLogin(char *url);
    void RetirarTodosOsParametrosDaMensagem(char *url);
    char *SepararTodosOsParametros(char *url);
    formWatchdog FiltrarParametrosFrmWatchDog(char *url);
    formConfiguracao FiltrarParametrosFrmConfiguracoes(char *url);
    formConfiguracaoDoPing FiltrarParametrosFrmConfiguracoesDoPing(char *url);
    formConfiguracaoDaRede FiltrarParametrosFrmConfiguracoesDeRede(char *url);
    formLogin FiltrarParametrosFrmLogin(char *url);
    formRelogio FiltrarParametrosFrmDateTime(char *url);
    BtnControl FiltrarParametrosFrmControleDasSaidas(char *url);

};

extern GerenciadorDeComandosHTTP HttpManager;

#endif