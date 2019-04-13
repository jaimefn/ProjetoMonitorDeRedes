#include <Headers\paginas_html.h>

PaginaHtml paginaHtml;

void PaginaHtml::CarregarPaginaEncontrada()
{
    char *page = PSTR("HTTP/1.0 302 Found Location: /");

    ether.fillAndSend(page, sizeof(page));
    ether.finalizeConn();
}

void PaginaHtml::RespostaDadosSalvosComSucesso(bool status)
{

    //[{"key":0, "value":300},{"key":1, "value":320}]

    char *page = PSTR("HTTP/1.0 200 OK\r\n"
                      "Access-Control-Allow-Origin: *\r\n"
                      "Content-Type: application/json;charset=utf-8\r\n"
                      "Connection: close\r\n\r\n[{\"key\": 0, \"value\": 1}]\r\n");

    ether.fillAndSend(page, sizeof(page));
    ether.finalizeConn();
}

void PaginaHtml::CarregarPaginaHttpNaoAutorizada()
{
    // Unsupported HTTP request
    // 304 or 501 response would be more appropriate
    char *page = PSTR("HTTP/1.0 401 Unauthorized\r\n"
                      "Content-Type: text/html\r\n\r\n"
                      "<h1>401 Unauthorized</h1>\r\n");

    ether.fillAndSend(page, sizeof(page));
    ether.finalizeConn();
}

void PaginaHtml::CarregarMenuCSS()
{
    Menu_CSS();
}

void PaginaHtml::CarregarCodeJs()
{
    Code_JS();
}

void PaginaHtml::CarregarJQueryJs()
{
    JQuery_JS();
}

void PaginaHtml::CarregarFavIcon()
{
    favicon_png();
}

