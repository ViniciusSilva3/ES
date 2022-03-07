#ifndef USUARIO_HPP_
#define USUARIO_HPP_

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <cstring>
using namespace std;
static const size_t npos = -1;
class usuario {
    private:
        std::string  cpf;
        std::string  senha;
    public:
        usuario() {};  //Construtor
        usuario(std::string cpf,std::string senha){
            setCpf(cpf);
            setSenha(senha);
        } 
        ~usuario(){}; // Destrutor
        inline void setCpf(std::string cpf){
            this->cpf = cpf;
        }
        inline void setSenha(std::string senha){
            this->senha = senha;
        }
        inline std::string getCpf() {return cpf;}
        inline std::string getSenha() {return senha;}
        // Funcoes que mexem na classe usuario
        int CadastrarUsuario(void);
        int EditarSenha(std::string);
        int EditarCpf(std::string);
        int AutentificaUsuario();
        int EscreveUsuario();
        int LeUsuario();
        int DeletaUsuario();
};



   





#endif