#ifndef _LATENCIA_H
#define _LATENCIA_H

#include <stdint.h>
class Latencia
{
  public:
    Latencia();
    static void add(uint8_t rede, uint32_t latencia);
    static void Zerar(uint8_t rede);
   static uint32_t CalcularMedia(uint8_t rede);

  private:
    static uint32_t latenciaMedia[4];
    static uint16_t quantidadeDeAmostras[4];
};

extern Latencia latencia;

#endif