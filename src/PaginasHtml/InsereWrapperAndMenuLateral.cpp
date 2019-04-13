#include <EtherCard.h>

extern void InsereBotaoOpenCloseMenu();

void InsereWrapperAndMenuLateral()
{
     char *page = PSTR("<div id='wrapper' class='toggled'>\r\n"
            "<!-- Sidebar -->\r\n"
            "<div id='sidebar-wrapper'>\r\n"
            "    <ul class='sidebar-nav'>\r\n"
            "<li class='sidebar-brand'><a href='#' style='color:white'>Menu</a></li>"
            "        <li><a href='#' id='link_ctrlcontrole'>Controle das Saidas</a></li>\r\n"
            "        <li><a href='#' id='link_log'>Log De Falhas</a></li>\r\n"
            //"        <li><a href='#' id='link_sensores'>Sensores</a></li>\r\n"
            //"        <li><a href='#' id='link_estatisticas'>Estatisticas</a></li>\r\n"
            "        <li><a href='#' id='link_ping'>Configurar Ping</a></li>\r\n"
            "        <li><a href='#' id='link_watchdog'>WatchDog</a></li>\r\n"
            "        <li><a href='#' id='link_inter_controle'>Interface de Controle</a></li>\r\n"
            "        <li><a href='#' id='link_rede'>Configuracoes de Rede</a></li>\r\n"
            "        <li><a href='#' id='link_senha'>Alterar Senha</a></li>\r\n"
            "        <li><a href='#' id='link_Data'>Data e Hora</a></li>\r\n"
            "        <li><a href='#' id='link_assistencia'>Assistencia tecnica</a></li>\r\n"
            "    </ul>\r\n"
            "</div>\r\n"
            "<!-- /#sidebar-wrapper -->\r\n");
    ether.fillAndSend(page, sizeof page);

}