#include <EtherCard.h>

void CloseWrapperContent()
{
 
    char *page = PSTR(
            "</div> <!-- /#main-content -->\r\n"
            "</div> <!-- /#page-content-wrapper -->\r\n");
    ether.fillAndSend(page, sizeof page);

}