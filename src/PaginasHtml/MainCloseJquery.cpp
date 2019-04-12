#include <EtherCard.h>

void MainCloseJQuery()
{
    char *page = PSTR("});\r\n"
        "</script>\r\n");

    ether.fillAndSend(page, sizeof page);
}