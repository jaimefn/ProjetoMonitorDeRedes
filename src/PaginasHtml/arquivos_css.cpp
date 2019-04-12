#include <EtherCard.h>
#include <SPI.h>
#include <SD.h>
#include <Headers\ResetarCpu.h>

void Menu_CSS()
{
    File myFile;
    char *page;
        myFile = SD.open("menu.css");
    if (myFile)
    {

        page = PSTR("HTTP/1.0 200 OK\r\nContent-Type: text/css\r\nConnection: close\r\ncache-control: max-age=31536000, public\r\n\r\n");
        ether.fillAndSend(page, sizeof(page));

        Serial.println("Enviando arquivo");
        int num_bytes_read = 0;
        char val;

        while (myFile.available())
        {

            val = (char)myFile.read();
            ether.fillAndSend(val);
            resetarCpu.ZerarWdt();
        }

        ether.finalizeConn();

        myFile.close();

        Serial.println("fechando envio do css");
        return;
    }

    page = PSTR("HTTP/1.0 302 Found Location: /");

    ether.fillAndSend(page, sizeof(page));
    ether.finalizeConn();

    Serial.println("Nao foi possivel acessar o arquivo");
}
