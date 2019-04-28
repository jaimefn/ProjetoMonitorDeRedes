
#include <EtherCard.h>
#include <SPI.h>
#include <SD.h>
#include <Headers\ResetarCpu.h>

extern void ParameterFillAndSend(char *val);
extern void InserirGraficos();

void Inserir_logfalhas()
{

    char *page = PSTR("<div class='panel panel-default'>\r\n"
                      "<div class='panel-heading'>\r\n"
                      "<h4 class='panel-title'>\r\n"
                      "LOG DE FALHAS\r\n"
                      "</h4>\r\n"
                      "</div>\r\n"
                      "<div class='panel-body'>\r\n"
                      "<div class='row'>\r\n");
    ether.fillAndSend(page, sizeof page);

            InserirGraficos();

        page = PSTR("</div>\r\n"
            "<div class='row'>\r\n"



      "<div class='panel panel-default'>\r\n"
                      "<div class='panel-heading'><h4>Log - SD CARD</h4></div>\r\n"
                      "<div class='panel-body'>\r\n"
"<div style='overflow-x:scroll'>\r\n"
"<div style='width: 900px; height: 200px'>"


          "<ul id='LogList' class='list-group'>\r\n");

    ether.fillAndSend(page, sizeof page);

    File myFile = SD.open("log.txt");
    if (myFile)
    {
        int num_bytes_read = 0;
        int num_zeros = 0;
        char val;
        char registro[50];

        while (myFile.available())
        {
            num_bytes_read = 0;
            page = PSTR("<li class='list-group-item'><p>");
            ether.fillAndSend(page, sizeof page);
            while (myFile.available())
            {
                val = (char)myFile.read();
                if (val == ';')
                {
                    val = (char)myFile.read(); // pega o '\r'
                    val = (char)myFile.read(); // pega o '\n'
                    break;
                }

                registro[num_bytes_read] = val;
                registro[num_bytes_read + 1] = '\0';
                num_bytes_read++;
            }

            if (num_bytes_read > 5)
                ParameterFillAndSend((char *)registro);

            page = PSTR("</p></li>\r\n");
            ether.fillAndSend(page, sizeof page);

            resetarCpu.ZerarWdt();
        }

        myFile.close();
    }
    else
    {
        page = PSTR("<li class='list-group-item'><p>Nao foi possivel acessar o arquivo!</p></li>\r\n");
        ether.fillAndSend(page, sizeof page);
    }
    page = PSTR("</ul>\r\n"
"</div>\r\n"
 "</div>\r\n"
               "<button type='button' id='btnClearLog' class='btn btn-primary btn-md'>Apagar Log</button>\r\n"

                "</div>\r\n"
                "</div>\r\n"
                "</div>\r\n"
                "</div>\r\n</div>\r\n");
    ether.fillAndSend(page, sizeof page);
}