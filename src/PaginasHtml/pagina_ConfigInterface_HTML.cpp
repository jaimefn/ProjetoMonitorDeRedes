#include <EtherCard.h>
#include <Headers\BancoDeDados.h>
#include <Headers\FuncoesUteis.h>

extern void ParameterFillAndSend(char* val);

void pagina_ConfigInterface(){

     char bfStringIP[30];
     formConfiguracao frmConfiguracao = MemoriaEEPROM.CarregarFormConfiguracao();

    char *page = PSTR(

        "<div class='panel panel-default'>\r\n"
              "<div class='panel-heading'>\r\n"
              "<h4 class='panel-title'>\r\n"
              "Configuracoes da Interface de Controle\r\n"
              "</h4>\r\n"
              "</div>\r\n"
              "<div class='panel-body'>\r\n"
              "<div class='dvStatus'></div>\r\n"
              "<form action='#' method='get'>\r\n"
              "<input type='hidden' name='Configuracao' value='true'>\r\n"
              "<div class='form-group'>\r\n"
              "<label for='NomeInterface'>Nome da Interface:</label>\r\n"
              "<input name='NomeInterface' type='text' maxlength='40' class='form-control' id='NomeInterface' value='");
  ether.fillAndSend(page, sizeof page);

  ParameterFillAndSend((char *)frmConfiguracao.nomeInterface);

  page = PSTR("'>\r\n"
              "</div>\r\n"
              "<div class='form-group'>\r\n"
              "<label for='NomeRede1'>Nome da Rede 1</label>\r\n"
              "<input name='NomeRede1' type='text' maxlength='40' class='form-control' id='NomeRede1' value='");
  ether.fillAndSend(page, sizeof page);

  ParameterFillAndSend((char *)frmConfiguracao.nomeRede[0]);

  page = PSTR("'>\r\n"
              "</div>\r\n"
              "<div class='form-group'>\r\n"
              "<label for='IpRede1'>IP da Rede 1</label>\r\n"
              "<input name='IpRede1' type='text' pattern='\\d{1,3}\\.\\d{1,3}\\.\\d{1,3}\\.\\d{1,3}' class='form-control' id='IpRede1' value='");
  ether.fillAndSend(page, sizeof page);

  sprintf(bfStringIP, "%d.%d.%d.%d", frmConfiguracao.ipRede[0][0], frmConfiguracao.ipRede[0][1], frmConfiguracao.ipRede[0][2], frmConfiguracao.ipRede[0][3]);

  ParameterFillAndSend(bfStringIP);

  page = PSTR("'>\r\n"
              "</div>\r\n"
              "<div class='form-group'>\r\n"
              "<label for='NomeRede2'>Nome da Rede 2</label>\r\n"
              "<input name='NomeRede2' type='text' maxlength='40' class='form-control' id='NomeRede2' value='");
  ether.fillAndSend(page, sizeof page);

  ParameterFillAndSend((char *)frmConfiguracao.nomeRede[1]);

  page = PSTR("'>\r\n"
              "</div>\r\n"
              "<div class='form-group'>\r\n"
              "<label for='IpRede2'>IP da Rede 2</label>\r\n"
              "<input name='IpRede2' type='text' pattern='\\d{1,3}\\.\\d{1,3}\\.\\d{1,3}\\.\\d{1,3}' class='form-control' id='IpRede2' value='");
  ether.fillAndSend(page, sizeof page);

  sprintf(bfStringIP, "%d.%d.%d.%d", frmConfiguracao.ipRede[1][0], frmConfiguracao.ipRede[1][1], frmConfiguracao.ipRede[1][2], frmConfiguracao.ipRede[1][3]);

  ParameterFillAndSend(bfStringIP);

  page = PSTR("'>\r\n"
              "</div>\r\n"
              "<div class='form-group'>\r\n"
              "<label for='NomeRede3'>Nome da Rede 3</label>\r\n"
              "<input name='NomeRede3' type='text' maxlength='40' class='form-control' id='NomeRede3' value='");
  ether.fillAndSend(page, sizeof page);

  ParameterFillAndSend((char *)frmConfiguracao.nomeRede[2]);

  page = PSTR("'>\r\n"
              "</div>\r\n"
              "<div class='form-group'>\r\n"
              "<label for='IpRede3'>IP da Rede 3</label>\r\n"
              "<input name='IpRede3' type='text' pattern='\\d{1,3}\\.\\d{1,3}\\.\\d{1,3}\\.\\d{1,3}' class='form-control' id='IpRede3' value='");
  ether.fillAndSend(page, sizeof page);

  sprintf(bfStringIP, "%d.%d.%d.%d", frmConfiguracao.ipRede[2][0], frmConfiguracao.ipRede[2][1], frmConfiguracao.ipRede[2][2], frmConfiguracao.ipRede[2][3]);

  ParameterFillAndSend(bfStringIP);

  page = PSTR("'>\r\n"
              "</div>\r\n"
              "<div class='form-group'>\r\n"
              "<label for='NomeRede4'>Nome da Rede 4</label>\r\n"
              "<input name='NomeRede4' type='text' maxlength='40'  class='form-control' id='NomeRede4' value='");
  ether.fillAndSend(page, sizeof page);

  ParameterFillAndSend((char *)frmConfiguracao.nomeRede[3]);

  page = PSTR("'>\r\n"
              "</div>\r\n"
              "<div class='form-group'>\r\n"
              "<label for='IpRede4'>IP da Rede 4</label>\r\n"
              "<input name='IpRede4' type='text' pattern='\\d{1,3}\\.\\d{1,3}\\.\\d{1,3}\\.\\d{1,3}' class='form-control' id='IpRede4' value='");
  ether.fillAndSend(page, sizeof page);

  sprintf(bfStringIP, "%d.%d.%d.%d", frmConfiguracao.ipRede[3][0], frmConfiguracao.ipRede[3][1], frmConfiguracao.ipRede[3][2], frmConfiguracao.ipRede[3][3]);

  ParameterFillAndSend(bfStringIP);

  page = PSTR("'>\r\n"
              "</div>\r\n"
              "<button type='submit' class='btn btn-primary'>Salvar</button>\r\n"
              "</form>\r\n"
              "</div>\r\n"
              "</div>\r\n");
    ether.fillAndSend(page, sizeof page);
}