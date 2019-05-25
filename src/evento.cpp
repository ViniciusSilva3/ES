#include "evento.hpp"

evento::evento() {
	setTipo(1);
	setDataInicio(1);
	setDataFim(1);
	setCidade((char *)"asd");
	setEstado((char *)"asd");
	setNome((char *)"asd");
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

int evento::setDataInicio(int datain) {
	dataInicio = datain;
	return 1;
}
int evento::setDataFim(int datafim) {
	dataFim = datafim;
	return 1;
}
int evento::setCidade(char *Cidade) {
	cidade = Cidade;
	return 1;
}
int evento::setEstado(char *Estado) {
	estado = Estado;
	return 1;
}
int evento::setNome(char* Nome) {
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

// Metodos Get

int evento::getTipo() {
	return tipo;
}
int evento::getDataInicio() {
	return dataInicio;
}
int evento::getDataFim() {
	return dataFim;
}
char * evento::getCidade() {
	return cidade;
}

char* evento::getEstado() {
	return estado;
}
char * evento::getNome() {
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
