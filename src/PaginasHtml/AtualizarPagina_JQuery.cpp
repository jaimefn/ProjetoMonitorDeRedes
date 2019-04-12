#include <EtherCard.h>

void AtualizarPagina()
{
    char *page = PSTR("\r\n\r\n\r\n"
                      "var intervalo = null;"
                      "intervalo =setInterval(function () {"
                      "var txtip = $('#ipBuffer').attr('data-ipBuffer');\r\n"
                      "var txtid = $('#ipBuffer').attr('data-idBuffer');\r\n"
                      "$.get('http://' + txtip + '/?Session=' + txtid + '&GetStatus=true', function (data, status) {\r\n"
                      "if(data.login == 0){\r\n"
                      "clearInterval(intervalo);"
                      "$('#dvmsg').html(\"<div class='alert alert-warning'><strong>Login inválido!</strong> Por Favor Efetue O Login Para Continuar <a href='http://\" + txtip + \"' class='alert-link'>Logar Novamente</a></div>\");\r\n"
                      "return;}\r\n"
                      "$('#ResetRede1').text(data.rstRede1);\r\n"
                      "$('#ResetRede2').text(data.rstRede2);\r\n"
                      "$('#ResetRede3').text(data.rstRede3);\r\n"
                      "$('#ResetRede4').text(data.rstRede4);\r\n"
                      "if(data.statusRede1 == 1)  $('#StatusRede1').html(\"<h4><span class='label label-success'>On</span></h4>\");\r\n"
                      "else   $('#StatusRede1').html(\"<h4><span class='label label-danger'>Off</span></h4>\");\r\n"
                      "if(data.statusRede2 == 1)  $('#StatusRede2').html(\"<h4><span class='label label-success'>On</span></h4>\");\r\n"
                      "else   $('#StatusRede2').html(\"<h4><span class='label label-danger'>Off</span></h4>\");\r\n"
                      "if(data.statusRede3 == 1)  $('#StatusRede3').html(\"<h4><span class='label label-success'>On</span></h4>\");\r\n"
                      "else   $('#StatusRede3').html(\"<h4><span class='label label-danger'>Off</span></h4>\");\r\n"
                      "if(data.statusRede4 == 1)  $('#StatusRede4').html(\"<h4><span class='label label-success'>On</span></h4>\");\r\n"
                      "else   $('#StatusRede4').html(\"<h4><span class='label label-danger'>Off</span></h4>\");\r\n"
                      "}, 'json');\r\n"
                      "}, 3000);\r\n\r\n");
    ether.fillAndSend(page, sizeof page);
}