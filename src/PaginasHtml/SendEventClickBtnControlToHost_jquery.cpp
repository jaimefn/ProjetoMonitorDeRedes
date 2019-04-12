#include <EtherCard.h>

void SendEventClickBtnControlToHost(){

char * page = PSTR( 

"\r\n\r\n$('#main-content').on('click','#btnCtrl1',function(event){"
"$('#txtBtnModal').val('1'); "
"$('#btnControlModal').modal('show');"
"});"
"\r\n\r\n$('#main-content').on('click','#btnCtrl2',function(event){"
"$('#txtBtnModal').val('2'); "
"$('#btnControlModal').modal('show');"
"});"
"\r\n\r\n$('#main-content').on('click','#btnCtrl3',function(event){"
"$('#txtBtnModal').val('3'); "
"$('#btnControlModal').modal('show');"
"});"
"\r\n\r\n$('#main-content').on('click','#btnCtrl4',function(event){"
"$('#txtBtnModal').val('4'); "
"$('#btnControlModal').modal('show');"
"});"

);

     ether.fillAndSend(page, sizeof page);
}