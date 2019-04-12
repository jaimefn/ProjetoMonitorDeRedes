#include <EtherCard.h>

void MainOpenBody()
{
    char *page = PSTR("\r\n\r\n<body>\r\n");
              
    ether.fillAndSend(page, sizeof page);
}