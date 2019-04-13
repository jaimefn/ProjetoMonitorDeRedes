#ifndef _PAGINAS_HTML_H
#define _PAGINAS_HTML_H

#include <EtherCard.h>
#include <Headers\Login.h>
#include <Headers\StructData.h>
#include <Headers\FuncoesUteis.h>
#include <Headers\BancoDeDados.h>
#include <SPI.h>
#include <SD.h>
#include <Headers\ResetarCpu.h>


class PaginaHtml
{
  public:
    void RespostaDadosSalvosComSucesso(bool status);
    void CarregarPaginaEncontrada();
    void CarregarPaginaHttpNaoAutorizada();
    void CarregarPaginaDeLogin();
    void CarregarPaginaRefresh();
    void CarregarHomePage();
    void CarregarMenuCSS();
    void CarregarCodeJs();
    void CarregarJQueryJs();
    void CarregarFavIcon();
    void CarregarPagina1();
    void CarregarPagina2();
    void CarregarPagina3();
    void CarregarPagina4();
    void CarregarPagina5();
    void CarregarPagina6();    
    void CarregarPagina7();
    void CarregarPagina8();
    void CarregarPagina9();
    void CarregarRGCAjax();
    void EnviarCssFile(char *nome);
    void EnviarJsFile(char *nome);
    void EnviarIcoFile(char *nome);
    void EnviarHtmlFile(char *nome);
    
  private:
    void EnviarArquivo(char *nome, char *tipo);
    
};

extern PaginaHtml paginaHtml;
extern void SendEventClickBtnControlToHost();
extern void SendEventSubmit();
extern void SendEventClick_BtnTblReset();
extern void MainOpenCabecalho();
extern void MainOpenBody();
extern void MainOpenJQuery();
extern void MainCloseCabecalho();
extern void MainCloseBody();
extern void MainCloseJQuery();
extern void pagina_inicial();
extern void pagina_ConfigDeRede();
extern void pagina_ConfigPing();
extern void pagina_ConfigInterface();
extern void pagina_ConfigDataHora();
extern void pagina_WDT();
extern void pagina_MudarSenha();
extern void pagina_AssistenciaTecnica();
extern void tabela_Status();
extern void ParameterFillAndSend(char *val);
extern void AtualizarPagina();
extern void Menu_CSS();
extern void Code_JS();
extern void JQuery_JS();
extern void favicon_png();
extern void modal();
extern void InsereDivMsg();
extern void InsereNomeInterface();
extern void InsereIpBufferAndIdBuffer();
extern void InsereWrapperAndMenuLateral();
extern void InsereWrapperContent();
extern void CloseWrapperContent();
extern void SendEventClick_BtnClearLog();
extern void InsereStyleParaMenuLateral();
extern void InsereTelaControleDasSaidas();
extern void CarregarPaginas_JQuery();
extern void InsereMainContent();
extern void InsereBotaoOpenCloseMenu();
extern void CloseOpenBotaoMenuLateral_JQuery();
extern void Inserir_logfalhas();
#endif