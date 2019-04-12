#include <EtherCard.h>
#include <Headers\BancoDeDados.h>

extern void ParameterFillAndSend(char* val);

void pagina_MudarSenha(){

  formLogin frmLogin = MemoriaEEPROM.CarregarFormLogin();

char *page = PSTR(
    
              "<div class='panel panel-default'>\r\n"
              "<div class='panel-heading'>\r\n"
              "<h4 class='panel-title'>\r\n"
              "Alterar Senha\r\n"
              "</h4>\r\n"
              "</div>\r\n"
              "<div class='panel-body'>\r\n"
              "<div class='dvStatus'></div>\r\n"
              "<form action='#' method='get'>\r\n"
              "<input type='hidden' name='Login' value='true'>\r\n"
              "<div class='form-group'>\r\n"
              "<label for='User'>Usuario:</label>\r\n"
              "<input name='User' type='text' class='form-control' id='User' maxlength='20' value='");
  ether.fillAndSend(page, sizeof page);

  ParameterFillAndSend((char *)frmLogin.Usuario);

  page = PSTR("'>\r\n"
              "</div>\r\n"
              "<div class='form-group'>\r\n"
              "<label for='Senha'>Senha:</label>\r\n"
              "<input name='pwd' type='password' class='form-control' id='Senha' maxlength='20'>\r\n"
              "</div>\r\n"
              "<button type='submit' class='btn btn-primary'>Salvar</button>\r\n"
              "</form>\r\n"
              "</div>\r\n"
              "</div>\r\n"
);
ether.fillAndSend(page,sizeof page);

}