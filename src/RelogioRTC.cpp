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

void RelogioRTC::UpdateTime()
{
    static unsigned long tempo = 0;
    static unsigned long TempoParaSincronizar = 0;

    if (millis() - tempo >= 1000)
    {

        if(TempoParaSincronizar >= 3600){ // sincronizar a cada 12 horas(43200) ou ntpRequestOk = false
            SendNtpRequest();
            TempoParaSincronizar = 0;
        }

        tempo = millis();
        TempoParaSincronizar++;
       
    }
}
void RelogioRTC::SendNtpRequest(){
    HttpManager.SendNtpRequest();
}


Time RelogioRTC::localTime(unsigned long ntpTime)
{
    byte monthDays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    unsigned long epoch = ntpTime;
    byte year;
    byte month, monthLength;
    unsigned long days;

    Time time;
    time.sec = epoch % 60;
    epoch /= 60; // now it is minutes
    time.min = epoch % 60;
    epoch /= 60; // now it is hours
    time.hour = epoch % 24;
    epoch /= 24; // now it is days
    time.dow = (epoch + 4) % 7;

    year = 70;
    days = 0;
    while ((unsigned)(days += (LEAP_YEAR(year) ? 366 : 365)) <= epoch)
    {
        year++;
    }
    time.year = year; // *pyear is returned as years from 1900

    days -= LEAP_YEAR(year) ? 366 : 365;
    epoch -= days; // now it is days in this year, starting at 0

    for (month = 0; month < 12; month++)
    {
        monthLength = ((month == 1) && LEAP_YEAR(year)) ? 29 : monthDays[month]; // month==1 -> february
        if (epoch >= monthLength)
        {
            epoch -= monthLength;
        }
        else
        {
            break;
        }
    }

    time.year = year + 1900;
    time.mon = month + 1;              // jan is month 0
    time.date = (uint8_t)epoch + 1; // dia do mes

    return time;
}

