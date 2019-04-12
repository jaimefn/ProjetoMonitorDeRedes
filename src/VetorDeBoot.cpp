#include <Headers\VetorDeBoot.h>

void InicializarSistema()
{

  //wdt_enable(WDTO_8S); // ativa o cao de guarda
  pinMode(PIN_SAIDA_1, OUTPUT);
  pinMode(PIN_SAIDA_2, OUTPUT);
  pinMode(PIN_SAIDA_3, OUTPUT);
  pinMode(PIN_SAIDA_4, OUTPUT);
  pinMode(49, OUTPUT);

  digitalWrite(PIN_SAIDA_1, LOW);
  digitalWrite(PIN_SAIDA_2, LOW);
  digitalWrite(PIN_SAIDA_3, LOW);
  digitalWrite(PIN_SAIDA_4, LOW);

  pinMode(btn_rst_memoria, INPUT_PULLUP);
  pinMode(btn_gnd, OUTPUT);
  digitalWrite(btn_gnd, LOW);



  Serial.begin(115200);
   
   if (!SD.begin(49))
    {
        Serial.println("SD initialization failed!");
    }


  Serial.println("Sistema inicializado...");
}