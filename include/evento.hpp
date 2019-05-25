#ifndef EVENTO_HPP_
#define EVENTO_HPP_

#include <iostream>
#include <fstream>
#include <stdio.h>
using namespace std;
class evento {
	private:
	int tipo;  //  representa teatro, esporte, show...
	int dataInicio;
	int dataFim;
	char * cidade;
	char * estado;
	char * nome;
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
	int getDataInicio();
	int getDataFim();
	char *getCidade();
	char *getEstado();
	char *getNome();
	int getCodigo();
	int getHorario();
	int getPrecoIngresso();
	int getNumSala();
	int getQuantIngresso();
	int getFaixaEtaria();

	// Metodos para setar os valores
	int setTipo(int);
	int setDataInicio(int);
	int setDataFim(int);
	int setCidade(char *);
	int setEstado(char *);
	int setNome(char *);
	int setCodigo(int);
	int setHorario(int);
	int setPrecoIngresso(int);
	int setNumSala(int);
	int setQuantIngresso(int);
	int setFaixaEtaria(int);
};

#endif
