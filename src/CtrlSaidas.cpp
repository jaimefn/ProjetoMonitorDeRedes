#include <Headers\CtrlSaidas.h>

CtrlSaidas controleDasSaidas;

CtrlSaidas::CtrlSaidas()
{
    for(uint8_t i = 0; i< 4;i++)
    Ativar(i);
}


void CtrlSaidas::AtualizarRelogio()
{
    for(uint8_t i = 0; i < 4; i++){
        if(bfStatusSaida[i] == true){    
            if(TempoDeResetDaRedeOk(i)==true){
                Ativar(i);
                bfStatusSaida[i] = false;
            }
        }
    }
}


void CtrlSaidas::AtualizarRelogioTempoDeResetDaRede(uint8_t saida, uint16_t _tempo)
{
    tempo[saida] =(unsigned long)_tempo * (unsigned long)1000;
    bfStatusSaida[saida] = true;
    bfTempoReset[saida] = millis();
}

bool CtrlSaidas::TempoDeResetDaRedeOk(uint8_t saida)
{
    if ((millis() - bfTempoReset[saida]) > tempo[saida])
    {
          return true;
    }
    return false;
}


bool CtrlSaidas::RetornarStatusDasSaidas(uint8_t saida)
{
    bool status = false;
    
    if( frmControleDasSaidas._flagStatusRede[saida] == 0x01){

        uint8_t pinSaida = A0+saida; //A12+saida
            
            uint16_t val = analogRead(pinSaida);
            
           // Serial.print("valor saida: ");
           // Serial.println(val);

            if(val > 500) status = true;        
    }

    return status;
}

void CtrlSaidas::Ativar(uint8_t saida)
{
     uint8_t pin = 0;

    if (saida > 3)
        return;
    
    frmControleDasSaidas._flagStatusRede[saida] = 0x01;
    pin = RetornarPinoDeSaida(saida);
    
    AtivarSaida(pin);
}

void CtrlSaidas::Desativar(uint8_t saida, uint16_t _tempo)
{
    uint8_t pin = 0;

    frmControleDasSaidas._flagStatusRede[saida] = 0x00;
    pin = RetornarPinoDeSaida(saida);
    
     DesativarSaida(pin);
     AtualizarRelogioTempoDeResetDaRede(saida,_tempo);

}

void CtrlSaidas::AtivarSaida(uint8_t pinoSaida)
{ 
    digitalWrite(pinoSaida, LOW);
}

void CtrlSaidas::DesativarSaida(uint8_t pinoSaida)
{
    digitalWrite(pinoSaida, HIGH);
}

uint8_t CtrlSaidas::RetornarPinoDeSaida(uint8_t saida)
{
    uint8_t pin = 0;

     switch(saida){
        case 0: pin = PIN_SAIDA_4 ; break;
        case 1: pin = PIN_SAIDA_3 ; break;
        case 2: pin = PIN_SAIDA_2 ; break;
        case 3: pin = PIN_SAIDA_1 ; break;
        default: pin = 0; break;
     }

     return pin;
}
