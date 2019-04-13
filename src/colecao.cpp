#include <Headers\colecao.h>

BfStatusPing bfStatusPing;
Colecao colecao;

BufferStatusPing BfStatusPing::bufferStatusPing;
uint8_t Colecao::ptr[5] = {0};
//DataLog Colecao::dataLog[4][maxReg];

uint8_t Colecao::bfPing0[maxReg];
uint8_t Colecao::bfPing1[maxReg];
uint8_t Colecao::bfPing2[maxReg];
uint8_t Colecao::bfPing3[maxReg];
uint16_t Colecao::bfLat0[maxReg];
uint16_t Colecao::bfLat1[maxReg];
uint16_t Colecao::bfLat2[maxReg];
uint16_t Colecao::bfLat3[maxReg];
uint8_t Colecao::bfHora0[maxReg];
uint8_t Colecao::bfHora1[maxReg];
uint8_t Colecao::bfHora2[maxReg];
uint8_t Colecao::bfHora3[maxReg];
uint8_t Colecao::bfMin0[maxReg];
uint8_t Colecao::bfMin1[maxReg];
uint8_t Colecao::bfMin2[maxReg];
uint8_t Colecao::bfMin3[maxReg];
uint8_t Colecao::bfDia0[maxReg];
uint8_t Colecao::bfDia1[maxReg];
uint8_t Colecao::bfDia2[maxReg];
uint8_t Colecao::bfDia3[maxReg];
uint8_t Colecao::bfReset0[maxReg];
uint8_t Colecao::bfReset1[maxReg];
uint8_t Colecao::bfReset2[maxReg];
uint8_t Colecao::bfReset3[maxReg];

BfStatusPing::BfStatusPing(){

}

void BfStatusPing::update(uint8_t perca, uint8_t total, uint8_t rede){
    bufferStatusPing.perca[rede] = perca;
    bufferStatusPing.total[rede] = total;
    bufferStatusPing.rede = rede;
}

void BfStatusPing::reset(uint8_t rede){
        bufferStatusPing.perca[rede] = 0;
        bufferStatusPing.total[rede] = 0;
        bufferStatusPing.rede = 0;
}


uint8_t BfStatusPing::getPerca(uint8_t rede){
    return bufferStatusPing.perca[rede];
}
uint8_t BfStatusPing::getTotal(uint8_t rede){
    return bufferStatusPing.total[rede];
}
uint8_t BfStatusPing::getRede(){
    return bufferStatusPing.rede;
}

Colecao::Colecao()
{
    clear();
}

void Colecao::clear()
{
    for (uint8_t i = 0; i < 4; i++)
        ptr[i] = 0;
}

void Colecao::add(uint8_t rede, DataLog datalog)
{
    ShiftCollection(rede);

    switch (rede)
    {
    case 0:
        bfPing0[0] = datalog.ping;
        bfLat0[0] = datalog.lat;
        bfHora0[0] = datalog.dateTime.hora;
        bfMin0[0] = datalog.dateTime.min;
        bfDia0[0] = datalog.dateTime.dia;
        bfReset0[0] = datalog.reset;
        break;

    case 1:
        bfPing1[0] = datalog.ping;
        bfLat1[0] = datalog.lat;
        bfHora1[0] = datalog.dateTime.hora;
        bfMin1[0] = datalog.dateTime.min;
        bfDia1[0] = datalog.dateTime.dia;
        bfReset1[0] = datalog.reset;

        break;
    case 2:
        bfPing2[0] = datalog.ping;
        bfLat2[0] = datalog.lat;
        bfHora2[0] = datalog.dateTime.hora;
        bfMin2[0] = datalog.dateTime.min;
        bfDia2[0] = datalog.dateTime.dia;
        bfReset2[0] = datalog.reset;

        break;
    case 3:
        bfPing3[0] = datalog.ping;
        bfLat3[0] = datalog.lat;
        bfHora3[0] = datalog.dateTime.hora;
        bfMin3[0] = datalog.dateTime.min;
        bfDia3[0] = datalog.dateTime.dia;
        bfReset3[0] = datalog.reset;

        break;
    }

    if (ptr[rede] < maxReg)
        ptr[rede]++;
}

DataLog Colecao::get(uint8_t rede, uint8_t regpos)
{
    DataLog dataLog;
    return dataLog;
}

