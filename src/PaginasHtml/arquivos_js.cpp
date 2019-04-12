#include <EtherCard.h>
#include <SPI.h>
#include <SD.h>
#include <Headers\ResetarCpu.h>





void Code_JS()
{
    File myFile;
    char *page;
    myFile = SD.open("code.js");
    if (myFile)
    {
        Serial.println("Enviando arquivo Code.js");
        page = PSTR("HTTP/1.0 200 OK\r\nContent-Type: text/javascript\r\nConnection: close\r\ncache-control: max-age=31536000, public\r\n\r\n");
        ether.fillAndSend(page, sizeof(page));

        int num_bytes_read = 0;
        char val;
        while (myFile.available())
        {
            val = (char)myFile.read();
            resetarCpu.ZerarWdt();
            ether.fillAndSend(val);
        }

        ether.finalizeConn();
        myFile.close();

        Serial.println("fechando envio do arquivo Code.js");
        return;
    }
    page = PSTR("HTTP/1.0 302 Found Location: /");

    ether.fillAndSend(page, sizeof(page));
    ether.finalizeConn();
    Serial.println("Nao foi possivel acessar o arquivo.js");
}

void JQuery_JS()
{
    File myFile;

    char *page;

    myFile = SD.open("jquery.js");
    if (myFile)
    {

        page = PSTR("HTTP/1.0 200 OK\r\nContent-Type: text/javascript\r\nConnection: close\r\ncache-control: max-age=31536000, public\r\n\r\n\r\n");
        ether.fillAndSend(page, sizeof(page));

        Serial.println("Enviando arquivo jquery.js");
        int num_bytes_read = 0;
        char val;
        while (myFile.available())
        {
            val = (char)myFile.read();
            resetarCpu.ZerarWdt();
            ether.fillAndSend(val);
        }
        ether.finalizeConn();
        myFile.close();
        Serial.println("fechando envio do arquivo jquery.js");
        return;
    }
    page = PSTR("HTTP/1.0 302 Found Location: /");

    ether.fillAndSend(page, sizeof(page));
    ether.finalizeConn();
    Serial.println("Nao foi possivel acessar o arquivo.js");
}

void favicon_png()
{
    File myFile;

    char *page = PSTR("HTTP/1.0 200 OK\r\nContent-Type: image/x-icon\r\nConnection: close\r\ncache-control: max-age=31536000, public\r\n\r\n");
    ether.fillAndSend(page, sizeof(page));

    myFile = SD.open("favicon.ico");
    if (myFile)
    {

        Serial.println("Enviando arquivo favicon.ico");
        int num_bytes_read = 0;
        char val;
        while (myFile.available())
        {
            val = (char)myFile.read();
            resetarCpu.ZerarWdt();
            ether.fillAndSend(val);
        }

        myFile.close();
    }

    Serial.println("fechando envio do arquivo favicon.ico");

    ether.finalizeConn();
}

