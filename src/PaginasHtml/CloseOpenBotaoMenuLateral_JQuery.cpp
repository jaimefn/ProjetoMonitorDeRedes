#include <EtherCard.h>

void CloseOpenBotaoMenuLateral_JQuery()
{
 
    char *page = PSTR(
            "$('#menu-toggle').click(function (e) {\r\n"
            "        e.preventDefault();\r\n"
            "        $('#wrapper').toggleClass('toggled');\r\n"
            "   });\r\n\r\n" );
    ether.fillAndSend(page, sizeof page);

}