#include <Headers\GerenciadorDeComandosHTTP.h>

uint8_t GerenciadorDeComandosHTTP::ntpMyPort = 123;

GerenciadorDeComandosHTTP HttpManager;

bool GerenciadorDeComandosHTTP::RequisicaoHttpNaoSuportada(char *url)
{
  if (strncmp("GET /", url, 5) != 0)
    return true;
  return false;
}

char *GerenciadorDeComandosHTTP::ApontarParaInicioDosDadosDaUrl(char *url)
{
  return url + 5;
}

bool GerenciadorDeComandosHTTP::UrlGetPagina1Htm(char *url)
{
  if (strncmp("pagina1.htm", url, 11) != 0)
    return false;
  return true;
}
bool GerenciadorDeComandosHTTP::UrlGetPagina2Htm(char *url)
{
  if (strncmp("pagina2.htm", url, 11) != 0)
    return false;
  return true;
}
bool GerenciadorDeComandosHTTP::UrlGetPagina3Htm(char *url)
{
  if (strncmp("pagina3.htm", url, 11) != 0)
    return false;
  return true;
}
bool GerenciadorDeComandosHTTP::UrlGetPagina4Htm(char *url)
{
  if (strncmp("pagina4.htm", url, 11) != 0)
    return false;
  return true;
}
bool GerenciadorDeComandosHTTP::UrlGetPagina5Htm(char *url)
{
  if (strncmp("pagina5.htm", url, 11) != 0)
    return false;
  return true;
}
bool GerenciadorDeComandosHTTP::UrlGetPagina6Htm(char *url)
{
  if (strncmp("pagina6.htm", url, 11) != 0)
    return false;
  return true;
}
bool GerenciadorDeComandosHTTP::UrlGetPagina7Htm(char *url)
{
  if (strncmp("pagina7.htm", url, 11) != 0)
    return false;
  return true;
}

bool GerenciadorDeComandosHTTP::UrlGetPagina8Htm(char *url)
{
  if (strncmp("pagina8.htm", url, 11) != 0)
    return false;
  return true;
}
bool GerenciadorDeComandosHTTP::UrlGetPagina9Htm(char *url)
{
  if (strncmp("pagina9.htm", url, 11) != 0)
    return false;
  return true;
}

bool GerenciadorDeComandosHTTP::UrlGetStatus(char *url)
{
  if (strncmp("GetStatus", url, 9) != 0)
    return false;
  return true;
}
bool GerenciadorDeComandosHTTP::UrlGetDateTime(char *url)
{
  if (strncmp("GetDateTime", url, 11) != 0)
    return false;
  return true;
}
bool GerenciadorDeComandosHTTP::UrlGetMenuCss(char *url)
{
  if (strncmp("menu.css", url, 8) != 0)
    return false;
  return true;
}

bool GerenciadorDeComandosHTTP::Urlrgcajax(char *url)
{
  if (strncmp("rgcajax.js", url, 10) != 0)
    return false;
  return true;
}

bool GerenciadorDeComandosHTTP::Urlrgccore(char *url)
{
  if (strncmp("rgccore.js", url, 10) != 0)
    return false;
  return true;
}

bool GerenciadorDeComandosHTTP::Urlrgline(char *url)
{
  if (strncmp("rgline.js", url, 9) != 0)
    return false;
  return true;
}

bool GerenciadorDeComandosHTTP::Urlrgckey(char *url)
{
  if (strncmp("rgckey.js", url, 9) != 0)
    return false;
  return true;
}

bool GerenciadorDeComandosHTTP::UrlGetFavIcon(char *url)
{
  if (strncmp("favicon.ico", url, 11) != 0)
    return false;
  return true;
}

bool GerenciadorDeComandosHTTP::UrlGetCodeJs(char *url)
{
  if (strncmp("code.js", url, 7) != 0)
    return false;
  return true;
}

bool GerenciadorDeComandosHTTP::UrlGetJQueryJs(char *url)
{
  if (strncmp("jquery.js", url, 13) != 0)
    return false;
  return true;
}
bool GerenciadorDeComandosHTTP::UrlGetDadosParaGrafico(char *url)
{
  if (strncmp("gdgraph1.js", url, 11) != 0)
    return false;
  return true;
}
bool GerenciadorDeComandosHTTP::UrlRgBar(char *url)
{
  if (strncmp("rgbar.js", url, 11) != 0)
    return false;
  return true;
}

