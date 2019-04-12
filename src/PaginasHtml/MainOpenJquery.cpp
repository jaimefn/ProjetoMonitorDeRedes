#include <EtherCard.h>

void MainOpenJQuery()
{
    char *page = PSTR("<script>\r\n"
                      "$(document).ready(function () {\r\n");
    ether.fillAndSend(page, sizeof page);
}

