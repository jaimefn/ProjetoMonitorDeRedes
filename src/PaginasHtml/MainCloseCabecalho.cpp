#include <EtherCard.h>

void MainCloseCabecalho()
{
    char *page = PSTR("</head>\r\n");
    ether.fillAndSend(page, sizeof page);
}