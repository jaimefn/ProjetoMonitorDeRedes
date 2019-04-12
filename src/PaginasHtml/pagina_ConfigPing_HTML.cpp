#include <EtherCard.h>
#include <Headers\BancoDeDados.h>
 
extern void ParameterFillAndSend(char* val);

void pagina_ConfigPing(){
 
  char bfStringIP[30];
 formConfiguracaoDoPing frmConfiguracaoDoPing = MemoriaEEPROM.CarregarFormConfiguracaoDoPing();
 
 
    char *page = PSTR(
        "<div class='panel panel-default'>\r\n"
              "<div class='panel-heading'>\r\n"
              "<h4 class='panel-title'>\r\n"
              "Configuracoes do Ping\r\n"
              "</h4>\r\n"
              "</div>\r\n"
              "<div class='panel-body'>\r\n"
              "<div class='dvStatus'></div>\r\n"
              "<form action='#' method='get'>\r\n"
              "<input type='hidden' name='ConfigPing' value='true'>\r\n"
              "<div class='form-group'>\r\n"
              "<label for='NumBytesPing'>Numero de Bytes do Ping [bytes]:</label>\r\n"
              "<input name='txtNumBytesPing' type='number' max='1500' min='30' step='1' class='form-control' id='NumBytesPing' value='");
  ether.fillAndSend(page, sizeof page);

  sprintf(bfStringIP, "%d", frmConfiguracaoDoPing.numeroDeBytesDoPing);

  ParameterFillAndSend(bfStringIP);

  page = PSTR("'>\r\n"
              "</div>\r\n"
              "<div class='form-group'>\r\n"
              "<label for='QuantDePings'>Quantidade de Pings a ser Enviados:</label>\r\n"
              "<input name='txtQuantDePings' type='number' max='1000' min='1' step='1' class='form-control' id='QuantDePings' value='");
  ether.fillAndSend(page, sizeof page);

 ether.fillAndSend(frmConfiguracaoDoPing.QuantidadeDePingParaEnvio);

  page = PSTR("'>\r\n"
              "</div>\r\n"
              "<div class='form-group'>\r\n"
              "<label for='TriggerPercaDePacotes'>Quantidade de pings perdidos para dar Reset na Rede:</label>\r\n"
              "<input name='txtTriggerPercaDePacotes' type='number' max='100' min='1' step='1' class='form-control' id='TriggerPercaDePacotes' value='");
  ether.fillAndSend(page, sizeof page);

ether.fillAndSend(frmConfiguracaoDoPing.NumeroDePercaDePacotes);

  page = PSTR("'>\r\n"
              "</div>\r\n"
              "<div class='form-group'>\r\n"
              "<label for='TimeOut'>Tempo de TimeOut:</label>\r\n"
              "<input name='txtTimeOut' type='number' max='3' min='1' step='1' class='form-control' id='TimeOut' value='");
  ether.fillAndSend(page, sizeof page);

ether.fillAndSend(frmConfiguracaoDoPing.TimeOut);

  page = PSTR("'>\r\n"
              "</div>\r\n"
              "<button type='submit' class='btn btn-primary'>Salvar</button>\r\n"
              "</form>\r\n"
              "</div>\r\n"
              "</div>\r\n"
    );

    ether.fillAndSend(page,sizeof page);

}