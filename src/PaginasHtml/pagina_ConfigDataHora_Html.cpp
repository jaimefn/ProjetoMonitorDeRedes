#include <EtherCard.h>
#include <Headers\BancoDeDados.h>
 
extern void ParameterFillAndSend(char* val);

void pagina_ConfigDataHora(){
 
  char bfStringIP[30];
   formNtp frmNtp = MemoriaEEPROM.CarregarFormNtp();
 
    char *page = PSTR(
     "<div class='panel panel-default'>\r\n"
      "        <div class='panel-heading'>\r\n"
      "        <h4 class='panel-title'>\r\n"
      "        Configuracoes de Data e Hora\r\n"
      "        </h4>\r\n"
      "        </div>\r\n"
      "        <div class='panel-body'>\r\n"
      "        <div class='dvStatus'></div>\r\n"
      "        <form action='#' method='get'>\r\n"
      "        <input type='hidden' name='ConfigDataHora' value='true'>\r\n"
      "        <div class='form-group'>\r\n"
      "        <label for='DataHora'>Data e Hora:</label>\r\n"
      "        <input name='DataHora' type='datetime-local' class='form-control' id='DataHora' value='2019-04-12T16:30'>\r\n"
      "        </div>\r\n"
      "        <div class='form-group'>\r\n"
      "        <label for='NTP'>Servidor NTP:</label>\r\n"
      "        <input name='NTP' type='text' pattern='\\d{1,3}\\.\\d{1,3}\\.\\d{1,3}\\.\\d{1,3}' class='form-control' id='NTP' value='");
    ether.fillAndSend(page, sizeof page);

    sprintf(bfStringIP, "%d.%d.%d.%d", frmNtp.ntpAdrress[0], frmNtp.ntpAdrress[1], frmNtp.ntpAdrress[2], frmNtp.ntpAdrress[3]);

    ParameterFillAndSend(bfStringIP);

    page = PSTR("'>\r\n"
               "<span class='help-block'>Porta: 123.</span>\r\n"
      "        </div>\r\n"
      "        <button type='submit' class='btn btn-primary'>Salvar</button>\r\n"
      "        </form>\r\n"
      "        </div>\r\n"
      "        </div>\r\n"
    "</body>\r\n"
    );

    ether.fillAndSend(page,sizeof page);

}