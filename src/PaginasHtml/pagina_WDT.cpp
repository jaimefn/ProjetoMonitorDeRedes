#include <EtherCard.h>
#include <Headers\BancoDeDados.h>

void pagina_WDT(){

     formWatchdog frmWatchDog = MemoriaEEPROM.CarregarFormWatchDog();

    char *page = PSTR(
              "<div class='panel panel-default'>\r\n"
              "<div class='panel-heading'>\r\n"
              "<h4 class='panel-title'>\r\n"
              "WatchDog\r\n"
              "</h4>\r\n"
              "</div>\r\n"
              "<div class='panel-body'>\r\n"
              "<div class='dvStatus'></div>\r\n"
              "<form action='#' method='get'>\r\n"
              "<input type='hidden' name='WatchDog' value='true'>\r\n"
              "<div class='form-group'>\r\n"
              "<label for='TempoVarredura'>Tempo entre as Varreduras [Seg]:</label>\r\n"
              "<input name='TempoVarredura' type='number' max='300' min='0' step='1' class='form-control' id='TempoVarredura' value=");
  ether.fillAndSend(page, sizeof page);

  ether.fillAndSend(frmWatchDog.tempoDeVarredura);

  page = PSTR("></div>\r\n"
              "<div class='form-group'>\r\n"
              "<label for='TempoAcionamento'>Tempo de Reacionamento apos reset [Seg]</label>\r\n"
              "<input name='TempoAcionamento' type='number' max='300' min='20' step='10' class='form-control' id='TempoAcionamento' value=");
  ether.fillAndSend(page, sizeof page);

  ether.fillAndSend(frmWatchDog.tempoDeAcionamento);

  page = PSTR(">\r\n"
              "</div>\r\n"
              "<div class='form-group'>\r\n"
              "<label for='QuantidadeResets'>Maxima Quantidade de Resets Permitida</label>\r\n"
              "<input name='QuantidadeResets' type='number' max='100' min='1' step='1' class='form-control' id='QuantidadeResets' value=");
  ether.fillAndSend(page, sizeof page);

  ether.fillAndSend(frmWatchDog.maximaQuantidadeDeResets);

  page = PSTR(">\r\n"
              "</div>\r\n"
              "<div class='form-check'>\r\n"
              "<label class='form-check-label'>\r\n"
              "<input name='chkBTN1' class='form-check-input' type='checkbox'");
  ether.fillAndSend(page, sizeof page);

  page = PSTR("checked");

  if (frmWatchDog._flagAtivarWD[0] != 0)
    ether.fillAndSend(page);

  page = PSTR("> Ativar Monitoramento da Rede 1"
              "</label>\r\n"
              "</div>\r\n"
              "<div class='form-check'>\r\n"
              "<label class='form-check-label'>\r\n"
              "<input name='chkBTN2' class='form-check-input' type='checkbox'");
  ether.fillAndSend(page, sizeof page);

  page = PSTR("checked");

  if (frmWatchDog._flagAtivarWD[1] != 0)
    ether.fillAndSend(page);

  page = PSTR("> Ativar Monitoramento da Rede 2"
              "</label>\r\n"
              "</div>\r\n"
              "<div class='form-check'>\r\n"
              "<label class='form-check-label'>\r\n"
              "<input name='chkBTN3' class='form-check-input' type='checkbox'");
  ether.fillAndSend(page, sizeof page);

  page = PSTR("checked");

  if (frmWatchDog._flagAtivarWD[2] != 0)
    ether.fillAndSend(page);

  page = PSTR("> Ativar Monitoramento da Rede 3"
              "</label>\r\n"
              "</div>\r\n"
              "<div class='form-check'>\r\n"
              "<label class='form-check-label'>\r\n"
              "<input name='chkBTN4' class='form-check-input' type='checkbox'");
  ether.fillAndSend(page, sizeof page);

  page = PSTR("checked");

  if (frmWatchDog._flagAtivarWD[3] != 0)
    ether.fillAndSend(page);

  page = PSTR("> Ativar Monitoramento da Rede 4"
              "</label>\r\n"
              "</div>\r\n"
              "<button type='submit' class='btn btn-primary'>Salvar</button>\r\n"
              "</form>\r\n"
              "</div>\r\n"
              "</div>\r\n"
    );
    ether.fillAndSend(page, sizeof page);
}