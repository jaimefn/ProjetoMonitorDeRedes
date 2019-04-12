#ifndef _LOGIN_H
#define _LOGIN_H

#include <arduino.h>
#include <Headers\BancoDeDados.h>

class Login{
    public:
    Login();

    bool IsLoged();

    void LogOff();

    bool LogIn(formLogin login);

    long GetRandonId();
    
    private:
long randNumber;
bool session = false;

void GerarIdRandomico();

};

extern Login Session;

#endif