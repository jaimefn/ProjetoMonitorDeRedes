#include <EtherCard.h>

void InsereDivMsg()
{
    char *page = PSTR("<div id='dvmsg'></div>\r\n");
              
    ether.fillAndSend(page, sizeof page);
}