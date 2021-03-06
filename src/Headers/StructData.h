
#ifndef _STRUCTDATA_H
#define _STRUCTDATA_H

#include <stdint.h>
typedef struct formConfiguracao
{
  //-[configuracao]
  char nomeInterface[40];
  char nomeRede[4][40];
  uint8_t ipRede[4][4];
};

typedef struct formEEPROM
{
  uint8_t _flagRestaurarPadrao;
};

typedef struct formConfiguracaoDaRede
{
  //-[ConfiguracaoDaRede]
  uint8_t macAdrress[6];
  uint8_t ipAdrress[4];
  uint8_t gwIpAdrress[4];
  uint8_t dnsAdrress[4];
  uint8_t subMascara[4];
};
typedef struct formConfiguracaoDoPing
{
  //-[ConfiguracaoDoPing]
  uint16_t numeroDeBytesDoPing;
  uint8_t QuantidadeDePingParaEnvio;
  uint8_t NumeroDePercaDePacotes;
  uint8_t TimeOut;
};
typedef struct formControleSaidas
{
  //-[ControleSaidas]
  uint8_t _flagStatusRede[4];
};

typedef struct formWatchdog
{
  //-[watchdog]
  uint8_t tempoDeVarredura;
  uint8_t tempoDeAcionamento;
  uint8_t maximaQuantidadeDeResets;
  uint8_t _flagAtivarWD[4];
};
typedef struct formStatus
{
  //-[status]

  uint8_t numeroDeResetRede[4];
  uint8_t tensao;
};
typedef struct formLogin
{
  //Login
  char Usuario[20];
  char Senha[20];
};

typedef struct formNtp{
    uint8_t ntpAdrress[4];
    uint8_t status;
};

typedef struct BtnControl
{
  //btnControl
  char btn;
  uint16_t tempo;
};

typedef struct Date
{
  uint16_t year;
  uint8_t mouth;
  uint8_t day;
};

typedef struct Time1
{
  uint8_t hour;
  uint8_t min;
  uint8_t sec;
};


typedef struct DateTime
{
  Date date;
  Time1 time;
  uint8_t dayOfWeek;
};

typedef struct DataLog
{
  //dados do log
  DateTime dateTime;
  uint8_t ping;
  uint16_t lat;
  uint8_t reset;
};

typedef struct BufferStatusPing
{
  //status da perca e total de pings ja enviados até o momento
  uint8_t perca[4];
  uint8_t total[4];
  uint8_t rede;
  
};


typedef struct formRelogio
{
  //
  DateTime dateTime;
  formNtp ntp;
};

#endif