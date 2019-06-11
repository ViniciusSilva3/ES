#include "evento.hpp"
#include "usuario.hpp"

evento::evento() {
	setTipo(1);
	setDataInicio("asd");
	setDataFim("asd");
	setCidade("asd");
	setEstado("asd");
	setNome("asd");
	setCodigo(1);
	setHorario(1);
	setPrecoIngresso(1);
	setNumSala(1);
	setQuantIngresso(1);
	setFaixaEtaria(1);
}
evento::~evento(void) {
}

int evento::setTipo(int tp) {
	tipo = tp;
	return 1;
}

int evento::setDataInicio(std::string datain) {
	dataInicio = datain;
	return 1;
}
int evento::setDataFim(std::string datafim) {
	dataFim = datafim;
	return 1;
}
int evento::setCidade(std::string Cidade) {
	cidade = Cidade;
	return 1;
}
int evento::setEstado(std::string Estado) {
	estado = Estado;
	return 1;
}
int evento::setNome(std::string Nome) {
	nome = Nome;
	return 1;
}
int evento::setCodigo(int cdg) {
	codigo = cdg;
	return 1;
}
int evento::setHorario(int hor) {
	horario = hor;
	return 1;
}
int evento::setPrecoIngresso(int preco) {
	precoIngresso = preco;
	return 1;
}
int evento::setNumSala(int nm) {
	numeroSala = nm;
	return 1;
}
int evento::setQuantIngresso(int qt) {
	quantIngressos = qt;
	return 1;
}
int evento::setFaixaEtaria(int faixa) {
	faixaEtaria = faixa;
	return 1;
}
int evento::setCriador(std::string str) {
    criador = str;
    return 1;
}
// Metodos Get

int evento::getTipo() {
	return tipo;
}
std::string evento::getDataInicio() {
	return dataInicio;
}
std::string evento::getDataFim() {
	return dataFim;
}
std::string evento::getCidade() {
	return cidade;
}

std::string evento::getEstado() {
	return estado;
}
std::string evento::getNome() {
	return nome;
}
int evento::getCodigo() {
	return codigo;
}
int evento::getHorario() {
	return horario;
}
int evento::getPrecoIngresso() {
	return precoIngresso;
}
int evento::getNumSala() {
	return numeroSala;
}
int evento::getQuantIngresso() {
	return quantIngressos;
}
int evento::getFaixaEtaria() {
	return faixaEtaria;
}
std::string evento::getCriador() {
    return criador;
}
int evento::escreveNovoEvento() {
    /* Esse metodo tem como objetivo armazenar os dados de um evento criado por
     * um admnistrador do sistema em um arquivo de texto, para que possa ser utilizado
     * para mostrar quais eventos atuais estao disponives para compra
     */
    ofstream myfile ("logeventos.txt", ios::app); // o ponteiro de escrita comeca no fim do arquivo
    if (myfile.is_open()) {
        myfile << tipo << " ";
        myfile << dataInicio << " ";
        myfile << dataFim << " ";
        myfile << cidade << " ";
        myfile << estado << " ";
        myfile << nome << " ";
        myfile << codigo << " ";
        myfile << horario << " ";
        myfile << precoIngresso << " ";
        myfile << numeroSala << " ";
        myfile << quantIngressos << " ";
        myfile << faixaEtaria << " "; 
        myfile << criador << "\n";// ultima caracteristica pula uma linha para ler o proximo evento
        myfile.close();
        return 1;
    }
    else cout << "Nao foi possivel abrir arquivo";
    return 0;
}
evento criaNovoEvento(usuario user1) {
    /* Metodo para uso do administrador poder criar novos eventos
     * fornecendo cada uma das caracteristicas necessarias
     */
    evento novoEv;
    novoEv = evento(); // constroi um objeto
    std::string str;
    int temp;
    cout << "Digite o tipo:\n";
    cin >> temp;
    novoEv.setTipo(temp);
    cout << "Digite a data de Inicio:\n";
    cin >> str;
    novoEv.setDataInicio(str);
    cout << "Digite a data de Fim:\n";
    cin >> str;
    novoEv.setDataFim(str);
    cout << "Digite a Cidade:\n";
    cin >> str;
    novoEv.setCidade(str);
    cout << "Digite o Estado:\n";
    cin >> str;
    novoEv.setEstado(str);
    cout << "Digite o Nome:\n";
    cin >> str;
    novoEv.setNome(str);
    cout << "Digite o codigo:\n";
    cin >> temp;
    novoEv.setCodigo(temp);
    cout << "Digite o Horario:\n";
    cin >> temp;
    novoEv.setHorario(temp);
    cout << "Digite o Preco do Ingresso:\n";
    cin >> temp;
    novoEv.setPrecoIngresso(temp);
    cout << "Digite o numero da Sala:\n";
    cin >> temp;
    novoEv.setNumSala(temp);
    cout << "Digite a quantidade de ingressos disponiveis:\n";
    cin >> temp;
    novoEv.setQuantIngresso(temp);
    cout << "Digite a faixa etaria:\n";
    cin >> temp;
    novoEv.setFaixaEtaria(temp);
    novoEv.setCriador(user1.getCpf());
    return novoEv;
}

void MostraEventosPesquisados(std::string DataInicio,std::string DataFim,std::string Cidade,std::string Estado){
ifstream file;
std::string word;
std::string tipo,datainicio,datafim,cidade,estado,nome,codigo,horario,precoingresso;
std::string numerosala,quantingressos,faixaetaria;
int i = 0;    
    file.open ("logeventos.txt");
    
    while (file >> word)
    {
        if (i == 0)
            tipo = word;
        else if (i == 1)
            datainicio = word;
        else if (i == 2)
            datafim = word;
        else if (i == 3)
            cidade = word;
        else if (i == 4)
            estado = word;
        else if (i == 5)
            nome = word;
        else if (i == 6)
            codigo = word;
        else if (i == 7)
            horario = word;
        else if (i == 8)
            precoingresso = word;
        else if (i == 9)
            numerosala = word;
        else if (i == 10)
            quantingressos = word;
        //A partir daqui, todos os dados do evento ja foram reunidos
        else if (i == 11){
            faixaetaria = word;
            i = -1;
            //cout << tipo << datainicio << datafim << cidade << estado << nome << codigo << horario << precoingresso << numerosala << quantingressos << faixaetaria << "\n";
            if(!DataInicio.compare(datainicio) && !DataFim.compare(datafim) && !Cidade.compare(cidade) && !Estado.compare(estado)){
                 cout << "*******************************\n";
                cout << "Evento:" << nome << "\n"; 
                cout << "*******************************\n";
                cout <<"Codigo:"<< codigo << "\n" << "Inicio:" << datainicio << "\n" << "Fim:" << datafim << "\n" << "Preco:" << precoingresso << "\n" <<"Quantidade de ingressos:" << quantingressos <<"\n";
                cout << "Horario:" << horario << "\n" << "Numero da sala:" << numerosala << "\n" << "Faixa etaria:" << faixaetaria << "\n";


            }
        }
        i++;
    }
}
