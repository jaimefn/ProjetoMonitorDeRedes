#ifndef _RELOGIO_H
#define _RELOGIO_H

#include <Headers\StructData.h>
#include <Headers\GerenciadorDeComandosHTTP.h>

#define LEAP_YEAR(_year) ((_year % 4) == 0)

class Relogio
{
  public:
    void begin();
    void SetTime(DateTime time);
    DateTime GetTime();
    String GetTimeString();
    void SincNtpTime(unsigned long ntpTime);
    void UpdateTime();
    void PrintDataTime();
    uint8_t getYear();
    uint8_t getMonth();
    uint8_t getDay();
    uint8_t getHour();
    uint8_t getMin();
    uint8_t getSec();
    
    

  private:
    static DateTime bfTime;
    static bool NtpRequestOk;
    static unsigned long lastNtpTime;
    static byte monthDays[];

    void SendNtpRequest();
    void localTime(unsigned long ntpTime);
    String zero(int a);
    String diaSemana(byte dia);
};

extern Relogio relogio;

#endif