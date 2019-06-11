#include "menu.hpp"
#include "evento.hpp"
#include <stdlib.h>
usuario user;
evento event;

int mainmenu(){
    int a,b,c,logado = 0,cad = 0;

    while(1){
        cout << "*******************************\n";
        cout << "Site de vendas de ingressos VHF\n";
        cout << "*******************************\n";
        cout << "1 - login\n";
        cout << "2 - Cadastrar Usuário\n";
        cout << "3 - Sair do Site\n";
        cin >> a;
        switch(a){
            case 1:
                system("clear");
                logado = menulogin();
                break;
            case 2:
                system("clear");
                menucadastrar();
                break;
            case 3:
                return 0; 
            default:
                break;
        }
        //menu logado
        while(logado){
            system("clear");
            cout << "*******************************\n";
            cout << "Site de vendas de ingressos VHF\n";
            cout << "Usuario:" << user.getCpf() <<"\n";
            cout << "*******************************\n";
            cout << "1 - Visualizar eventos\n";
            cout << "2 - Criar um evento\n";
            cout << "3 - Gerenciar Cadastro\n";
            cout << "4 - Logout\n";
            cin >> b;
            switch(b){
                case 1:
                    
                    break;
                case 2:
                    event = criaNovoEvento();
                    event.escreveNovoEvento();
                    break;
                case 3:
                    cad = 1;
                    while(cad){
                    system("clear");
                    cout << "*******************************\n";
                    cout << "Site de vendas de ingressos VHF\n";
                    cout << "Usuario:" << user.getCpf() <<"\n";
                    cout << "*******************************\n";
                    cout << "1 - Alterar CPF\n";
                    cout << "3 - Alterar Senha\n";
                    cout << "3 - Deletar Usuário\n";
                    cout << "4 - Voltar\n";
                    cin >> c;
                    switch(c){
                        case 1:
                            user.EditarCpf(user.getCpf());
                            system("clear");
                            cout << "CPF alterado com sucesso!\n";
                            break;
                        case 2:
                            user.EditarSenha(user.getSenha());
                            cout << "Senha alterado com sucesso!\n";
                            break;
                        case 3:
                            user.DeletaUsuario();
                            system("clear");
                            cout << "Usuário Deletado com sucesso!\n";
                            cad = 0;
                            logado = 0;
                            break;
                        case 4:
                            cad = 0;
                            break;
                        default:
                            break;       
            }
                    break;
                case 4:
                    logado = 0;
                    break;
                default:
                    break;    
            }
        }
        
        }
    }
}
// Login do menu,retorna 0 se não achar usuário, 1 se encontra-lo
int menulogin(){   
    std::string a,b;
    cout << "Digite seu CPF:\n";
    cin  >> a;
    user.setCpf(a);
    cout << "Digite sua senha:\n";
    cin  >> b;
    user.setSenha(b); 
    if(!(user.AutentificaUsuario())){
        system("clear");
        cout<< "Usuário não cadastrado\n";
        return 0;
    }
        return 1;
}
void menucadastrar(){
    user.CadastrarUsuario();
    system("clear");
    cout << "Cadastro Realizado com sucesso!\n";
}