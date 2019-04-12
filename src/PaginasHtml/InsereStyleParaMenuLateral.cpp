#include <EtherCard.h>

void InsereStyleParaMenuLateral(){

 char *page = PSTR(
"<style>\r\n"
"body {\r\n"
"overflow-x: hidden;\r\n"
"}\r\n"
"#wrapper {\r\n"
"padding-left: 0;\r\n"
"-webkit-transition: all 0.5s ease;\r\n"
"-moz-transition: all 0.5s ease;\r\n"
"-o-transition: all 0.5s ease;\r\n"
"transition: all 0.5s ease;\r\n"
"}\r\n"
"#wrapper.toggled {\r\n"
"padding-left: 250px;\r\n"
"}\r\n"
"#sidebar-wrapper {\r\n"
"z-index: 1000;\r\n"
"position: fixed;\r\n"
"left: 250px;\r\n"
"width: 0;\r\n"
"height: 100%;\r\n"
"margin-left: -250px;\r\n"
"overflow-y: auto;\r\n"
"background: #000;\r\n"
"-webkit-transition: all 0.5s ease;\r\n"
"-moz-transition: all 0.5s ease;\r\n"
"-o-transition: all 0.5s ease;\r\n"
"transition: all 0.5s ease;\r\n"
"}\r\n"
"#wrapper.toggled #sidebar-wrapper {\r\n"
"width: 250px;\r\n"
"}\r\n"
"#page-content-wrapper {\r\n"
"width: 100%;\r\n"
"position: absolute;\r\n"
"padding: 15px;\r\n"
"}\r\n"
"#wrapper.toggled #page-content-wrapper {\r\n"
"position: absolute;\r\n"
"margin-right: -250px;\r\n"
"}\r\n"
".sidebar-nav {\r\n"
"position: absolute;\r\n"
"top: 0;\r\n"
"width: 250px;\r\n"
"margin: 0;\r\n"
"padding: 0;\r\n"
"list-style: none;\r\n"
"}\r\n"
".sidebar-nav li {\r\n"
"text-indent: 20px;\r\n"
"line-height: 40px;\r\n"
"}\r\n"
".sidebar-nav li a {\r\n"
"display: block;\r\n"
"text-decoration: none;\r\n"
"color: #999999;\r\n"
"}\r\n"
".sidebar-nav li a:hover {\r\n"
"text-decoration: none;\r\n"
"color: #fff;\r\n"
"background: rgba(255, 255, 255, 0.2);\r\n"
"}\r\n"
".sidebar-nav li a:active, .sidebar-nav li a:focus {\r\n"
"text-decoration: none;\r\n"
"}\r\n"
".sidebar-nav>.sidebar-brand {\r\n"
"height: 65px;\r\n"
"font-size: 18px;\r\n"
"line-height: 60px;\r\n"
"}\r\n"
".sidebar-nav>.sidebar-brand a {\r\n"
"color: #999999;\r\n"
"}\r\n"
".sidebar-nav>.sidebar-brand a:hover {\r\n"
"color: #fff;\r\n"
"background: none;\r\n"
"}\r\n"
"@media(min-width:768px) {\r\n"
"#wrapper {\r\n"
"padding-left: 0;\r\n"
"}\r\n"
"#wrapper.toggled {\r\n"
"padding-left: 250px;\r\n"
"}\r\n"
"#sidebar-wrapper {\r\n"
"width: 0;\r\n"
"}\r\n"
"#wrapper.toggled #sidebar-wrapper {\r\n"
"width: 250px;\r\n"
"}\r\n"
"#page-content-wrapper {\r\n"
"padding: 20px;\r\n"
"position: relative;\r\n"
"}\r\n"
"#wrapper.toggled #page-content-wrapper {\r\n"
"position: relative;\r\n"
"margin-right: 0;\r\n"
"}\r\n"
"}\r\n"
"</style>\r\n");
 
 ether.fillAndSend(page, sizeof page);

}
