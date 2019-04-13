

#include <Headers\main.h>

int count_clicks = 0;
long int debounce_time = 0;


void teste()
{
  unsigned long tempo = 0;
  DataLog dt;
  
  for (short j = 0; j < 4; j++)
  {
    for (short i =0; i < 19; i++)
    {

      dt.ping = random(0,1);
      dt.reset =  0;
      dt.lat = random(8,20);

  if(j == 0){

  
     if(i == 13){
          dt.ping = 30;
          dt.lat = random(100,255);
          dt.reset = 1;

     }
   
  

     if(i == 10){
      dt.ping = random(15,30);
          dt.lat = random(10,100);
       if(dt.ping == 30) dt.reset = 1;

     }
  } 
  
  if(j == 1){
     if(i == 5){
      dt.ping = random(15,30);
          dt.lat = random(10,100);
       if(dt.ping == 30) dt.reset = 1;

     }
  } 
  
      dt.dateTime.hora = j+1;
      dt.dateTime.min = i*3;
      dt.dateTime.dia = j+1;
      colecao.add(j, dt);
    }
  }
}

void setup()
{

  InicializarSistema();
  //ConfigurarPing();
 // MemoriaEEPROM.RestaurarDadosDeFabrica();

   conexao.InicializarEnc28j60();


  resetarCpu.InitWdt();

  relogio.begin();
 // teste();

  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  }


void loop()
{

  resetarCpu.ZerarWdt();
  relogio.UpdateTime();
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