bool GerenciadorDeComandosHTTP::UrlGetReset(char *url)
{
  if (strncmp("ResetTblStatus", url, 14) != 0)
    return false;
  return true;
}

bool GerenciadorDeComandosHTTP::UrlBtnClearLog(char *url)
{
  if (strncmp("btnClearLog", url, 11) != 0)
    return false;
  return true;
}

bool GerenciadorDeComandosHTTP::UrlSolicitaPaginaDeLogin(char *url)
{
  if (url[0] == '\0')
    return true;
  return false;
}
bool GerenciadorDeComandosHTTP::UrlSolicitaHomePage(char *url)
{
  if (strncmp("HomePage", url, 8) != 0)
    return false;
  return true;
}

bool GerenciadorDeComandosHTTP::UrlSalvarWatchDog(char *url)
{
  if (strncmp("WatchDog", url, 8) != 0)
    return false;
  return true;
}

bool GerenciadorDeComandosHTTP::UrlSalvarConfiguracoes(char *url)
{
  if (strncmp("Configuracao", url, 12) != 0)
    return false;
  return true;
}

bool GerenciadorDeComandosHTTP::UrlSalvarConfiguracoesDeRede(char *url)
{
  if (strncmp("ConfigRede", url, 10) != 0)
    return false;
  return true;
}

bool GerenciadorDeComandosHTTP::UrlSalvarConfiguracoesDoPing(char *url)
{
  if (strncmp("ConfigPing", url, 10) != 0)
    return false;
  return true;
}

bool GerenciadorDeComandosHTTP::UrlSalvarControleDasSaidas(char *url)
{
  if (strncmp("BtnControl", url, 10) != 0)
    return false;
  return true;
}

bool GerenciadorDeComandosHTTP::UrlValidarId(char *id)
{

  char bfId[10];
  sprintf(bfId, "%d", Session.GetRandonId());

  if (strncmp(bfId, id, sizeof bfId) == 0)
  {
    return true;
  }

  return false;
}

bool GerenciadorDeComandosHTTP::UrlValidarLogin(char *url)
{
  if (strncmp("ValidarLogin", url, 12) != 0)
    return false;
  return true;
}

bool GerenciadorDeComandosHTTP::UrlSalvarLogin(char *url)
{
  if (strncmp("Login", url, 5) != 0)
    return false;
  return true;
}

bool GerenciadorDeComandosHTTP::UrlSalvarRelogio(char *url)
{
  if (strncmp("ConfigDataHora", url, 14) != 0)
    return false;
  return true;
}

void GerenciadorDeComandosHTTP::RetirarTodosOsParametrosDaMensagem(char *url)
{
  char *getFimDaMensagem = strstr(url, " HTTP");
  *getFimDaMensagem = '\0';
}

char *GerenciadorDeComandosHTTP::SepararTodosOsParametros(char *url)
{
  return strtok(url, "&");
}

char *GerenciadorDeComandosHTTP::FiltrarId(char *url)
{
  return 0;
}

formWatchdog GerenciadorDeComandosHTTP::FiltrarParametrosFrmWatchDog(char *url)
{

  char *command = SepararTodosOsParametros(url);

  formWatchdog frmWatchDog;

  frmWatchDog._flagAtivarWD[0] = 0;
  frmWatchDog._flagAtivarWD[1] = 0;
  frmWatchDog._flagAtivarWD[2] = 0;
  frmWatchDog._flagAtivarWD[3] = 0;

  while (command != 0)
  {

    // Split the command in two values
    char *separator = strchr(command, '=');
    if (separator != 0)
    {
      // Actually split the string in 2: replace ':' with 0
      *separator = 0;
      ++separator;

      if (strncmp("QuantidadeResets", command, 16) == 0)
      {
        frmWatchDog.maximaQuantidadeDeResets = (uint8_t)FuncoesUteis::ConvertCharArrayToByte(separator);
      }
      if (strncmp("TempoAcionamento", command, 16) == 0)
      {
        frmWatchDog.tempoDeAcionamento = (uint8_t)FuncoesUteis::ConvertCharArrayToByte(separator);
      }
      if (strncmp("TempoVarredura", command, 14) == 0)
      {
        frmWatchDog.tempoDeVarredura = (uint8_t)FuncoesUteis::ConvertCharArrayToByte(separator);
      }
      if (strncmp("chkBTN1", command, 7) == 0)
      {
        frmWatchDog._flagAtivarWD[0] = 1;
      }
      if (strncmp("chkBTN2", command, 7) == 0)
      {
        frmWatchDog._flagAtivarWD[1] = 1;
      }
      if (strncmp("chkBTN3", command, 7) == 0)
      {
        frmWatchDog._flagAtivarWD[2] = 1;
      }
      if (strncmp("chkBTN4", command, 7) == 0)
      {
        frmWatchDog._flagAtivarWD[3] = 1;
      }
    }
    // Find the next command in input string
    command = strtok(0, "&");
  }
  return frmWatchDog;
}

