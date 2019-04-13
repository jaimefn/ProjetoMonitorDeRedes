#include <EtherCard.h>
#include <Headers\BancoDeDados.h>
 
extern void ParameterFillAndSend(char* val);

void pagina_ConfigDeRede(){
 
 char bfStringIP[30];
 formConfiguracaoDaRede frmConfiguracaoDeRede = MemoriaEEPROM.CarregarFormConfiguracaoDeRede();
 
 
    char *page = PSTR(
        "<div class='panel panel-default'>\r\n"
              "<div class='panel-heading'>\r\n"
              "<h4 class='panel-title'>\r\n"
              "Configuracoes de Rede\r\n"
              "</h4>\r\n"
              "</div>\r\n"
              "<div class='panel-body'>\r\n"
              "<div class='alert alert-warning'>"
              "<strong>Aviso!</strong> Quando clicar em Salvar, O dispositivo ir� reiniciar em 8 Seg.</div>"
              "<div class='dvStatus'></div>\r\n"
              "<form action='#' method='get'>\r\n"
              "<input type='hidden' name='ConfigRede' value='true'>\r\n"
              "<div class='form-group'>\r\n"
              "<label for='txtFrmConfigDeRedeIp'>IP:</label>\r\n"
              "<input name='Ip' type='text' pattern='\\d{1,3}\\.\\d{1,3}\\.\\d{1,3}\\.\\d{1,3}' class='form-control' id='txtFrmConfigDeRedeIp' value='");
  ether.fillAndSend(page, sizeof page);

  sprintf(bfStringIP, "%d.%d.%d.%d", frmConfiguracaoDeRede.ipAdrress[0], frmConfiguracaoDeRede.ipAdrress[1], frmConfiguracaoDeRede.ipAdrress[2], frmConfiguracaoDeRede.ipAdrress[3]);

  ParameterFillAndSend(bfStringIP);

  page = PSTR("'>\r\n"
              "</div>\r\n"
              "<div class='form-group'>\r\n"
              "<label for='dns'>DNS:</label>\r\n"
              "<input name='DNS' type='text' pattern='\\d{1,3}\\.\\d{1,3}\\.\\d{1,3}\\.\\d{1,3}' class='form-control' id='dns' value='");
  ether.fillAndSend(page, sizeof page);

  sprintf(bfStringIP, "%d.%d.%d.%d", frmConfiguracaoDeRede.dnsAdrress[0], frmConfiguracaoDeRede.dnsAdrress[1], frmConfiguracaoDeRede.dnsAdrress[2], frmConfiguracaoDeRede.dnsAdrress[3]);

  ParameterFillAndSend(bfStringIP);

  page = PSTR("'>\r\n"
              "</div>\r\n"
              "<div class='form-group'>\r\n"
              "<label for='GatWay'>GatWay:</label>\r\n"
              "<input name='GatWay' type='text' pattern='\\d{1,3}\\.\\d{1,3}\\.\\d{1,3}\\.\\d{1,3}' class='form-control' id='GatWay' value='");
  ether.fillAndSend(page, sizeof page);

  sprintf(bfStringIP, "%d.%d.%d.%d", frmConfiguracaoDeRede.gwIpAdrress[0], frmConfiguracaoDeRede.gwIpAdrress[1], frmConfiguracaoDeRede.gwIpAdrress[2], frmConfiguracaoDeRede.gwIpAdrress[3]);

  ParameterFillAndSend(bfStringIP);

  page = PSTR("'>\r\n"
              "</div>\r\n"
              "<div class='form-group'>\r\n"
              "<label for='SubMasc'>SubMascara:</label>\r\n"
              "<input name='SubMasc' type='text' pattern='\\d{1,3}\\.\\d{1,3}\\.\\d{1,3}\\.\\d{1,3}' class='form-control' id='SubMasc' value='");
  ether.fillAndSend(page, sizeof page);

  sprintf(bfStringIP, "%d.%d.%d.%d", frmConfiguracaoDeRede.subMascara[0], frmConfiguracaoDeRede.subMascara[1], frmConfiguracaoDeRede.subMascara[2], frmConfiguracaoDeRede.subMascara[3]);

  ParameterFillAndSend(bfStringIP);

  page = PSTR("'>\r\n"
              "</div>\r\n"
              "<div class='form-group'>\r\n"
              "<label for='Mac'>MAC:</label>\r\n"
              "<input name='MAC' type='text' pattern='^([0-9A-Fa-f]{2}[:]){5}([0-9A-Fa-f]{2})$'class='form-control' id='Mac' value='");
  ether.fillAndSend(page, sizeof page);

  sprintf(bfStringIP, "%02x:%02x:%02x:%02x:%02x:%02x", frmConfiguracaoDeRede.macAdrress[0], frmConfiguracaoDeRede.macAdrress[1], frmConfiguracaoDeRede.macAdrress[2], frmConfiguracaoDeRede.macAdrress[3], frmConfiguracaoDeRede.macAdrress[4], frmConfiguracaoDeRede.macAdrress[5]);

  ParameterFillAndSend(bfStringIP);

  page = PSTR("'>\r\n"
              "<span class='help-block'>formato [ xx:xx:xx:xx:xx:xx ].</span>\r\n"
              "</div>\r\n"
              "<button type='submit' class='btn btn-primary'>Salvar</button>\r\n"
              "</form>\r\n"
              "</div>\r\n"
              "</div>\r\n"
    );

    ether.fillAndSend(page,sizeof page);

}