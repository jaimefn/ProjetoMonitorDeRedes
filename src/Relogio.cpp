#include <Headers\Relogio.h>

Relogio relogio;

byte Relogio::monthDays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

DateTime Relogio::bfTime;
unsigned long lastNptTime = 10886400;
bool Relogio::NtpRequestOk = false;

void Relogio::begin()
{
    NtpRequestOk = false;
    lastNptTime = 10886400;
    SendNtpRequest();
}

void Relogio::SetTime(DateTime time)
{
}

DateTime Relogio::GetTime()
{
    localTime(lastNptTime);
    return bfTime;
}

String Relogio::GetTimeString()
{
    localTime(lastNptTime);
    return diaSemana(bfTime.diaSemana) + ", " + zero(bfTime.dia) + "/" + zero(bfTime.mes + 1) + "/" + (bfTime.ano + 1900) + " " + zero(bfTime.hora) + ":" + zero(bfTime.min) + ":" + zero(bfTime.seg);
}

void Relogio::SincNtpTime(unsigned long ntpTime)
{
    NtpRequestOk = true;
    lastNptTime = ntpTime;
 
    PrintDataTime();
}

void Relogio::UpdateTime()
{
    static unsigned long tempo = 0;
    static unsigned long TempoParaSincronizar = 0;

    if (millis() - tempo >= 1000)
    {

        if(!NtpRequestOk || TempoParaSincronizar >= 600){ // sincronizar a cada 12 horas(43200) ou ntpRequestOk = false
            SendNtpRequest();
            TempoParaSincronizar = 0;
        }

        tempo = millis();
        lastNptTime++;
        TempoParaSincronizar++;
    }
}

void Relogio::SendNtpRequest(){
    HttpManager.SendNtpRequest();
}

void Relogio::localTime(unsigned long ntpTime)
{
    unsigned long epoch = ntpTime;
    byte year;
    byte month, monthLength;
    unsigned long days;

    bfTime.seg = epoch % 60;
    epoch /= 60; // now it is minutes
    bfTime.min = epoch % 60;
    epoch /= 60; // now it is hours
    bfTime.hora = epoch % 24;
    epoch /= 24; // now it is days
    bfTime.diaSemana = (epoch + 4) % 7;

    year = 70;
    days = 0;
    while ((unsigned)(days += (LEAP_YEAR(year) ? 366 : 365)) <= epoch)
    {
        year++;
    }
    bfTime.ano = year; // *pyear is returned as years from 1900

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

    bfTime.mes = month;              // jan is month 0
    bfTime.dia = (uint8_t)epoch + 1; // dia do mes
}

String Relogio::zero(int a)
{
    if (a >= 10)
    {
        return (String)a + "";
    }
    else
    {
        return "0" + (String)a;
    }
}

String Relogio::diaSemana(byte dia)
{
    String str[] = {"Domingo", "Segunda-feira", "Terça-feira", "Quarta-feira", "Quinta-feira", "Sexta-feira", "Sabado"};
    return str[dia];
}

void Relogio::PrintDataTime()
{
    localTime(lastNptTime);

    String s = diaSemana(bfTime.diaSemana) + ", " + zero(bfTime.dia) + "/" + zero(bfTime.mes + 1) + "/" + (bfTime.ano + 1900) + " " + zero(bfTime.hora) + ":" + zero(bfTime.min) + ":" + zero(bfTime.seg);

    Serial.println(s);
    Serial.println(" ");
}

    uint8_t Relogio::getYear(){
            localTime(lastNptTime);
        return bfTime.ano;
    }
    uint8_t Relogio::getMonth(){
            localTime(lastNptTime);
        return bfTime.mes;
    }
    uint8_t Relogio::getDay(){
            localTime(lastNptTime);
        return bfTime.dia;
    }
    uint8_t Relogio::getHour(){
            localTime(lastNptTime);
        return bfTime.hora;
    }
    uint8_t Relogio::getMin(){
            localTime(lastNptTime);
        return bfTime.min;
    }
    uint8_t Relogio::getSec(){
    localTime(lastNptTime);
        return bfTime.seg;
    }