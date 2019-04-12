#include <EtherCard.h>
#include <Headers\BancoDeDados.h>
 
extern void ParameterFillAndSend(char* val);
extern void modal();

void Inserir_Botoes(){
   
    formConfiguracao frmConfiguracao = MemoriaEEPROM.CarregarFormConfiguracao();
   
  char *page = PSTR(
                "<div class='panel panel-default '>\r\n"
                "<div class='panel-heading'>"
                 "<h4 class='panel-title'>\r\n"
                 "Controle Das Saidas"
                 "</h4></div>\r\n"
                "<div class='panel-body'>\r\n"
                "<button type='button' id='btnCtrl1' class='btn btn-primary btn-block'>\r\n");
    ether.fillAndSend(page, sizeof page);
    ParameterFillAndSend((char *)frmConfiguracao.nomeRede[0]);
    page = PSTR("</button>\r\n"
                "<button type='button' id='btnCtrl2' class='btn btn-primary btn-block'>\r\n");
    ether.fillAndSend(page, sizeof page);
    ParameterFillAndSend((char *)frmConfiguracao.nomeRede[1]);
    page = PSTR("</button>\r\n"
                "<button type='button' id='btnCtrl3' class='btn btn-primary btn-block'>\r\n");
    ether.fillAndSend(page, sizeof page);
    ParameterFillAndSend((char *)frmConfiguracao.nomeRede[2]);
    page = PSTR("</button>\r\n"
                "<button type='button' id='btnCtrl4' class='btn btn-primary btn-block'>\r\n");
    ether.fillAndSend(page, sizeof page);
    ParameterFillAndSend((char *)frmConfiguracao.nomeRede[3]);
    page = PSTR("</button>\r\n");
    ether.fillAndSend(page, sizeof page);

        modal();

    page = PSTR(
        "</div>\r\n"
        "</div>\r\n"
    );
    ether.fillAndSend(page, sizeof page);
    

}