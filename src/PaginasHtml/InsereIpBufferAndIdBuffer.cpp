#include <EtherCard.h>
#include <Headers\Login.h>
#include <Headers\BancoDeDados.h>

extern void ParameterFillAndSend(char *val);

void InsereIpBufferAndIdBuffer()
{
      char bfStringIP[30];
      formConfiguracaoDaRede frmConfiguracaoDeRede = MemoriaEEPROM.CarregarFormConfiguracaoDeRede();

    char *page = PSTR("<div id='ipBuffer' data-ipBuffer='");
    ether.fillAndSend(page, sizeof page);

    sprintf(bfStringIP, "%d.%d.%d.%d", frmConfiguracaoDeRede.ipAdrress[0], frmConfiguracaoDeRede.ipAdrress[1], frmConfiguracaoDeRede.ipAdrress[2], frmConfiguracaoDeRede.ipAdrress[3]);
    ParameterFillAndSend(bfStringIP);

    page = PSTR("' data-idBuffer='");

    ether.fillAndSend(page, sizeof page);

    char bufferRandomId[30];

    itoa(Session.GetRandonId(), bufferRandomId, 10);

    ParameterFillAndSend((char *)bufferRandomId);

    page = PSTR("'></div>\r\n");
    ether.fillAndSend(page, sizeof page);

}