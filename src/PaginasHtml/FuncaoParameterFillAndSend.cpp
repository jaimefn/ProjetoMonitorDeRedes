#include <EtherCard.h>



void ParameterFillAndSend(char *val)
{
  while (*val != '\0')
  {
    ether.fillAndSend(*val);
    val++;
  }
}