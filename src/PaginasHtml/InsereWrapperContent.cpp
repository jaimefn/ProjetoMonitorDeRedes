#include <EtherCard.h>

extern void  InsereBotaoOpenCloseMenu();

void InsereWrapperContent()
{
 
    char *page = PSTR(
            " <!-- Page Content -->\r\n"
            "<div id='page-content-wrapper'>\r\n");
    ether.fillAndSend(page, sizeof page);

}