#ifndef _LOG_DE_FALHA_H
#define _LOG_DE_FALHA_H

#include <Headers\StructData.h>
#include <Headers\Relogio.h>
#include <SPI.h>
#include <SD.h>

class LogDeFalhas
{
  public:
   void CriarLog(byte identificador);
   void LimparLog();

  private:
  // static const int maxLogs = 20; 
  static File file;

    void grava_SD(byte identificador);
    int abre_arquivo_gravacao(char filename[]);
    void fecha_arquivo();

   };

extern LogDeFalhas logDeFalhas;

#endif