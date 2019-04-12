#ifndef _MAQUINA_DE_ESTADO_H
#define _MAQUINA_DE_ESTADO_H

#include <Headers\StructData.h>
#include <Headers\BancoDeDados.h>
#include <Headers\CtrlSaidas.h>
#include <Headers\CtrlResets.h>
#include <Headers\Latencia.h>
#include <Headers\LogDeFalha.h>
#include <Headers\colecao.h>
#include <Headers\Conexao.h>
#include <EtherCard.h>


#define _TimeOut 1
#define _ReplyOk 2
#define _Waiting 0

#define _CONFIGURACAO_INICIAL 0
#define _START 1
#define _VERIFICAR_SE_EXISTE_REDE_DISPONIVEL_PARA_PINGAR 2
#define _PINGAR_REDE_MONITORADA 3
#define _AGUARDAR_RESPOSTA_DO_PING 4
#define _AGUARDAR_1S 5
#define _RESETAR_REDE 6
#define _VAI_PARA_PROXIMA_REDE 7
#define _VERIFICAR_SE_ATINGIU_LIMITE_DE_RESETS 8
#define _VERIFICAR_TEMPO_DE_VARREDURA 9

class MaquinaDeEstado
{
  public:
    MaquinaDeEstado();
    void AtualizarMaquinaDeEstado();

  private:
    typedef struct RedeMonitorada
    {
        uint8_t id;
        uint8_t ip[4];
        uint8_t mac[6];
        uint16_t numeroDeResets;
        uint16_t numeroDeTimeOut;
        float latencia;
    };

    typedef struct ParametrosDaMaquinaDeEstado
    {
        uint8_t quantidadeDeRedesMonitoradas;
        uint8_t proximaRedeMonitorada;
        uint8_t idDaRedeEmAnalise;
        unsigned long tempoDeVarredura;
        uint16_t tempoDeAcionamento;
        uint16_t tempoTimeOut;
        uint16_t numeroDeBytesDoPing;
        uint16_t QuantidadeDePings;
        uint16_t PercaDePacotesMaxima;
        uint16_t PercaDePacotesSequencial;
        uint16_t RegistroDeLatenciaAlta;
        uint16_t maxResets;
        uint16_t numeroDePingsEnviados;
        RedeMonitorada redeMonitorada[4];
    };

    ParametrosDaMaquinaDeEstado MDE;
    RedeMonitorada redeMonitorada;
    unsigned long bfTempoDeVarredura = 0;
    unsigned long bfTempoDeTimeOut = 0;
    unsigned long bfTempo1seg = 0;    

    bool ResetarModuloEthernet();
    void AtualizarBufferStatusPing();
    bool ExisteRedeDisponivelParaPingar();
    void ResetarVariaveisDeTodasRedesMonitoras();
    bool VerificarSeRedeAtingiuLimiteDeResets(uint8_t id);
    void DesativarRedeTemporariamente();
    void IncrementarContagemDePingsPerdidos();
    void ResetarVariaveisDaRedeEmAnalise();
    void IncrementarContagemDeRedeResetada();
    void LimparIpsResiduais();
    void AtualizarRelogioTempoDeUmSegundo();
    bool TempoDeUmSegundoOk();
    void SolicitarEnderecoMacDoDispositivoRemoto(char *ip);
    void ResetarVariaveisDaMaquinaDeEStado();
    bool PularParaProximaRedeMonitorada();
    void IncrementarContagemDePingsEnviados();
    void AtualizarRelogioDeTimeOut();
    bool TempoDeTimeOutEstourou();
    void AtualizarRelogioDeVarredura();
    bool TempoDeVarreduraOk();
    byte QuantidadeDeRedesMonitoradas();
    void PingarRedeMonitorada();
    void CriarObjetosDeMonitoramento();
    void InicializarVariaveisDaMaquinaDeEstado();
    void Init_MaquinaDeEstado();
    bool VerificarSeBancoDeDAdosFoiAlterado();
    bool ValidarMaquinaDeEstado();
    bool TerminouDeEnviarOsPings();
    bool RespostaDoPingChegou();
    bool VerificarSePrecisaResetarRede();
    void AtualizarColecaoDeDados(uint8_t sinalizarRedeResetada);
};

extern MaquinaDeEstado maquinaDeEstado;

#endif