void PaginaHtml::CarregarPaginaDeLogin()
{
    char bfStringIP[30];
    char bfStringId[10];

    formConfiguracaoDaRede frmConfiguracaoDeRede = MemoriaEEPROM.CarregarFormConfiguracaoDeRede();

    sprintf(bfStringIP, "%d.%d.%d.%d", frmConfiguracaoDeRede.ipAdrress[0], frmConfiguracaoDeRede.ipAdrress[1], frmConfiguracaoDeRede.ipAdrress[2], frmConfiguracaoDeRede.ipAdrress[3]);
    sprintf(bfStringId, "%d", Session.GetRandonId());

    char *page = PSTR("HTTP/1.0 200 OK\r\n"
                      "Content-Type: text/html\r\n"
                      "cache-control: max-age=31536000, public\r\n"
                      "Pragma: cache\r\n\r\n"
                      "<!DOCTYPE html>\r\n"
                      "<html lang='pt-BR'>\r\n"
                      "<head>\r\n"
                      "<title>Controle da Interface</title>\r\n"
                      "<meta http-equiv='Content-Type' content='text/html; charset=utf-8'>\r\n" //iso-8859-1
                      "<meta name='viewport' content='width=device-width, initial-scale=1'>\r\n"
                      
                      
                      //"<link rel='stylesheet' href='bootstrap.css'>\r\n"
                    //"<link rel='stylesheet' href='https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css'>\r\n"
                    "<link rel='stylesheet' href='https://cdn.rawgit.com/jaimefn/cdn/master/bootstrap.css'>\r\n"
                    
  
                    //"<script src='jquery.js'></script>\r\n"                    
                    //"<script src='https://ajax.googleapis.com/ajax/libs/jquery/3.2.1/jquery.min.js'></script>\r\n"
                    "<script src='https://cdn.rawgit.com/jaimefn/cdn/master/jquery.js'></script>\r\n"

                    //"<script src='bootstrap.js'></script>"
                    //"<script src='https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js'></script>\r\n"
                    "<script src='https://cdn.rawgit.com/jaimefn/cdn/master/bootstrap.js'></script>\r\n"
                      
                      
                      "<script>\r\n"
                      "$(document).ready(function () {\r\n"
                      "$('form').submit(function (event) {\r\n"
                      "event.preventDefault();\r\n"
                      "var parametros = $(this).serialize();\r\n"
                      "var txtip = $('#ipBuffer').attr('data-ipBuffer');\r\n"
                      "var txtid = $('#ipBuffer').attr('data-idBuffer');\r\n"
                      "var myUrl = 'http://' + txtip + '/?Session=' + txtid + '&' + parametros;\r\n"
                      "var msg = $(this).prev();\r\n"
                      "$.ajax({\r\n"
                      "url: myUrl,\r\n"
                      "dataType: 'json',\r\n"
                      "timeout: 5000,\r\n"
                      "success: function (data) {\r\n"
                      "$('#ipBuffer').attr('data-idBuffer', data.id);\r\n"
                      "if (data.login != 0) {\r\n"
                      "$(msg).html(\"<div class='alert alert-success'><strong>Sucesso!</strong> Login Realizado com Sucesso.</div>\");\r\n"
                      "var myHomePage = 'http://' + txtip + '/?Session=' + data.id + '&HomePage=true';\r\n"
                      "location.replace(myHomePage);\r\n"
                      "}\r\n"
                      "else {\r\n"
                      "$(msg).html(\"<div class='alert alert-danger'><strong>Login Falhou!</strong> Usuario ou Senha Incorretos.</div>\");\r\n"
                      "}},\r\n"
                      "error: function (xhr, status, errorThrown) {\r\n"
                      "$(msg).html(\"<div class='alert alert-danger'><strong>Falha TimeOut!</strong> Servidor N�o Respondeu.</div>\");\r\n"
                      "},\r\n"
                      "complete: function (jqXHR, status) {\r\n"
                      "$(this).prev().show();\r\n"
                      "setTimeout(function () {\r\n"
                      "$('.alert').hide();\r\n"
                      "}, 5000);}});});});\r\n"
                      "</script>\r\n"
                      "\r\n<style>\r\n"
                      ".logo {\r\n"
                      "padding: 15px 0;\r\n"
                      "font-size: 25px;\r\n"
                      "color: #aaaaaa;\r\n"
                      "font-weight: bold;\r\n"
                      "}\r\n"
                      "</style>\r\n\r\n"
                      "</head><body>\r\n"
                      "<div class='container'>\r\n"
                      "<div class='dvStatus'></div>\r\n"
                      "<div class='row'>\r\n"
                      "<div class='col-sm-2 col-md-4 col-lg-4'>\r\n"
                      "</div>\r\n"
                      "<div class='col-sm-8 col-md-4 col-lg-4'>\r\n"
                      "<div class='text-center' style='padding: 50px 0'>\r\n"
                      "<div class='logo'>Entre com suas credenciais</di>\r\n"
                      "</div>\r\n"
                      "<div class='well'>\r\n"
                      "<form action='#' method='get'>\r\n"
                      "<input type='hidden' name='ValidarLogin' value='true'>\r\n"
                      "<div class='form-group'><label for='User'>Usuario:</label><input name='User' type='text' class='form-control' id='User'  maxlength='20'></div>\r\n"
                      "<div class='form-group'><label for='Senha'>Senha:</label><input name='pwd' type='password' class='form-control' id='Senha' maxlength='20'></div>\r\n"
                      "<button type='submit' class='btn btn-primary'>Entrar</button>\r\n"
                      "</form>\r\n"
                      "</div>\r\n"
                      "</div>\r\n"
                      "<div class='col-sm-2 col-md-4 col-lg-4'>\r\n"
                      "</div>\r\n"
                      "</div>\r\n"
                      "<div id='ipBuffer' data-ipBuffer='");
    ether.fillAndSend(page, sizeof page);

    ParameterFillAndSend(bfStringIP);

    page = PSTR("' data-idBuffer='");
    ether.fillAndSend(page, sizeof page);

    ParameterFillAndSend(bfStringId);

    page = PSTR("'></div>"
                "</div></body></html>\r\n");

    ether.fillAndSend(page, sizeof(page));
    ether.finalizeConn();
}

