#include <EtherCard.h>
#include <Headers\BancoDeDados.h>

extern void ParameterFillAndSend(char *val);
extern void InsereBotaoOpenCloseMenu();

void InsereNomeInterface()
{
      formConfiguracao frmConfiguracao = MemoriaEEPROM.CarregarFormConfiguracao();

    char *page = PSTR("<div class='panel panel-default '>\r\n"
        "<div class='panel-heading'>\r\n"
        "<div class=''>\r\n"
        "<span id='menu-toggle' style='font-size:30px;cursor:pointer;float:left;'>&#9776;</span>\r\n"
        "<h4 class='text-center font-weight-bold'>\r\n");
    ether.fillAndSend(page, sizeof page);
        
    ParameterFillAndSend((char *)frmConfiguracao.nomeInterface);

    page = PSTR("</h4></div></div>\r\n"
                "</div>\r\n");
              
    ether.fillAndSend(page, sizeof page);
}