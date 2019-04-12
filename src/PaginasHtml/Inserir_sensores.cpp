#include <EtherCard.h>

void Inserir_sensores()
{

   char *page = PSTR(
        "<div class='panel panel-default '>\r\n"
        "<div class='panel-heading'>Sensores</div>\r\n"
        "<div class='panel-body'>\r\n"
        "<table class='table table-striped'>\r\n"
        "<thead>\r\n"
        "<tr>\r\n"
        "<th>Sensores</th>\r\n"
        "<th>Valor</th>\r\n"
        "</tr>\r\n"
        "</thead>\r\n"
        "<tbody>\r\n"
        "<tr>\r\n"
        "<td>Tensao</td>\r\n"
        "<td>\r\n"
        "-- V</td>\r\n"
        "</tr>\r\n"
        "<tr>\r\n"
        "<td>Corrente</td>\r\n"
        "<td>--</td>\r\n"
        "</tr>\r\n"
        "<tr>\r\n"
        "<td>Temperatura</td>\r\n"
        "<td>--</td>\r\n"
        "</tr>\r\n"
        "</tbody>\r\n"
        "</table>\r\n"
        "</div>"
        "</div>"
   );
    ether.fillAndSend(page, sizeof page);
}