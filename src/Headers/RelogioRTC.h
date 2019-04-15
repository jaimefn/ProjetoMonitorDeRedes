#ifndef _RELOGIORTC_H
#define _RELOGIORTC_H

#include <Headers\StructData.h>
#include <DS1307.h>


class RelogioRTC : public DS1307
{
  public:
    RelogioRTC(uint8_t data, uint8_t sclk);
    void begin();
    char* getDateTimeFormated();
  private:
};

#endif