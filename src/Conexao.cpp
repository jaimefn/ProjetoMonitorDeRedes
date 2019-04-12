#include <Headers\Conexao.h>

Conexao conexao;

uint8_t Ethernet::buffer[1000];

void Conexao::TestarConexaoComInternet()
{
}

void Conexao::ResetarEnc28j60()
{
  
}

void Conexao::InicializarEnc28j60()
{

  formConfiguracaoDaRede frmConfig = MemoriaEEPROM.CarregarFormConfiguracaoDeRede();

if (ether.begin(sizeof Ethernet::buffer, frmConfig.macAdrress, ENC28J60_CS) == 0)
    Serial.println(F("Failed to access Ethernet controller"));


//if (!ether.dhcpSetup())
//    Serial.println(F("DHCP failed"));

  ether.staticSetup(frmConfig.ipAdrress, frmConfig.gwIpAdrress, frmConfig.dnsAdrress, frmConfig.subMascara);
  
  ether.printIp("IP:  ", ether.myip);
  ether.printIp("GW:  ", ether.gwip);
  ether.printIp("DNS: ", ether.dnsip);
  ether.printIp("MASK: ", ether.netmask); 
  Serial.print("MAC: ");
  ether.printMac(ether.mymac);
  Serial.println();   

}