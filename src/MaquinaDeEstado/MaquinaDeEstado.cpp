#include <Headers\MaquinaDeEstado.h>

MaquinaDeEstado maquinaDeEstado;

MaquinaDeEstado::MaquinaDeEstado()
{
    Init_MaquinaDeEstado();
}
void MaquinaDeEstado::AtualizarBufferStatusPing()
{
    bfStatusPing.update(MDE.redeMonitorada[MDE.idDaRedeEmAnalise].numeroDeTimeOut, MDE.numeroDePingsEnviados, MDE.idDaRedeEmAnalise);
}

bool MaquinaDeEstado::ResetarModuloEthernet()
{

    uint8_t offSet = 2;
    bool resetar = false;


    if (MDE.PercaDePacotesSequencial >= MDE.PercaDePacotesMaxima * MDE.quantidadeDeRedesMonitoradas * offSet)
    {
        MDE.PercaDePacotesSequencial = 0;
        resetar = true;
    }
    else if(MDE.RegistroDeLatenciaAlta > 50){
        MDE.RegistroDeLatenciaAlta = 0;
        resetar = true;
    }

    if(resetar == true){
        //conexao.InicializarEnc28j60();
        resetarCpu.ResetCpu(true);
        return true;
    }

    return false;
}

void MaquinaDeEstado::AtualizarRelogioDeTimeOut()
{
    bfTempoDeTimeOut = micros();
}

bool MaquinaDeEstado::TempoDeTimeOutEstourou()
{

    if (micros() - bfTempoDeTimeOut >= MDE.tempoTimeOut * 1000000)
    {
        return true;
    }
    return false;
}

void MaquinaDeEstado::AtualizarRelogioTempoDeUmSegundo()
{
    bfTempo1seg = millis();
}

bool MaquinaDeEstado::TempoDeUmSegundoOk()
{

    if (millis() - bfTempo1seg >= 2000)
    {
        return true;
    }
    return false;
}

void MaquinaDeEstado::AtualizarRelogioDeVarredura()
{
    bfTempoDeVarredura = millis();
}

bool MaquinaDeEstado::TempoDeVarreduraOk()
{
    if (millis() - bfTempoDeVarredura >= (MDE.tempoDeVarredura * 1000))
    {
        return true;
    }
    return false;
}

bool MaquinaDeEstado::VerificarSeRedeAtingiuLimiteDeResets(uint8_t id)
{
    if (CtrlResets.GetResets(id) >= MDE.maxResets)
    {
        return true;
    }

    return false;
}

void MaquinaDeEstado::DesativarRedeTemporariamente()
{
    controleDasSaidas.Desativar(MDE.idDaRedeEmAnalise, MDE.tempoDeAcionamento);
}
void MaquinaDeEstado::IncrementarContagemDePingsPerdidos()
{
    MDE.redeMonitorada[MDE.idDaRedeEmAnalise].numeroDeTimeOut++;
}
void MaquinaDeEstado::ResetarVariaveisDaRedeEmAnalise()
{
    MDE.redeMonitorada[MDE.idDaRedeEmAnalise].numeroDeTimeOut = 0;
    MDE.numeroDePingsEnviados = 0;
    MDE.redeMonitorada[MDE.idDaRedeEmAnalise].latencia = 0;
    
    latencia.Zerar(MDE.idDaRedeEmAnalise);


}

void MaquinaDeEstado::IncrementarContagemDeRedeResetada()
{
    // MDE.redeMonitorada[MDE.idDaRedeEmAnalise].numeroDeResets++;
    CtrlResets.Incrementar(MDE.idDaRedeEmAnalise);
}

uint8_t MaquinaDeEstado::QuantidadeDeRedesMonitoradas()
{
    return MDE.quantidadeDeRedesMonitoradas;
}

bool MaquinaDeEstado::ExisteRedeDisponivelParaPingar()
{

    for (uint8_t i = 0; i < MDE.quantidadeDeRedesMonitoradas; i++)
    {
        if (!VerificarSeRedeAtingiuLimiteDeResets(i))
            return true;
    }
    return false;
}

void MaquinaDeEstado::PingarRedeMonitorada()
{
    ether.clientIcmpRequest(ether.hisip, (MDE.numeroDeBytesDoPing - 28));
}

void MaquinaDeEstado::SolicitarEnderecoMacDoDispositivoRemoto(char *ip)
{
    ether.MakeNewIpConection(ip);
}

void MaquinaDeEstado::ResetarVariaveisDeTodasRedesMonitoras()
{
}

void MaquinaDeEstado::ResetarVariaveisDaMaquinaDeEStado()
{
    MDE.numeroDePingsEnviados = 0;
}