formConfiguracao GerenciadorDeComandosHTTP::FiltrarParametrosFrmConfiguracoes(char *url)
{

  char *command = SepararTodosOsParametros(url);

  formConfiguracao frmConfiguracao;

  while (command != 0)
  {

    // Split the command in two values
    char *separator = strchr(command, '=');
    if (separator != 0)
    {

      // Actually split the string in 2: replace ':' with 0
      *separator = 0;
      ++separator;

      ether.urlDecode(separator);

      if (strncmp("NomeInterface", command, 13) == 0)
      {
        FuncoesUteis::copiarArray(separator, frmConfiguracao.nomeInterface, strlen(separator), 40);
      }
      if (strncmp("NomeRede1", command, 9) == 0)
      {
        FuncoesUteis::copiarArray(separator, frmConfiguracao.nomeRede[0], strlen(separator), 40);
      }
      if (strncmp("NomeRede2", command, 9) == 0)
      {
        FuncoesUteis::copiarArray(separator, frmConfiguracao.nomeRede[1], strlen(separator), 40);
      }
      if (strncmp("NomeRede3", command, 9) == 0)
      {
        FuncoesUteis::copiarArray(separator, frmConfiguracao.nomeRede[2], strlen(separator), 40);
      }
      if (strncmp("NomeRede4", command, 9) == 0)
      {
        FuncoesUteis::copiarArray(separator, frmConfiguracao.nomeRede[3], strlen(separator), 40);
      }
      if (strncmp("IpRede1", command, 7) == 0)
      {
        FuncoesUteis::CopiarIpParaByteArray(separator, '.', frmConfiguracao.ipRede[0], 4, 10);
      }
      if (strncmp("IpRede2", command, 7) == 0)
      {
        FuncoesUteis::CopiarIpParaByteArray(separator, '.', frmConfiguracao.ipRede[1], 4, 10);
      }
      if (strncmp("IpRede3", command, 7) == 0)
      {
        FuncoesUteis::CopiarIpParaByteArray(separator, '.', frmConfiguracao.ipRede[2], 4, 10);
      }
      if (strncmp("IpRede4", command, 7) == 0)
      {
        FuncoesUteis::CopiarIpParaByteArray(separator, '.', frmConfiguracao.ipRede[3], 4, 10);
      }
    }
    // Find the next command in input string
    command = strtok(0, "&");
  }

  return frmConfiguracao;
}

formConfiguracaoDaRede GerenciadorDeComandosHTTP::FiltrarParametrosFrmConfiguracoesDeRede(char *url)
{

  char *command = SepararTodosOsParametros(url);

  formConfiguracaoDaRede frmConfiguracaoDeRede;

  while (command != 0)
  {

    // Split the command in two values
    char *separator = strchr(command, '=');
    if (separator != 0)
    {

      // Actually split the string in 2: replace ':' with 0
      *separator = 0;
      ++separator;

      ether.urlDecode(separator);

      if (strncmp("Ip", command, 2) == 0)
      {
        FuncoesUteis::CopiarIpParaByteArray(separator, '.', frmConfiguracaoDeRede.ipAdrress, 4, 10);
      }
      if (strncmp("DNS", command, 3) == 0)
      {
        FuncoesUteis::CopiarIpParaByteArray(separator, '.', frmConfiguracaoDeRede.dnsAdrress, 4, 10);
      }
      if (strncmp("GatWay", command, 6) == 0)
      {
        FuncoesUteis::CopiarIpParaByteArray(separator, '.', frmConfiguracaoDeRede.gwIpAdrress, 4, 10);
      }
      if (strncmp("SubMasc", command, 7) == 0)
      {
        FuncoesUteis::CopiarIpParaByteArray(separator, '.', frmConfiguracaoDeRede.subMascara, 4, 10);
      }
      if (strncmp("MAC", command, 3) == 0)
      {
        FuncoesUteis::CopiarIpParaByteArray(separator, ':', frmConfiguracaoDeRede.macAdrress, 6, 16);
      }
    }
    // Find the next command in input string
    command = strtok(0, "&");
  }

  return frmConfiguracaoDeRede;
}

