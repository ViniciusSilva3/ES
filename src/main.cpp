#include "funcoes.h"
#include "evento.hpp"

int main(void) {
	evento Ev;
	Ev = criaNovoEvento();
    Ev.escreveNovoEvento();
	return 0;
}
