#include <EtherCard.h>

extern void Inserir_Botoes();
extern void Inserir_tabela();
extern void Inserir_logfalhas();
extern void Inserir_sensores();


void pagina_inicial(){

char *page = PSTR(
"<div id='pagina_inicial'>\r\n"
"<div class='row'>\r\n"
"<div class='col-sm-6'>\r\n");
ether.fillAndSend(page, sizeof page);

Inserir_Botoes();

page = PSTR("</div>\r\n"
"<div class='col-sm-6'>\r\n");
ether.fillAndSend(page, sizeof page);

Inserir_tabela();

page = PSTR("</div>"
"</div><!-- fim row -->\r\n"
"</div><!-- fim pagina_inicial -->\r\n");
ether.fillAndSend(page, sizeof page);

}