formConfiguracaoDoPing GerenciadorDeComandosHTTP::FiltrarParametrosFrmConfiguracoesDoPing(char *url)
{

  char *command = SepararTodosOsParametros(url);

  formConfiguracaoDoPing frmConfiguracaoDoPing;

  while (command != 0)
  {

    // Split the command in two values
    char *separator = strchr(command, '=');
    if (separator != 0)
    {

      // Actually split the string in 2: replace ':' with 0
      *separator = 0;
      ++separator;

      ether.urlDecode(separator);

      if (strncmp("txtNumBytesPing", command, 15) == 0)
      {
        frmConfiguracaoDoPing.numeroDeBytesDoPing = FuncoesUteis::ConvertCharArrayToByte(separator);
        char bfNumeroDeBytes[10];
      }
      if (strncmp("txtQuantDePings", command, 15) == 0)
      {
        frmConfiguracaoDoPing.QuantidadeDePingParaEnvio = FuncoesUteis::ConvertCharArrayToByte(separator);
      }
      if (strncmp("txtTriggerPercaDePacotes", command, 24) == 0)
      {
        frmConfiguracaoDoPing.NumeroDePercaDePacotes = FuncoesUteis::ConvertCharArrayToByte(separator);
      }
      if (strncmp("txtTimeOut", command, 10) == 0)
      {
        frmConfiguracaoDoPing.TimeOut = FuncoesUteis::ConvertCharArrayToByte(separator);
      }
    }
    // Find the next command in input string
    command = strtok(0, "&");
  }

  return frmConfiguracaoDoPing;
}

BtnControl GerenciadorDeComandosHTTP::FiltrarParametrosFrmControleDasSaidas(char *url)
{

  char *command = SepararTodosOsParametros(url);

  BtnControl btnControl;

  while (command != 0)
  {

    // Split the command in two values
    char *separator = strchr(command, '=');
    if (separator != 0)
    {
      // Actually split the string in 2: replace ':' with 0
      *separator = 0;
      ++separator;

      if (strncmp("btn", command, 3) == 0)
      {
        btnControl.btn = *separator;
      }
      if (strncmp("optrd", command, 3) == 0)
      {
        btnControl.tempo = FuncoesUteis::ConvertCharArrayToByte(separator);
      }
    }
    // Find the next command in input string
    command = strtok(0, "&");
  }

  return btnControl;
}

formLogin GerenciadorDeComandosHTTP::FiltrarParametrosFrmLogin(char *url)
{

  char *command = SepararTodosOsParametros(url);

  formLogin frmLogin;

  while (command != 0)
  {

    // Split the command in two values
    char *separator = strchr(command, '=');
    if (separator != 0)
    {
      // Actually split the string in 2: replace ':' with 0
      *separator = 0;
      ++separator;

      ether.urlDecode(separator);

      if (strncmp("User", command, 4) == 0)
      {
        FuncoesUteis::copiarArray(separator, frmLogin.Usuario, strlen(separator), 20);
      }
      if (strncmp("pwd", command, 3) == 0)
      {
        FuncoesUteis::copiarArray(separator, frmLogin.Senha, strlen(separator), 20);
      }
    }
    // Find the next command in input string
    command = strtok(0, "&");
  }

  return frmLogin;
}

formRelogio GerenciadorDeComandosHTTP::FiltrarParametrosFrmDateTime(char *url)
{

  char *command = SepararTodosOsParametros(url);

  formRelogio frmRelogio;

  while (command != 0)
  {

    // Split the command in two values
    char *separator = strchr(command, '=');
    if (separator != 0)
    {
      // Actually split the string in 2: replace ':' with 0
      *separator = 0;
      ++separator;

      ether.urlDecode(separator);

      if (strncmp("DataHora", command, 8) == 0)
      {
        Serial.print("DateTime: ");
        Serial.println(separator);

        char *date = separator;
        char *time = strchr(separator, 'T');
        if (time != 0)
        {
          // Actually split the string in 2: replace ':' with 0
          *time = 0;
          ++time;
        }

        char *year = date;
        char *month = strchr(date, '-');
        *month = 0;
        ++month;
        char *day = strchr(month,'-');
        *day = 0;
        ++day;

        char *hour = time;
        char *min = strchr(hour, ':');
        *min = 0;
        ++min;
        
        
       frmRelogio.dateTime.date.day = FuncoesUteis::ConvertCharArrayToByte(day);
       frmRelogio.dateTime.date.mouth = FuncoesUteis::ConvertCharArrayToByte(month); 
       frmRelogio.dateTime.date.year = FuncoesUteis::ConvertCharArrayToByte(year);
       frmRelogio.dateTime.time.hour = FuncoesUteis::ConvertCharArrayToByte(hour);
       frmRelogio.dateTime.time.min = FuncoesUteis::ConvertCharArrayToByte(min);
       frmRelogio.dateTime.time.sec = 0;//FuncoesUteis::ConvertCharArrayToByte(hour);
                
      }

      if (strncmp("NTP", command, 3) == 0)
      {
        FuncoesUteis::CopiarIpParaByteArray(separator, '.', frmRelogio.ntp.ntpAdrress, 4, 10);
      }
    }
    // Find the next command in input string
    command = strtok(0, "&");
  }

  return frmRelogio;
}

