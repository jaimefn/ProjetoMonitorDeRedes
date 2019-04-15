#include <Headers\RelogioRTC.h>



RelogioRTC::RelogioRTC(uint8_t data, uint8_t sclk): DS1307(data,sclk){
    
}

void RelogioRTC::begin()
{
    
    //Aciona o relogio
    halt(false);
    //Definicoes do pino SQW/Out
    setSQWRate(SQW_RATE_1);
    enableSQW(true);
}

char *RelogioRTC::getDateTimeFormated(){

}