void PaginaHtml::CarregarPaginaRefresh()
{
    char *page = PSTR("HTTP/1.0 200 OK\r\n"
                      "Content-Type: text/html\r\n"
                      "Pragma: no-cache\r\n\r\n"
                      "<!DOCTYPE html>\r\n"
                      "<html><head><meta http-equiv='refresh' content=\"1; url=?Refresh\" /><title>Atualizando Dados</title></head>\r\n"
                      "<body><div style=\"width:350px;border-radius:0px 20px 0px 20px;border: 2px solid #333; padding:25px\"><h3>Dados Alterados com Sucesso. Aguarde...</h3><p>se nao for direcionado em 3 seg ----> <a href=\"?Refresh\">Voltar</a></p></div></body></html>\r\n");

    ether.fillAndSend(page, sizeof(page));
    ether.finalizeConn();
}

void PaginaHtml::CarregarHomePage()
{
    char *page;

    MainOpenCabecalho();

    //MainOpenJQuery();

    //CloseOpenBotaoMenuLateral_JQuery();
    //SendEventClick_BtnClearLog();
    //SendEventClick_BtnTblReset();
    //SendEventClickBtnControlToHost();
    //SendEventSubmit();
    //AtualizarPagina();

    //CarregarPaginas_JQuery();

    //MainCloseJQuery();

    //InsereStyleParaMenuLateral();

    MainCloseCabecalho();

    MainOpenBody(); //<body>

    InsereWrapperAndMenuLateral(); //  wrapper e menu lateral

    InsereWrapperContent(); // wrapper content

    InsereNomeInterface(); // nome da interface

    InsereDivMsg();

    InsereMainContent(); //-> conteudo dinamico vem aqui dentro

    pagina_inicial();

    CloseWrapperContent();

    InsereIpBufferAndIdBuffer();

    MainCloseBody();

    ether.finalizeConn();
}

void PaginaHtml::CarregarPagina1()
{
    pagina_inicial();
    ether.finalizeConn();
}

void PaginaHtml::CarregarPagina2()
{

    pagina_ConfigPing();
    ether.finalizeConn();
}

void PaginaHtml::CarregarPagina3()
{

    pagina_WDT();
    ether.finalizeConn();
}

void PaginaHtml::CarregarPagina4()
{
    pagina_ConfigInterface();
    ether.finalizeConn();
}

void PaginaHtml::CarregarPagina5()
{
    pagina_ConfigDeRede();
    ether.finalizeConn();
}

void PaginaHtml::CarregarPagina6()
{
    pagina_MudarSenha();
    ether.finalizeConn();
}

void PaginaHtml::CarregarPagina7()
{
    pagina_AssistenciaTecnica();
    ether.finalizeConn();
}

void PaginaHtml::CarregarPagina8()
{
    Inserir_logfalhas();
    ether.finalizeConn();
}

void PaginaHtml::CarregarPagina9()
{
    pagina_ConfigDataHora();
    ether.finalizeConn();
}

void PaginaHtml::EnviarCssFile(char *nome)
{                        
    EnviarArquivo(nome, "text/css");
}
void PaginaHtml::EnviarJsFile(char *nome)
{
    EnviarArquivo(nome, "text/javascript");
}
void PaginaHtml::EnviarIcoFile(char *nome)
{
    EnviarArquivo(nome, "image/x-icon");
}
void PaginaHtml::EnviarHtmlFile(char *nome)
{
    EnviarArquivo(nome, "text/html");
}

void PaginaHtml::EnviarArquivo(char *nome, char *tipo)
{

    File myFile;
    char *page;

    myFile = SD.open(nome);
    if (myFile)
    {

        page = PSTR("HTTP/1.0 200 OK\r\nContent-Type: ");
        ether.fillAndSend(page, sizeof(page));

        
        ether.fillAndSend(tipo,false);

        page = PSTR("\r\nConnection: close\r\ncache-control: max-age=31536000, public\r\n\r\n");
        ether.fillAndSend(page, sizeof(page));

        Serial.print("Enviando arquivo: ");
        Serial.println(nome);

        char val;
        while (myFile.available())
        {
            val = (char)myFile.read();
            resetarCpu.ZerarWdt();
            ether.fillAndSend(val);
        }

        ether.finalizeConn();
        myFile.close();
        Serial.println("Concluido.");
        return;
    }

    page = PSTR("HTTP/1.0 302 Found Location: /");

    ether.fillAndSend(page, sizeof(page));
    ether.finalizeConn();

    Serial.print("Nao foi possivel acessar o arquivo: ");
}

