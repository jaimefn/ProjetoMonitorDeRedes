#include <Headers\FuncoesUteis.h>

void FuncoesUteis::ImprimirByteAsIntArray(uint8_t *ptr)
{

  while (*ptr != 0)
  {
    //Serial.print((int)*ptr++);
  }
  //Serial.println();
}

void FuncoesUteis::copiarIp(char *arrayOriginal, char *arrayCopy, uint8_t arraySize)
{
  if (arraySize > 0)
  {
    while (arraySize--){
      *arrayCopy++ = *arrayOriginal++;
    }   
  }
}

void FuncoesUteis::copiarArray(char *arrayOriginal, char *arrayCopy, uint8_t arraySize, uint8_t maxSize)
{

  if(arraySize >= maxSize) arraySize = maxSize - 1;

  if (arraySize > 0)
  {
    while (arraySize--){
      *arrayCopy++ = *arrayOriginal++;
    }
    *arrayCopy = 0x00;    
  }
}

uint16_t FuncoesUteis::ConvertCharArrayToByte(char *ptr)
{
  return (uint16_t)strtoul(ptr, NULL, 10);
}

uint16_t FuncoesUteis::ConvertCharArrayToByte(char *ptr, uint8_t base)
{
  return (uint16_t)strtoul(ptr, NULL, base);
}

void FuncoesUteis::CopiarIpParaByteArray(const char *str, char sep, char *bytes, uint8_t maxBytes, uint8_t base)
{
  for (int i = 0; i < maxBytes; i++)
  {
    bytes[i] = (char)strtoul(str, NULL, base); // Convert byte
    str = strchr(str, sep);                    // Find next separator
    if (str == NULL || *str == '\0')
    {
      break; // No more separators, exit
    }
    str++; // Point to next character after separator
  }
}


void FuncoesUteis::ImprimirByteAsCharArray(uint8_t *ptr)
{
  while (*ptr != 0)
  {
    //Serial.print((char)*ptr++);
  }
 // Serial.println();
}
