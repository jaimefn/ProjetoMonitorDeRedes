#ifndef _CONEXAO_H
#define _CONEXAO_H

#include <EtherCard.h>
#include <Headers\BancoDeDados.h>
#include <Headers\StructData.h>

 #define ENC28J60_RST  12
 #define ENC28J60_CS   53

class Conexao
{
  public:
       void InicializarEnc28j60();
  private:
         void TestarConexaoComInternet();
         void ResetarEnc28j60();
};

extern Conexao conexao;

#endif