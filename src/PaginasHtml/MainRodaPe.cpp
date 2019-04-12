#include <EtherCard.h>

void MainRodaPe()
{
    char *page = PSTR("");
    ether.fillAndSend(page, sizeof page);
}