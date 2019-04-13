#include <EtherCard.h>

void MainOpenCabecalho(){
    char *page = PSTR("HTTP/1.0 200 OK\r\n"
                    "Content-Type: text/html\r\n"
                    "cache-control: max-age=31536000, public\r\n"
                    "Pragma: cache\r\n\r\n"
                    "<!DOCTYPE html>\r\n"
                    "<html lang='pt-BR'>\r\n"
                    "<head>\r\n"
                    "<title>Controle da Interface</title>\r\n"
                    "<meta http-equiv='Content-Type' content='text/html; charset=utf-8'>\r\n"
                    "<meta name='viewport' content='width=device-width, initial-scale=1'>\r\n"
                    
                    //"<link rel='stylesheet' href='bootstrap.css'>\r\n"
                    //"<link rel='stylesheet' href='https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css'>\r\n"
                    "<link rel='stylesheet' href='https://cdn.rawgit.com/jaimefn/cdn/master/bootstrap.css'>\r\n"
                    
                    //"<link rel='stylesheet' href='menu.css'>\r\n"
                    "<link rel='stylesheet' href='https://cdn.rawgit.com/jaimefn/cdn/master/menu.css'>\r\n"
                    
                    //"<script src='jquery.js'></script>\r\n"                    
                    //"<script src='https://ajax.googleapis.com/ajax/libs/jquery/3.2.1/jquery.min.js'></script>\r\n"
                    "<script src='https://cdn.rawgit.com/jaimefn/cdn/master/jquery.js'></script>\r\n"

                    //"<script src='bootstrap.js'></script>"
                    //"<script src='https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js'></script>\r\n"
                    "<script src='https://cdn.rawgit.com/jaimefn/cdn/master/bootstrap.js'></script>\r\n"
                    
                    //"<script src='code.js'></script>\r\n"
                    //"<script src='https://cdn.rawgit.com/jaimefn/cdn/master/code_v2.js'></script>\r\n"
                    "<script src='https://gitcdn.xyz/repo/jaimefn/cdn_teste/master/codigo_v3.js'></script>\r\n"
         
                    //"<script src='rgccore.js'></script>\r\n"
                    "<script src='https://cdn.rawgit.com/jaimefn/cdn/master/rgsccore.js'></script>\r\n"
                    
                    //"<script src='rgcajax.js'></script>\r\n"
                    "<script src='https://cdn.rawgit.com/jaimefn/cdn/master/rgcajax.js'></script>\r\n"
                    
                    //"<script src='rgline.js'></script>\r\n"
                    "<script src='https://cdn.rawgit.com/jaimefn/cdn/master/rgsline.js'></script>\r\n"
                    
                    //"<script src='rgbar.js'></script>\r\n"
                    "<script src='https://cdn.rawgit.com/jaimefn/cdn/master/rgsbar.js'></script>\r\n"
);

     ether.fillAndSend(page, sizeof page);
}