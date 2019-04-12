#include <EtherCard.h>

void MainCloseBody()
{
    char *page = PSTR("</div> <!-- /#Wrapper --> \r\n"
              "</body>\r\n"
              "</html>\r\n");
    ether.fillAndSend(page, sizeof page);
}