char *GerenciadorDeComandosHTTP::UrlRetornarId(char *url)
{
  char *getInit = strstr(url, "=");
  if (getInit != 0)
  {
    ++getInit;
    return getInit;
  }

  return 0;
}

char *GerenciadorDeComandosHTTP::PularCampoSession(char *url)
{
  char *getFim = strchr(url, '&');
  if (getFim != 0)
  {
    *getFim = 0;
    return ++getFim;
  }

  return url;
}

void GerenciadorDeComandosHTTP::SendNtpRequest()
{

  formNtp frmNtp = MemoriaEEPROM.CarregarFormNtp();
  ether.ntpRequest(frmNtp.ntpAdrress, ntpMyPort);
}

void GerenciadorDeComandosHTTP::GerenciarComandosHTTP()
{

  // wait for an incoming TCP packet, but ignore its contents

  word len = ether.packetReceive();
  word dadosRecebidos = ether.packetLoop(len);

  if (dadosRecebidos)
  {

    delay(1); // necessary for my system

    ether.setBufferPtr(dadosRecebidos);

    char *url = (char *)Ethernet::buffer + dadosRecebidos;

    if (RequisicaoHttpNaoSuportada(url))
    {
      //  Serial.println("pagina 304 found location");
      // paginaHtml.CarregarPaginaEncontrada();
      return;
    }

    url = ApontarParaInicioDosDadosDaUrl(url);

    RetirarTodosOsParametrosDaMensagem(url);

    //Serial.println("url:");
    //Serial.println(url);
    //Serial.println();

    if (UrlGetMenuCss(url))
    {
      paginaHtml.EnviarCssFile("menu.css");
      return;
    }

    if (UrlGetFavIcon(url))
    {
      paginaHtml.EnviarIcoFile("favicon.ico");
      return;
    }

    if (UrlGetCodeJs(url))
    {
      paginaHtml.EnviarJsFile("code.js");
      return;
    }

    if (Urlrgckey(url))
    {
      paginaHtml.EnviarJsFile("rgckey.js");
      return;
    }
    if (Urlrgline(url))
    {
      paginaHtml.EnviarJsFile("rgsline.js");
      return;
    }
    if (Urlrgccore(url))
    {
      paginaHtml.EnviarJsFile("rgsccore.js");
      return;
    }
    if (Urlrgcajax(url))
    {
      paginaHtml.EnviarJsFile("rgcajax.js");
      return;
    }
    if (UrlRgBar(url))
    {
      paginaHtml.EnviarJsFile("rgsbar.js");
      return;
    }

    if (UrlGetJQueryJs(url))
    {
      paginaHtml.EnviarJsFile("jquery.js");
      return;
    }

    if (UrlGetDadosParaGrafico(url))
    {
      json.EnviarDadosDoLog();
      return;
    }

    if (UrlSolicitaPaginaDeLogin(url))
    {
      // Serial.println("- pagina login -");
      paginaHtml.CarregarPaginaDeLogin();
      return;
    }

    char *ptrId = UrlRetornarId(url);

    if (ptrId != 0)
    {
      url = PularCampoSession(url);
    }

    if (UrlValidarLogin(url))
    {
      // Serial.println("- validar login -");

      formLogin frmLogin = FiltrarParametrosFrmLogin(url);
      if (Session.LogIn(frmLogin))
      {
        json.EnviarStatusEId('1');
        return;
      }
    }

    if (!UrlValidarId(ptrId) || !Session.IsLoged())
    {
      // Serial.println("ptrId invalido");
      json.EnviarStatusEId('0');
      return;
    }

    if (UrlGetStatus(url))
    {
      json.EnviarStatus();
      return;
    }

    if (UrlBtnClearLog(url))
    {
      logDeFalhas.LimparLog();
      json.EnviarStatus('0', '1');
      return;
    }

    if (UrlGetPagina1Htm(url))
    {
      paginaHtml.CarregarPagina1();
      return;
    }
    if (UrlGetPagina2Htm(url))
    {
      paginaHtml.CarregarPagina2();
      return;
    }
    if (UrlGetPagina3Htm(url))
    {
      paginaHtml.CarregarPagina3();
      return;
    }
    if (UrlGetPagina4Htm(url))
    {
      paginaHtml.CarregarPagina4();
      return;
    }
    if (UrlGetPagina5Htm(url))
    {
      paginaHtml.CarregarPagina5();
      return;
    }
    if (UrlGetPagina6Htm(url))
    {
      paginaHtml.CarregarPagina6();

      return;
    }

    if (UrlGetPagina7Htm(url))
    {
      paginaHtml.CarregarPagina7();
      return;
    }

    if (UrlGetPagina8Htm(url))
    {
      paginaHtml.CarregarPagina8();
      return;
    }

    if (UrlGetPagina9Htm(url))
    {
      paginaHtml.CarregarPagina9();
      return;
    }
    
    if (UrlGetDateTime(url))
    {
      json.EnviarDateTime();
      return;
    }
    
    if (UrlSolicitaHomePage(url))
    {
      // Serial.println("- home page -");

      paginaHtml.CarregarHomePage();
    }

    if (UrlSalvarWatchDog(url))
    {

      formWatchdog frmWatchDog = FiltrarParametrosFrmWatchDog(url);

      MemoriaEEPROM.SalvarformWatchdog(frmWatchDog);
      json.EnviarStatus('0', '1');
    }

    if (UrlSalvarConfiguracoes(url))
    {

      formConfiguracao frmConfiguracao = FiltrarParametrosFrmConfiguracoes(url);
      MemoriaEEPROM.SalvarformConfiguracao(frmConfiguracao);
      json.EnviarStatus('0', '1');
    }

    if (UrlSalvarConfiguracoesDeRede(url))
    {

      formConfiguracaoDaRede frmConfiguracaoDeRede = FiltrarParametrosFrmConfiguracoesDeRede(url);
      MemoriaEEPROM.SalvarformConfiguracaoDaRede(frmConfiguracaoDeRede);
      json.EnviarStatus('0', '1');
      resetarCpu.ResetCpu(true);
    }

    if (UrlSalvarConfiguracoesDoPing(url))
    {

      formConfiguracaoDoPing frmConfiguracaoDoPing = FiltrarParametrosFrmConfiguracoesDoPing(url);

      MemoriaEEPROM.SalvarformConfiguracaoDoPing(frmConfiguracaoDoPing);
      json.EnviarStatus('0', '1');
    }

    if (UrlSalvarControleDasSaidas(url))
    {
      // Serial.print("controle das saidas");
      BtnControl btnControl;

      btnControl = FiltrarParametrosFrmControleDasSaidas(url);

      controleDasSaidas.Desativar(btnControl.btn - 49, btnControl.tempo);
    }

    if (UrlSalvarLogin(url))
    {

      formLogin frmLogin = FiltrarParametrosFrmLogin(url);
      MemoriaEEPROM.SalvarformLogin(frmLogin);

      json.EnviarStatus('0', '1');
    }

    if (UrlSalvarRelogio(url))
    {

      formRelogio frmRelogio = FiltrarParametrosFrmDateTime(url);
      MemoriaEEPROM.SalvarformNtp(frmRelogio.ntp);

      RelogioRTC r(20,21);  

      r.setDate(frmRelogio.dateTime.date.day,frmRelogio.dateTime.date.mouth,frmRelogio.dateTime.date.year);
      r.setTime(frmRelogio.dateTime.time.hour,frmRelogio.dateTime.time.min,frmRelogio.dateTime.time.sec);

      json.EnviarStatus('0', '1');
    }

    if (UrlGetReset(url))
    {
      //     Serial.print("Reset");
      CtrlResets.Zerar();
    }

    return;
  }

  if (len)
  {

    static long timeZoneOffset = 10800; //gmt-3 -> 3600*3
    static unsigned long timeFromNTP;
    static const unsigned long seventy_years = 2208988800UL;

    if (ether.ntpProcessAnswer(&timeFromNTP, ntpMyPort))
    {
      relogio.SincNtpTime(timeFromNTP - seventy_years - timeZoneOffset);
    }
  }
}
