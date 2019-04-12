#include <EtherCard.h>

void pagina_AssistenciaTecnica()
{

   char *page = PSTR("<div class='panel panel-default'>\r\n"
        "<div class='panel-heading'>\r\n"
        "<h4 class='panel-title'>\r\n"
        "Assistência Técnica\r\n"
        "</h4>\r\n"
        "</div>\r\n"
        "<div class='panel-body'>\r\n"
        "<div class='well'>"
        "<div class='page-header'>"
        "<h2>Contatos:</h2>"
        "</div>"
        "<p>whatsapp: (81) 9 9950-4253</p>"
        "<p>e-mail: jaime.desenvolvimento@hotmail.com</p>"
        "<br>"
        "<p>Responsavel: Jaime Nascimento</p>"
        "</div>"
        "</div>\r\n"
        "</div>\r\n");
    ether.fillAndSend(page, sizeof page);
}