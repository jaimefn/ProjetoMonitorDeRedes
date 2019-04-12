#include <Headers\Login.h>

Login Session;

    Login::Login(){
        session = false;
       GerarIdRandomico();
    }
    bool Login::IsLoged(){
            return session;
    }

    void Login::LogOff(){
        session = false;
    }

    bool Login::LogIn(formLogin login){
        
        session = false;
        formLogin frmLogin = MemoriaEEPROM.CarregarFormLogin();
 
        if (strncmp(login.Usuario, frmLogin.Usuario, sizeof frmLogin.Usuario) == 0){
             if (strncmp(login.Senha, frmLogin.Senha, sizeof frmLogin.Senha) == 0){
                GerarIdRandomico();
                session = true; 
        }
        }
        return session;
    }
    void Login::GerarIdRandomico(){
        randomSeed(micros());
        randNumber = random(100,10000);
    }

    long Login::GetRandonId(){
        return randNumber;
    }
    
