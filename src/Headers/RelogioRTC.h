#ifndef _RELOGIORTC_H
#define _RELOGIORTC_H

#include <Headers\StructData.h>
#include <Headers\GerenciadorDeComandosHTTP.h>
#include <DS1307.h>

#define LEAP_YEAR(_year) ((_year % 4) == 0)

class RelogioRTC : public DS1307
{
  public:
    RelogioRTC(uint8_t data, uint8_t sclk);
    void begin();
    char* getDateTimeFormated();
    Time localTime(unsigned long ntpTime);
    void UpdateTime();
  private:
    void SendNtpRequest();
};

#endif