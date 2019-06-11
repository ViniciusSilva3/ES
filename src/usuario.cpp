#include "usuario.hpp"
// Essa funcao cria um usuario novo 
int usuario::CadastrarUsuario(){
    
    std::string cpf, senha;
    int UsuarioExistente = 0;
    
    cout << "Digite o CPF do usuario:\n";
    cin >> cpf;
    cout << "Digite a senha do usuario:\n";
    cin >> senha;
    
    //Cria um usuario que podera ser inserido no sistema
    this->setCpf(cpf);
    this->setSenha(senha);
    
    //Verifica se o CPF ja esta cadastrado no sistema
    UsuarioExistente =  this->LeUsuario();
    if (UsuarioExistente == 0)
        this->EscreveUsuario();
    
    // Se ja existir o CPF o metodo retorna 1
    else{
        cout << "CPF ja esta cadastrado no sistema";
        return 1;
    }
    return 0;
}
// Esse metodo tem como objetivo armazenar os dados de um usuario criado por
 
int usuario::EscreveUsuario() {
    
    ofstream myfile ("logusuarios.txt", ios::app); // o ponteiro de escrita comeca no fim do arquivo
    if (myfile.is_open()) {
        myfile << this->getCpf() << " ";
        myfile << this->getSenha() << "\n";
        myfile.close();
    }
    else
         cout << "Nao foi possivel abrir arquivo";
    return 0;
}
/* Metodo usado para encontrar no banco de dados se existe algum usuario com o mesmo CPF , impe-
* dindo assim duas contas com o mesmo CPF
*
*/
int usuario :: LeUsuario(){
    std::ifstream infile("logusuarios.txt");
    std:: string cpf, senha;
    while( infile >> cpf >> senha){
        if(cpf == this->getCpf()){
            //cout << "Achou\n";
            return 1;
        }
    }

    return 0;

}
/* Verifica se o cpf e a senha digitadas batem com o usuario ja existente no banco de dados 
* Autentificado : Retorna 1
* Não autentificado : Retorna 0
*/
int usuario :: AutentificaUsuario(){
    std::ifstream infile("logusuarios.txt");
    std::string cpf, senha;
    while( infile >> cpf >> senha){
        if(cpf == this->getCpf() && senha == this->getSenha()){
            //Usuario autentificado
            return 1;
        }
    }

return 0;
}
//Esse metodo procura o usuario na lista de usuarios cadastrados e, se existir, faz a exclusao dele 
// do sistema
int usuario:: DeletaUsuario(){

    string DeletarUsuario,line;
    string cpf,senha;

    cpf = this->getCpf();
    senha = this->getSenha();

    ifstream fin;
    fin.open("logusuarios.txt");
    ofstream temp;
    temp.open("temp.txt");
    
    DeletarUsuario = cpf + " " + senha;
    // Procura por todo o arquivo, linha por linha o usuario cadastrado
    while(!fin.eof()){
            getline(fin,line);
            if (line.find(DeletarUsuario) != -1){
                line.replace(line.find(DeletarUsuario),DeletarUsuario.length(),"");
                temp << line;
            }
            else
                temp << line << endl;

    }
    //O arquivo eh reescrito em outro
    temp.close();
    fin.close();
    remove("logusuarios.txt");
    rename("temp.txt","logusuarios.txt");

return 0;
}


int usuario::EditarCpf(std::string cpf){
    
    string UsuarioNovo,UsuarioAntigo,line;
    string senha,CpfNovo,CpfAntigo;

    CpfNovo = cpf;
    CpfAntigo = this->getCpf();
    senha = this->getSenha();

    ifstream fin;
    fin.open("logusuarios.txt");
    ofstream temp;
    temp.open("temp.txt");
    UsuarioAntigo = CpfAntigo + " " + senha;
    UsuarioNovo = CpfNovo + " " + senha;
    // Procura por todo o arquivo, linha por linha o usuario para trocar CPF
    while(!fin.eof()){
            getline(fin,line);
            if (line.find(UsuarioAntigo) != -1)
                line.replace(line.find(UsuarioAntigo),UsuarioNovo.length(),UsuarioNovo);
                temp << line << endl;

    }
    //O arquivo eh reescrito em outro
    temp.close();
    fin.close();
    remove("logusuarios.txt");
    rename("temp.txt","logusuarios.txt");

return 0;
}

int usuario::EditarSenha(std::string senha){
    
    string UsuarioNovo,UsuarioAntigo,line;
    string SenhaNova,cpf,SenhaAntiga;

    SenhaNova = senha;
    SenhaAntiga = this->getSenha();
    cpf = this->getCpf();

    ifstream fin;
    fin.open("logusuarios.txt");
    ofstream temp;
    temp.open("temp.txt");
    UsuarioAntigo = cpf + " " + SenhaAntiga;
    UsuarioNovo = cpf + " " + SenhaNova;
    // Procura por todo o arquivo, linha por linha o usuario para trocar CPF
    while(!fin.eof()){
            getline(fin,line);
            if (line.find(UsuarioAntigo) != -1)
                line.replace(line.find(UsuarioAntigo),UsuarioNovo.length(),UsuarioNovo);
                temp << line << endl;

    }
    //O arquivo eh reescrito em outro
    temp.close();
    fin.close();
    remove("logusuarios.txt");
    rename("temp.txt","logusuarios.txt");

return 0;
}