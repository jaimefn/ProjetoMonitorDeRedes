#ifndef _COLECAO_H
#define _COLECAO_H

#include <Headers\StructData.h>
#include <EtherCard.h>

class BfStatusPing{
  public:
    BfStatusPing();
   static void update(uint8_t perca, uint8_t total, uint8_t rede);
   static void reset(uint8_t rede);
   static uint8_t getPerca(uint8_t rede);
   static uint8_t getTotal(uint8_t rede);
   static uint8_t getRede();
   
  private:
   static BufferStatusPing bufferStatusPing;
};




class Colecao
{
public:
  Colecao();
  static void clear();
  static void add(uint8_t rede, DataLog datalog);
  static DataLog get(uint8_t rede, uint8_t n);
  static uint8_t getPing(uint8_t rede, uint8_t n);
  static uint16_t getLat(uint8_t rede, uint8_t n);
  static uint8_t getReset(uint8_t rede, uint8_t n);
  static uint8_t getDia(uint8_t rede, uint8_t n);
  static uint8_t getHora(uint8_t rede, uint8_t n);
  static uint8_t getMin(uint8_t rede, uint8_t n);
  static uint8_t getFirstPosition(uint8_t rede);
  static uint8_t getMaxRegister();
  static void print(uint8_t rede, uint8_t reg);

private:
  static const uint8_t maxReg = 20;
 // static DataLog dataLog[4][maxReg];
  static uint8_t bfPing0[maxReg];
  static uint8_t bfPing1[maxReg];
  static uint8_t bfPing2[maxReg];
  static uint8_t bfPing3[maxReg];
  static uint16_t bfLat0[maxReg];
  static uint16_t bfLat1[maxReg];
  static uint16_t bfLat2[maxReg];
  static uint16_t bfLat3[maxReg];
  static uint8_t bfHora0[maxReg];
  static uint8_t bfHora1[maxReg];
  static uint8_t bfHora2[maxReg];
  static uint8_t bfHora3[maxReg];
  static uint8_t bfMin0[maxReg];
  static uint8_t bfMin1[maxReg];
  static uint8_t bfMin2[maxReg];
  static uint8_t bfMin3[maxReg];
  static uint8_t bfDia0[maxReg];
  static uint8_t bfDia1[maxReg];
  static uint8_t bfDia2[maxReg];
  static uint8_t bfDia3[maxReg];
  static uint8_t bfReset0[maxReg];
  static uint8_t bfReset1[maxReg];
  static uint8_t bfReset2[maxReg];
  static uint8_t bfReset3[maxReg];

  static uint8_t ptr[5];

  static void ShiftCollection(uint8_t rede);
};

extern Colecao colecao;
extern BfStatusPing bfStatusPing;
#endif