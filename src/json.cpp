#include <Headers\json.h>

extern void ParameterFillAndSend(char *val);

JSon json;

void JSon::Cabecalho()
{

    char *page = PSTR("HTTP/1.1 200 OK\r\n"
                      "Access-Control-Allow-Origin: *\r\n"
                      "Content-Type: application/json;charset=utf-8\r\n"
                      "Connection: close\r\n\r\n");

    ether.fillAndSend(page, sizeof(page));
}

void JSon::EnviarStatusEId(char statusLogin)
{

    Cabecalho();
    char bfNumero[15];

    char *page = PSTR("{\"objeto\": \"status\"");
    ether.fillAndSend(page, sizeof page);

    page = PSTR(", \"login\": ");
    ether.fillAndSend(page, sizeof page);
    ether.fillAndSend(statusLogin);

    page = PSTR(", \"id\": ");
    ether.fillAndSend(page, sizeof page);

    sprintf(bfNumero, "%d", Session.GetRandonId());
    ParameterFillAndSend(bfNumero);

    page = PSTR("}\r\n");

    ether.fillAndSend(page, sizeof(page));
    ether.finalizeConn();
}

void JSon::EnviarStatus(char btn, char valor)
{

    Cabecalho();

    char *page = PSTR("{\"objeto\": \"status\"");
    ether.fillAndSend(page, sizeof page);

    page = PSTR(", \"btn\": ");

    ether.fillAndSend(page, sizeof(page));
    ether.fillAndSend(btn);

    page = PSTR(", \"value\": ");

    ether.fillAndSend(page, sizeof(page));
    ether.fillAndSend(valor);

    page = PSTR("}\r\n");

    ether.fillAndSend(page, sizeof(page));
    ether.finalizeConn();
}

void JSon::EnviarStatus()
{
    // codigo para converter float em xx.xx
    /* 4 is mininum width, 2 is precision; float value is copied onto str_temp*/
    // char bf[6];
    // dtostrf(latencia.GetLatencia(i), 4, 2, bf);

    char bfNumero[15];

    Cabecalho();

    char *page = PSTR("{\"objeto\": \"status\"");
    ether.fillAndSend(page, sizeof page);
    page = PSTR(", \"login\": ");
    ether.fillAndSend(page, sizeof page);

    sprintf(bfNumero, "%d", Session.IsLoged());
    ParameterFillAndSend(bfNumero);

    page = PSTR(", \"id\": ");
    ether.fillAndSend(page, sizeof page);

    sprintf(bfNumero, "%d", Session.GetRandonId());
    ParameterFillAndSend(bfNumero);

    page = PSTR(", \"rede\": ");
    ether.fillAndSend(page, sizeof page);

    sprintf(bfNumero, "%d", (bfStatusPing.getRede()+1));
    ParameterFillAndSend(bfNumero);


    for (uint8_t i = 0; i < 4; i++)
    {

        page = PSTR(", \"rstRede");
        ether.fillAndSend(page, sizeof page);

        sprintf(bfNumero, "%d", i + 1);
        ParameterFillAndSend(bfNumero);

        page = PSTR("\": ");
        ether.fillAndSend(page, sizeof(page));

        sprintf(bfNumero, "%d", CtrlResets.GetResets(i));
        ParameterFillAndSend(bfNumero);
    }

    for (uint8_t i = 0; i < 4; i++)
    {

        page = PSTR(", \"statusRede");
        ether.fillAndSend(page, sizeof page);

        sprintf(bfNumero, "%d", i + 1);
        ParameterFillAndSend(bfNumero);

        page = PSTR("\": ");
        ether.fillAndSend(page, sizeof(page));

        sprintf(bfNumero, "%d", controleDasSaidas.RetornarStatusDasSaidas(i));

        ParameterFillAndSend(bfNumero);
    }

    for (uint8_t i = 0; i < 4; i++)
    {

        page = PSTR(", \"perca");
        ether.fillAndSend(page, sizeof page);

        sprintf(bfNumero, "%d", i + 1);
        ParameterFillAndSend(bfNumero);

        page = PSTR("\": ");
        ether.fillAndSend(page, sizeof(page));

        sprintf(bfNumero, "%d", bfStatusPing.getPerca(i));
            
        ParameterFillAndSend(bfNumero);
    }


    for (uint8_t i = 0; i < 4; i++)
    {

        page = PSTR(", \"total");
        ether.fillAndSend(page, sizeof page);

        sprintf(bfNumero, "%d", i + 1);
        ParameterFillAndSend(bfNumero);

        page = PSTR("\": ");
        ether.fillAndSend(page, sizeof(page));

        sprintf(bfNumero, "%d", bfStatusPing.getTotal(i));

        ParameterFillAndSend(bfNumero);
    }

    page = PSTR("}");

    ether.fillAndSend(page, sizeof(page));

    //==========================================
    page = PSTR("\r\n");

    ether.fillAndSend(page, sizeof(page));
    ether.finalizeConn();
}

void JSon::EnviarDadosDoLog()
{
    uint8_t val = 0;
    uint8_t bfdia = 1;
    uint8_t bfhora = 0;
    uint8_t bfmin = 0;
    char bfDados[10];
    char *page;

    Serial.println("--EnviarDadosDoLog()--");

    Cabecalho();

    page = PSTR("{");
    ether.fillAndSend(page, sizeof page);

    for (uint8_t obj = 0; obj < 4; obj++)
    {
        for (uint8_t rede = 0; rede < 4; rede++)
        {
            switch (obj)
            {
            case 0:
                page = PSTR("\"ping");
                break;
            case 1:
                page = PSTR("\"latencia");
                break;
            case 2:
                page = PSTR("\"data");
                break;
            case 3:
                page = PSTR("\"cor");
                break;
            }

            ether.fillAndSend(page, sizeof page);

            sprintf(bfDados, "%d", rede);
            ParameterFillAndSend(bfDados);

            page = PSTR("\": [");
            ether.fillAndSend(page, sizeof page);

       
            for (uint8_t registro = colecao.getMaxRegister(); registro > 0; registro--)
            {

                switch (obj)
                {
                case 0:

                    val = colecao.getPing(rede, registro - 1);
                    sprintf(bfDados, "%d", val);
                    break;
                case 1:
                    val = colecao.getLat(rede, registro - 1);
                    sprintf(bfDados, "%d", val);
                    break;
                case 2:
                //    bfdia = colecao.getDia(rede, registro - 1);
                    bfhora = colecao.getHora(rede, registro - 1);
                    bfmin = colecao.getMin(rede, registro - 1);

                    sprintf(bfDados, "\"%02d:%02d\"", bfhora,bfmin);
                    break;
                case 3:
                    val = colecao.getReset(rede, registro - 1);
                    if (val == 1)
                        sprintf(bfDados, "\"#E30513\"");
                    else
                        sprintf(bfDados, "\"#86B5BC\"");
                    break;
                }

                ParameterFillAndSend(bfDados);

                if (registro - 1 > 0)
                {
                    page = PSTR(",");
                    ether.fillAndSend(page, sizeof(page));
                }
            }

            page = PSTR("]");
            ether.fillAndSend(page, sizeof page);
            
            if (rede < 3 )
            {
                page = PSTR(", ");
                ether.fillAndSend(page, sizeof page);
            }
          
            
        }

           if (obj < 3 )
            {
                page = PSTR(", ");
                 ether.fillAndSend(page, sizeof page);
            }
           
     }

    page = PSTR("}");
    ether.fillAndSend(page, sizeof page);

    ether.finalizeConn();
}