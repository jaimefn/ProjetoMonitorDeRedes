#include <EtherCard.h>

void tabela_Status()
{

    char *page = PSTR(
        "<div class='panel panel-default '>\r\n"
        "<div class='panel-heading'>"
        "<h4 class='panel-title'>\r\n"
        "Status das Saidas"
        "</h4></div>\r\n"
        "<div class='panel-body'>\r\n"
        "<table class='table table-striped'>\r\n"
        "<thead>\r\n"
        "<tr>\r\n"
        "<th>Saidas</th>\r\n"
        "<th>Resets</th>\r\n"
        "<th>Status</th>\r\n"
        "<th>Link</th>\r\n"
        "</tr>\r\n"
        "</thead>\r\n"
        "<tbody>\r\n"
        "<tr id='rowRede1'>\r\n"
        "<td>Rede 1</td>\r\n"
        "<td id='ResetRede1'>--</td>\r\n"
        "<td id='StatusRede1'>--</td>\r\n"
        "<td id='LinkRede1'>--</td>\r\n"
        "</tr>\r\n"
        "<tr id='rowRede2'>\r\n"
        "<td>Rede 2</td>\r\n"
        "<td id='ResetRede2'>--</td>\r\n"
        "<td id='StatusRede2'>--</td>\r\n"
        "<td id='LinkRede2'>--</td>\r\n"
        "</tr>\r\n"
        "<tr id='rowRede3'>\r\n"
        "<td>Rede 3</td>\r\n"
        "<td id='ResetRede3'>--</td>\r\n"
        "<td id='StatusRede3'>--</td>\r\n"
        "<td id='LinkRede3'>--</td>\r\n"
        "</tr>\r\n"
        "<tr id='rowRede4'>\r\n"
        "<td>Rede 4</td>\r\n"
        "<td id='ResetRede4'>--</td>\r\n"
        "<td id='StatusRede4'>--</td>\r\n"
        "<td id='LinkRede4'>--</td>\r\n"
        "</tr>\r\n"
        "</tbody>\r\n"
        "</table>\r\n"
        "<button type='button' id='btnResetTblStatus' class='btn btn-primary btn-md'>Reset</button>\r\n"
        "</div>\r\n"
        "</div>\r\n");

    ether.fillAndSend(page, sizeof page);
}