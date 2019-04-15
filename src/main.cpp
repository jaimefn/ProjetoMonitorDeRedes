

#include <Headers\main.h>

int count_clicks = 0;
long int debounce_time = 0;
RelogioRTC relogioRTC(20,21);


void setup()
{

  InicializarSistema();
  conexao.InicializarEnc28j60();
  resetarCpu.InitWdt();
  relogioRTC.begin();
  delay(100);
  HttpManager.SendNtpRequest();

  }


void loop()
{

  resetarCpu.ZerarWdt();
  relogioRTC.UpdateTime();
  HttpManager.GerenciarComandosHTTP();
  maquinaDeEstado.AtualizarMaquinaDeEstado();
  
  if(digitalRead(btn_rst_memoria) == 0){
  
  if(count_clicks > 0){
    if(millis()-debounce_time > 5000){
      count_clicks = 0;
    }
  }
  
    count_clicks++;
    debounce_time = millis();

    while(digitalRead(btn_rst_memoria) == 0);

    if(count_clicks == 10){
        count_clicks = 0;
        MemoriaEEPROM.RestaurarDadosDeFabrica(0xA5,true);
        resetarCpu.ResetCpu(true);
        Serial.println(F("Memoria Resetada, reiniciando em 8 seg..."));
    }

    delay(100);
  }

}