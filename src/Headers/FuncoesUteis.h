
#ifndef _FUNCOESUTEIS_H
#define _FUNCOESUTEIS_H

#include <stdint.h>
#include <stdlib.h>
#include <string.h>

class FuncoesUteis
{
  public:
    static void copiarIp(char *arrayOriginal, char *arrayCopy, uint8_t arraySize);
    static void ImprimirByteAsIntArray(uint8_t *ptr);
    static void copiarArray(char *arrayOriginal, char *arrayCopy, uint8_t arraySize, uint8_t maxSize);
    static uint16_t ConvertCharArrayToByte(char *ptr);
    static uint16_t ConvertCharArrayToByte(char *ptr, uint8_t base);
    static void CopiarIpParaByteArray(const char *str, char sep, char *bytes, uint8_t maxBytes, uint8_t base);
    static void ImprimirByteAsCharArray(uint8_t *ptr);
};
#endif