bool MaquinaDeEstado::PularParaProximaRedeMonitorada()
{
    bool resultado = false;

    int redeAtual = 0;

    for ( redeAtual = MDE.proximaRedeMonitorada; redeAtual < MDE.quantidadeDeRedesMonitoradas; redeAtual++)
    {
        if (!VerificarSeRedeAtingiuLimiteDeResets(MDE.redeMonitorada[redeAtual].id))
        {

            ResetarVariaveisDaMaquinaDeEStado();
            SolicitarEnderecoMacDoDispositivoRemoto(MDE.redeMonitorada[redeAtual].ip);

            MDE.idDaRedeEmAnalise = MDE.redeMonitorada[redeAtual].id;
            resultado = true;
            break;
        }
    }
     
    MDE.proximaRedeMonitorada = redeAtual + 1;

    if (MDE.proximaRedeMonitorada >= MDE.quantidadeDeRedesMonitoradas)
        MDE.proximaRedeMonitorada = 0;

    return resultado;
}

void MaquinaDeEstado::LimparIpsResiduais()
{
    for (uint8_t i = 0; i < 4; i++)
    {
        for (uint8_t j = 0; j < 4; j++)
            MDE.redeMonitorada[i].ip[j] = 0;
    }
}

void MaquinaDeEstado::CriarObjetosDeMonitoramento()
{
    uint8_t quant = 0;

    formWatchdog frmWatchDog = MemoriaEEPROM.CarregarFormWatchDog();
    formConfiguracao frmConfig = MemoriaEEPROM.CarregarFormConfiguracao();
    MDE.quantidadeDeRedesMonitoradas = 0;
    
    for (uint8_t i = 0; i < 4; i++)
    {

        if (frmWatchDog._flagAtivarWD[i] != 0x00)
        {
            FuncoesUteis::copiarIp(frmConfig.ipRede[i], MDE.redeMonitorada[quant].ip, 4);
            MDE.redeMonitorada[quant].id = i;
            MDE.quantidadeDeRedesMonitoradas = ++quant;
        }
    }
}

void MaquinaDeEstado::InicializarVariaveisDaMaquinaDeEstado()
{
    formConfiguracaoDoPing frmConfigPing = MemoriaEEPROM.CarregarFormConfiguracaoDoPing();
    formWatchdog frmWatchDog = MemoriaEEPROM.CarregarFormWatchDog();
    MDE.tempoDeVarredura = frmWatchDog.tempoDeVarredura;
    MDE.tempoDeAcionamento = frmWatchDog.tempoDeAcionamento;
    MDE.tempoTimeOut = frmConfigPing.TimeOut;
    MDE.numeroDeBytesDoPing = frmConfigPing.numeroDeBytesDoPing;
    MDE.PercaDePacotesMaxima = frmConfigPing.NumeroDePercaDePacotes;
    MDE.PercaDePacotesSequencial = 0;
    MDE.RegistroDeLatenciaAlta = 0;
    MDE.QuantidadeDePings = frmConfigPing.QuantidadeDePingParaEnvio;
    MDE.maxResets = frmWatchDog.maximaQuantidadeDeResets;
    MDE.proximaRedeMonitorada = 0;

    ResetarVariaveisDaMaquinaDeEStado();
}

void MaquinaDeEstado::Init_MaquinaDeEstado()
{
    InicializarVariaveisDaMaquinaDeEstado();
    CriarObjetosDeMonitoramento();
}

bool MaquinaDeEstado::VerificarSeBancoDeDAdosFoiAlterado()
{

    if (MemoriaEEPROM.VerificarStatusDoBancoDeDados())
    {
        MemoriaEEPROM.ModificarFlagDeAlteracaoNoBancoDeDados(false);
        return true;
    }

    return false;
}

