#include "funcoes.h"
#include "evento.hpp"
#include "usuario.hpp"
#include "menu.hpp"

int main(void) {
	usuario user;
	user = usuario("Felipe","Felipe1");
		user.EditarSenha("Vinica12345");	
	mainmenu();
	return 0;
}
