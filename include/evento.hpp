#ifndef EVENTO_HPP_
#define EVENTO_HPP_

#include <iostream>
#include <fstream>
#include <stdio.h>
using namespace std;
class evento {
	private:
	int tipo;  //  representa teatro, esporte, show...
	std::string dataInicio;
	std::string dataFim;
	std::string cidade;
	std::string estado;
	std::string nome;
	int codigo;
	int horario;
	int precoIngresso;
	int numeroSala;
	int quantIngressos;
	int faixaEtaria;

	public:
	evento();  // construtor
	~evento();  // destrutor
	// Metodos para acessar os valores
	int getTipo();
	std::string getDataInicio();
	std::string getDataFim();
	std::string getCidade();
	std::string getEstado();
	std::string getNome();
	int getCodigo();
	int getHorario();
	int getPrecoIngresso();
	int getNumSala();
	int getQuantIngresso();
	int getFaixaEtaria();

	// Metodos para setar os valores
	int setTipo(int);
	int setDataInicio(std::string);
	int setDataFim(std::string);
	int setCidade(std::string);
	int setEstado(std::string);
	int setNome(std::string);
	int setCodigo(int);
	int setHorario(int);
	int setPrecoIngresso(int);
	int setNumSala(int);
	int setQuantIngresso(int);
	int setFaixaEtaria(int);
};

#endif
