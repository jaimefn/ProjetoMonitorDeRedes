#include <EtherCard.h>
#include <Headers\BancoDeDados.h>
#include <Headers\RelogioRTC.h>

 
extern void ParameterFillAndSend(char* val);

void pagina_ConfigDataHora(){
 
  RelogioRTC r(20,21);

  Time t = r.getTime();

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
      "        <div class='center-block' style='width: 305px' >\r\n"
      "        <h2><span id='spanDateTime' class='label label-default'>");
       ether.fillAndSend(page, sizeof page);
        sprintf(bfStringIP, "%02d:%02d:%02d - %02d/%02d/%04d",t.hour,t.min,t.sec,t.date,t.mon,t.year);
     
  ParameterFillAndSend(bfStringIP);
  page = PSTR("</span></h2>\r\n"
      "        </div>\r\n"
      "        <div class='dvStatus'></div>\r\n"
      "        <form action='#' method='get'>\r\n"
      "        <input type='hidden' name='ConfigDataHora' value='true'>\r\n"
      "        <div class='form-group'>\r\n"
      "        <label for='DataHora'>Data e Hora:</label>\r\n"
      "        <input name='DataHora' type='datetime-local' class='form-control' id='DataHora' value='");
       ether.fillAndSend(page, sizeof page);
        sprintf(bfStringIP, "%04d-%02d-%02dT%02d:%02d",t.year,t.mon,t.date,t.hour,t.min);
      
  ParameterFillAndSend(bfStringIP);
  page = PSTR("'>\r\n"
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
      "           <script>\r\n"
      "               $(document).ready(function() {\r\n"
      "    	              var o = null;\r\n"
      "                   o = setInterval(function() {\r\n"
      "                     var e = $('#ipBuffer').attr('data-ipBuffer'),\r\n"
      "                     t = $('#ipBuffer').attr('data-idBuffer');\r\n"
      "                     $.get('http://' + e + '/?Session=' + t + '&GetDateTime=true', function(t, a) {\r\n"
      "		                    $('#spanDateTime').html(t.data);\r\n"
      "                     }, 'json')\r\n" 
      "                   }, 1e3);\r\n"
      "                });\r\n"
      "           </script>\r\n"
      "          </body>\r\n"
    );

    ether.fillAndSend(page,sizeof page);

}