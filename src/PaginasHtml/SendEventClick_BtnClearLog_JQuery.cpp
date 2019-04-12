   #include <EtherCard.h>

void SendEventClick_BtnClearLog()
{
    char *page = PSTR("\r\n\r\n\r\n"
"               $('#main-content').on('click','#btnClearLog',function () {\r\n"
"                    var txtip = $('#ipBuffer').attr('data-ipBuffer');\r\n"
"                    var txtid = $('#ipBuffer').attr('data-idBuffer');\r\n"
"                    var myUrl = 'http://' + txtip + '/?Session=' + txtid; \r\n"
"                      var myData = $.ajax({\r\n"
"                        url: myUrl,\r\n"
"                        data: {btnClearLog: 'true'},\r\n"
"                        dataType: 'json',\r\n"
"                        timeout: 5000,\r\n"
"                        success: function (data) {                         \r\n"
"                        $('#main-content #LogList').html(\"<li class='list-group-item'>Nenhum Registro de Falha Localizado</li>\"); \r\n"
"                        }});\r\n"
"                    myData.error(function (xhr, status, errorThrown) {\r\n"
"                      alert('Não foi Possível Excluir os registros!, tente reiniciar o equipamento.');\r\n"
"                    });\r\n"
"                });\r\n"
"\r\n\r\n\r\n\r\n");
    ether.fillAndSend(page, sizeof page);
} 