bool MaquinaDeEstado::ValidarMaquinaDeEstado()
{

    if (VerificarSeBancoDeDAdosFoiAlterado())
    {
        Init_MaquinaDeEstado();
    }

    if (QuantidadeDeRedesMonitoradas() > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool MaquinaDeEstado::TerminouDeEnviarOsPings()
{
    if (MDE.numeroDePingsEnviados >= MDE.QuantidadeDePings)
        return true;
    return false;
}

bool MaquinaDeEstado::RespostaDoPingChegou()
{
    bool result = false;
    result = ether.packetLoopIcmpCheckReply(ether.hisip);
    return result;
}

bool MaquinaDeEstado::VerificarSePrecisaResetarRede()
{
    if ((MDE.redeMonitorada[MDE.idDaRedeEmAnalise].numeroDeTimeOut) >= MDE.PercaDePacotesMaxima)
    {
        return true;
    }
    else
        return false;
}

void MaquinaDeEstado::IncrementarContagemDePingsEnviados()
{
    MDE.numeroDePingsEnviados++;
}

void MaquinaDeEstado::AtualizarColecaoDeDados(uint8_t sinalizarRedeResetada)
{
    DataLog datalog;
    Relogio relogio;

    datalog.dateTime.hora = relogio.getHour();
    datalog.dateTime.min = relogio.getMin();
    datalog.dateTime.dia = relogio.getDay();
    datalog.ping = MDE.redeMonitorada[MDE.idDaRedeEmAnalise].numeroDeTimeOut;
    datalog.lat = latencia.CalcularMedia(MDE.idDaRedeEmAnalise);
    datalog.reset = (bool)sinalizarRedeResetada;

    colecao.add(MDE.idDaRedeEmAnalise, datalog);
}

void MaquinaDeEstado::AtualizarMaquinaDeEstado()
{
    static uint8_t maxTentativaParaReceberMac = 0;

    static uint8_t incrementadorDePosicao = _VAI_PARA_PROXIMA_REDE;

    controleDasSaidas.AtualizarRelogio();

    if (!ValidarMaquinaDeEstado())
        return;

    switch (incrementadorDePosicao)
    {

    case _CONFIGURACAO_INICIAL:

        if(!ExisteRedeDisponivelParaPingar())
        return;

       incrementadorDePosicao = _VAI_PARA_PROXIMA_REDE;
    break;
    case _START:
                 MDE.RegistroDeLatenciaAlta = 0;
                 maxTentativaParaReceberMac = 0;
                 ResetarVariaveisDaRedeEmAnalise();
               //  bfStatusPing.reset(MDE.idDaRedeEmAnalise);

        AtualizarRelogioTempoDeUmSegundo();
        incrementadorDePosicao = _AGUARDAR_1S;

    break;    

    case _PINGAR_REDE_MONITORADA: // step 1


        //Serial.print("ip: ");
        //ether.printIp(ether.hisip);
        //Serial.println();
       // Serial.print("mac: ");
       // ether.printMac(ether.destmacaddr);
       // Serial.println();
        
        if (TerminouDeEnviarOsPings())
        {
            AtualizarColecaoDeDados(0);

            incrementadorDePosicao = _VAI_PARA_PROXIMA_REDE;
        }
        else
        {

            if (controleDasSaidas.RetornarStatusDasSaidas(MDE.idDaRedeEmAnalise) == false)
            {
                incrementadorDePosicao = _VAI_PARA_PROXIMA_REDE;
                return;
            }
            
            //if(ether.HasValidRemoteMac()){PingarRedeMonitorada();}
            //else{SolicitarEnderecoMacDoDispositivoRemoto(ether.hisip);}
            
            PingarRedeMonitorada();
            
            IncrementarContagemDePingsEnviados();
            AtualizarRelogioDeTimeOut();
     
            incrementadorDePosicao = _AGUARDAR_RESPOSTA_DO_PING;
        }

        break;
    case _AGUARDAR_RESPOSTA_DO_PING: // step 2
       

        if (RespostaDoPingChegou())
        {

      
            uint16_t lat = (uint16_t)((micros() - bfTempoDeTimeOut) * 0.001);

           
            if(lat > 50) MDE.RegistroDeLatenciaAlta++;

            ResetarModuloEthernet();


            MDE.PercaDePacotesSequencial = 0;

            latencia.add(MDE.idDaRedeEmAnalise, lat);

            // Serial.print(" lat: ");
            // Serial.println(lat);

            AtualizarBufferStatusPing();

            AtualizarRelogioTempoDeUmSegundo();
            incrementadorDePosicao = _AGUARDAR_1S;
        }
        else if (TempoDeTimeOutEstourou())
        {

           // Serial.println("TimeOut");

            MDE.PercaDePacotesSequencial++;

            ResetarModuloEthernet();
        
            IncrementarContagemDePingsPerdidos();
            AtualizarBufferStatusPing();

           

            if (VerificarSePrecisaResetarRede())
            {
                incrementadorDePosicao = _RESETAR_REDE;
            }
            else
            {                    
                    
                AtualizarRelogioTempoDeUmSegundo();
                incrementadorDePosicao = _AGUARDAR_1S;
            }
        }

        break;
    case _AGUARDAR_1S:

        if (TempoDeUmSegundoOk())
        {
            incrementadorDePosicao = _PINGAR_REDE_MONITORADA;
        }
        break;
    case _RESETAR_REDE: // step 3
        IncrementarContagemDeRedeResetada();
        AtualizarColecaoDeDados(1);
        DesativarRedeTemporariamente();
        logDeFalhas.CriarLog(MDE.idDaRedeEmAnalise + 1);
        incrementadorDePosicao = _VAI_PARA_PROXIMA_REDE;

        break;
    case _VAI_PARA_PROXIMA_REDE: // step 6

        if (PularParaProximaRedeMonitorada())
        {            
             if (MDE.idDaRedeEmAnalise == 0)
            {
                AtualizarRelogioDeVarredura();
                incrementadorDePosicao = _VERIFICAR_TEMPO_DE_VARREDURA;
            }
            else
            {              
                incrementadorDePosicao = _START;
            }

        }

        break;
    case _VERIFICAR_TEMPO_DE_VARREDURA: // step 0

        if (!TempoDeVarreduraOk())
            return;
 
        incrementadorDePosicao = _START;

        break;
    }
}