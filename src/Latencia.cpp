
#include <Headers\Latencia.h>

Latencia latencia;
    
     uint32_t Latencia::latenciaMedia[4] = {0};
     uint16_t Latencia::quantidadeDeAmostras[4] = {0};
 
Latencia::Latencia()
{
    for (uint8_t i = 0; i < 4; i++)   
    Zerar(i);
}

void Latencia::add(uint8_t rede, uint32_t lat)
{
    quantidadeDeAmostras[rede]++;
    latenciaMedia[rede] = latenciaMedia[rede] + lat;
}

void Latencia::Zerar(uint8_t rede)
{
     latenciaMedia[rede] = 0x00;
     quantidadeDeAmostras[rede] = 0x00;
}

uint32_t Latencia::CalcularMedia(uint8_t rede)
{
    return latenciaMedia[rede]/quantidadeDeAmostras[rede];
}
