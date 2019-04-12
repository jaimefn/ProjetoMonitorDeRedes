#include <arduino.h>
#include <avr\wdt.h>
#include <Headers\Login.h>
#include <Headers\FuncoesUteis.h>
#include <Headers\BancoDeDados.h>
#include <Headers\paginas_html.h>
#include <Headers\Conexao.h>
#include <Headers\GerenciadorDeComandosHTTP.h>
#include <Headers\MaquinaDeEstado.h>
#include <Headers\CtrlSaidas.h>
#include <Headers\json.h>
#include <Headers\ResetarCpu.h>
#include <Headers\CtrlResets.h>
#include <Headers\Latencia.h>
#include <Headers\Relogio.h>
#include <Headers\BtnReset.h>
//VetorDeBoot
extern void InicializarSistema();

