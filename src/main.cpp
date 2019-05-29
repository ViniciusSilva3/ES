#include "funcoes.h"
#include "evento.hpp"
#include "usuario.hpp"

int main(void) {
	usuario user;
	user = usuario("Felipe","Felipe1");
		user.EditarSenha("Vinica12345");	
	return 0;
}
