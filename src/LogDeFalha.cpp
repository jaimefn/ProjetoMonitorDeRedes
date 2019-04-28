#include <Headers\LogDeFalha.h>

LogDeFalhas logDeFalhas;


File LogDeFalhas::file;

void LogDeFalhas::CriarLog(byte identificador){
    grava_SD(identificador);
}



void LogDeFalhas::LimparLog(){
    SD.remove("log.txt");
}


void LogDeFalhas::grava_SD(byte identificador)
{
    char bfString[60];
    RelogioRTC r(20,21);
    Time dt = r.getTime(); 
   sprintf(bfString, "%02d:%02d:%02d - %02d/%02d/%04d",dt.hour,dt.min,dt.sec,dt.date,dt.mon,dt.year);


  if(abre_arquivo_gravacao("log.txt")){
  
    file.print("Rede[");
    file.print(identificador);
    file.println("]: ");
    file.println("RESETOU - ");
    file.print(bfString);  
    file.println(";");

  fecha_arquivo();

  }else{
      Serial.println("Erro ao Abrir Arquivo!");
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