uint8_t Colecao::getPing(uint8_t rede, uint8_t n)
{
    uint8_t val = 0;

    switch (rede)
    {
    case 0: val = bfPing0[n]; break;
    case 1: val = bfPing1[n]; break;
    case 2: val = bfPing2[n]; break;
    case 3: val = bfPing3[n]; break;
    }

    return val;
}
uint16_t Colecao::getLat(uint8_t rede, uint8_t n)
{
    uint16_t val = 0;

    switch (rede)
    {
    case 0: val = bfLat0[n]; break;
    case 1: val = bfLat1[n]; break;
    case 2: val = bfLat2[n]; break;
    case 3: val = bfLat3[n]; break;
    }

    return val;
}
uint8_t Colecao::getReset(uint8_t rede, uint8_t n)
{    uint8_t val = 0;

    switch (rede)
    {
    case 0: val = bfReset0[n]; break;
    case 1: val = bfReset1[n]; break;
    case 2: val = bfReset2[n]; break;
    case 3: val = bfReset3[n]; break;
    }

    return val;

}
uint8_t Colecao::getDia(uint8_t rede, uint8_t n)
{
   uint8_t val = 0;

    switch (rede)
    {
    case 0: val = bfDia0[n]; break;
    case 1: val = bfDia1[n]; break;
    case 2: val = bfDia2[n]; break;
    case 3: val = bfDia3[n]; break;
    }

    return val;

}
uint8_t Colecao::getHora(uint8_t rede, uint8_t n)
{    uint8_t val = 0;

    switch (rede)
    {
    case 0: val = bfHora0[n]; break;
    case 1: val = bfHora1[n]; break;
    case 2: val = bfHora2[n]; break;
    case 3: val = bfHora3[n]; break;
    }

    return val;

}
uint8_t Colecao::getMin(uint8_t rede, uint8_t n)
{
       uint8_t val = 0;

    switch (rede)
    {
    case 0: val = bfMin0[n]; break;
    case 1: val = bfMin1[n]; break;
    case 2: val = bfMin2[n]; break;
    case 3: val = bfMin3[n]; break;
    }

    return val;
}

uint8_t Colecao::getFirstPosition(uint8_t rede)
{
    return ptr[rede];
}

uint8_t Colecao::getMaxRegister()
{
    return maxReg;
}

void Colecao::ShiftCollection(uint8_t rede)
{

    for (uint8_t i = maxReg-1; i > 0; i--)
    {
        switch (rede)
        {
        case 0:
            bfPing0[i] = bfPing0[i - 1];
            bfLat0[i] = bfLat0[i - 1];
            bfHora0[i] = bfHora0[i - 1];
            bfMin0[i] = bfMin0[i - 1];
            bfDia0[i] = bfDia0[i - 1];
            bfReset0[i] = bfReset0[i - 1];

            break;
        case 1:

            bfPing1[i] = bfPing1[i - 1];
            bfLat1[i] = bfLat1[i - 1];
            bfHora1[i] = bfHora1[i - 1];
            bfMin1[i] = bfMin1[i - 1];
            bfDia1[i] = bfDia1[i - 1];
            bfReset1[i] = bfReset1[i - 1];

            break;
        case 2:

            bfPing2[i] = bfPing2[i - 1];
            bfLat2[i] = bfLat2[i - 1];
            bfHora2[i] = bfHora2[i - 1];
            bfMin2[i] = bfMin2[i - 1];
            bfDia2[i] = bfDia2[i - 1];
            bfReset2[i] = bfReset2[i - 1];

            break;
        case 3:
            bfPing3[i] = bfPing3[i - 1];
            bfLat3[i] = bfLat3[i - 1];
            bfHora3[i] = bfHora3[i - 1];
            bfMin3[i] = bfMin3[i - 1];
            bfDia3[i] = bfDia3[i - 1];
            bfReset3[i] = bfReset3[i - 1];
            break;
        }
    }

    print(rede, 1);
}

void Colecao::print(uint8_t rede, uint8_t reg)
{
    /*
    Serial.println("");

    Serial.print(F("rede: "));
    Serial.println(rede);

    Serial.print(F("Ping: "));
    Serial.println(dataLog[rede][reg].ping);
    Serial.print(F("Latencia: "));
    Serial.println(dataLog[rede][reg].lat);
    Serial.print(F("Reset: "));
    Serial.println(dataLog[rede][reg].reset);
    Serial.print(F("Hora: "));
    Serial.println(dataLog[rede][reg].hora);

    Serial.println("");
    */
}
