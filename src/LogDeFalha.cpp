#include <Headers\LogDeFalha.h>

LogDeFalhas logDeFalhas;


File LogDeFalhas::file;

void LogDeFalhas::CriarLog(byte identificador){
    grava_SD(identificador);
}



void LogDeFalhas::LimparLog(){
    SD.remove("Dados.txt");
}


void LogDeFalhas::grava_SD(byte identificador)
{
  String dateTime = relogio.GetTimeString();
  if(abre_arquivo_gravacao("Dados.txt")){
  
    file.print(dateTime);
    file.print(" -> Rede[");
    file.print(identificador);
    file.println("];");

  fecha_arquivo();

  }else{
      Serial.println("Erro ao Abrir Arquivo");
  }

}
 

int LogDeFalhas::abre_arquivo_gravacao(char filename[])
{
  file = SD.open(filename, FILE_WRITE);
 
  if (file)
  {
    return 1;
  } else
  {
    return 0;
  }
}
 
void LogDeFalhas::fecha_arquivo()
{
  if (file)
  {
    file.close();
  }
}