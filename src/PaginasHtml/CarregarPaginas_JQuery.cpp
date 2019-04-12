#include <EtherCard.h>

void CarregarPaginas_JQuery(){

 char *page = PSTR(
"    $('#link_ctrlcontrole').click(function(){\r\n"
                      "var txtip = $('#ipBuffer').attr('data-ipBuffer');\r\n"
                      "var txtid = $('#ipBuffer').attr('data-idBuffer');\r\n"
                      "var myUrl = 'http://' + txtip + '/?Session=' + txtid + '&' + 'pagina1.htm';\r\n"
"        $('#main-content').load(myUrl);\r\n"
"    });\r\n"

"    $('#link_ping').click(function(){\r\n"
                      "var txtip = $('#ipBuffer').attr('data-ipBuffer');\r\n"
                      "var txtid = $('#ipBuffer').attr('data-idBuffer');\r\n"
                      "var myUrl = 'http://' + txtip + '/?Session=' + txtid + '&' + 'pagina2.htm';\r\n"
"        $('#main-content').load(myUrl);\r\n"
"    });\r\n"


"    $('#link_watchdog').click(function(){\r\n"
                      "var txtip = $('#ipBuffer').attr('data-ipBuffer');\r\n"
                      "var txtid = $('#ipBuffer').attr('data-idBuffer');\r\n"
                      "var myUrl = 'http://' + txtip + '/?Session=' + txtid + '&' + 'pagina3.htm';\r\n"

"        $('#main-content').load(myUrl);\r\n"
"    });\r\n"

"    $('#link_inter_controle').click(function(){\r\n"
                      "var txtip = $('#ipBuffer').attr('data-ipBuffer');\r\n"
                      "var txtid = $('#ipBuffer').attr('data-idBuffer');\r\n"
                      "var myUrl = 'http://' + txtip + '/?Session=' + txtid + '&' + 'pagina4.htm';\r\n"

"        $('#main-content').load(myUrl);\r\n"
"    });\r\n"

"    $('#link_rede').click(function(){\r\n"
                      "var txtip = $('#ipBuffer').attr('data-ipBuffer');\r\n"
                      "var txtid = $('#ipBuffer').attr('data-idBuffer');\r\n"
                      "var myUrl = 'http://' + txtip + '/?Session=' + txtid + '&' + 'pagina5.htm';\r\n"

"        $('#main-content').load(myUrl);\r\n"
"    });\r\n"

"    $('#link_senha').click(function(){\r\n"
                      "var txtip = $('#ipBuffer').attr('data-ipBuffer');\r\n"
                      "var txtid = $('#ipBuffer').attr('data-idBuffer');\r\n"
                      "var myUrl = 'http://' + txtip + '/?Session=' + txtid + '&' + 'pagina6.htm';\r\n"

"        $('#main-content').load(myUrl);\r\n"
"    });\r\n"

"    $('#link_assistencia').click(function(){\r\n"
                      "var txtip = $('#ipBuffer').attr('data-ipBuffer');\r\n"
                      "var txtid = $('#ipBuffer').attr('data-idBuffer');\r\n"
                      "var myUrl = 'http://' + txtip + '/?Session=' + txtid + '&' + 'pagina7.htm';\r\n"

"        $('#main-content').load(myUrl);\r\n"
"    });\r\n"

"    $('#link_log').click(function(){\r\n"
                      "var txtip = $('#ipBuffer').attr('data-ipBuffer');\r\n"
                      "var txtid = $('#ipBuffer').attr('data-idBuffer');\r\n"
                      "var myUrl = 'http://' + txtip + '/?Session=' + txtid + '&' + 'pagina8.htm';\r\n"
"        $('#main-content').load(myUrl);\r\n"
"    });\r\n");

 ether.fillAndSend(page, sizeof page);

}