#include "funcoes.h"
#include "evento.hpp"
#include "usuario.hpp"

int main(void) {
	usuario user;
	user = usuario("01234567894","Felipe4");
	user.CriaUsuario();
	user = usuario("01234567891","Felipe5");
	user.CriaUsuario();
	user = usuario("01234567892","Felipe5");
	user.CriaUsuario();
	user = usuario("01234567891","Felipe5");
	user.DeletaUsuario();
	user = usuario("TESTETESTE1","Felipe5");
	user.CriaUsuario();
	user.DeletaUsuario();
	return 0;
}
