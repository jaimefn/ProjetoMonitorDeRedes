#include <EtherCard.h>

void InsereMainContent()
{
 
    char *page = PSTR("<div id='main-content' class='container-fluid'>\r\n");
    ether.fillAndSend(page, sizeof page);

}