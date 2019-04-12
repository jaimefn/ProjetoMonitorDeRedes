#include <EtherCard.h>

void SendEventSubmit(){
        char * page = PSTR("\r\n\r\n$('#main-content').on('submit','form',function (event) {\r\n"
                    "event.preventDefault();\r\n"
                    "var parametros = $(this).serialize();\r\n\r\n"
                    "$('#btnControlModal').modal('hide');\r\n"
                    "var txtip = $('#ipBuffer').attr('data-ipBuffer');\r\n"
                    "var txtid = $('#ipBuffer').attr('data-idBuffer');\r\n"
                    "var myUrl = 'http://' + txtip + '/?Session=' + txtid + '&' + parametros;\r\n"
                    "var msg = $(this).prev();\r\n"
                    "var myData = $.ajax({\r\n"
                        "url: myUrl,\r\n"
                        "dataType: 'json',\r\n"
                        "timeout: 5000,\r\n"
                        "success: function (data) {\r\n"
                                "if (data.value == 1) {\r\n"
                                    "$(msg).html(\"<div class='alert alert-success'><strong>Sucesso!</strong> Os Dados Foram Salvos.</div>\");\r\n"
                                "}\r\n"
                                "else {\r\n"
                                    "$(msg).html(\"<div class='alert alert-danger'><strong>Falha!</strong> Não foi Possível Salvar Os Dados.</div>\");\r\n"
                                "}\r\n"
                                "$(this).prev().show();\r\n"
                                "setTimeout(function () {\r\n"
                                    "$('.alert').hide();\r\n"
                                "}, 3000);\r\n"
                        "}});\r\n"
                    "myData.error(function (xhr, status, errorThrown) {\r\n"
                        "$(msg).html(\"<div class='alert alert-danger'><strong>Falha TimeOut!</strong> Servidor Não Respondeu.</div>\");\r\n"
                    "});\r\n"
                "});\r\n\r\n\r\n");

     ether.fillAndSend(page, sizeof page);
}