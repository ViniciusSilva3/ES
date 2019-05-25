// Copyright [2018] <Vinicius>
#define CATCH_CONFIG_MAIN
#include "funcoes.h"
#include "evento.hpp"
//#include "catch.hpp"
  TEST_CASE( "Classe Eventos" ){
    SECTION( "Teste do Construtor da classe" ){
        evento Ev1;
        int vf;
        std::string teste = "asd";
        char *vfc;
        Ev1 = evento();
        vf = Ev1.getTipo();
        REQUIRE ( vf == 1 );
        vf = Ev1.getDataInicio();
        REQUIRE ( vf == 1 );
        vf = Ev1.getDataFim();
        REQUIRE ( vf == 1 );
        vf = Ev1.getCodigo();
        REQUIRE ( vf == 1 );
        vf = Ev1.getHorario();
        REQUIRE ( vf == 1 );
        vf = Ev1.getPrecoIngresso();
        REQUIRE ( vf == 1 );
        vf = Ev1.getNumSala();
        REQUIRE ( vf == 1 );
        vf = Ev1.getQuantIngresso();
        REQUIRE ( vf == 1 );
        vf = Ev1.getFaixaEtaria();
        REQUIRE ( vf == 1 );
        vfc = Ev1.getCidade();
        REQUIRE ( teste == vfc );
        vfc = Ev1.getEstado();
        REQUIRE ( teste == vfc );
        vfc = Ev1.getNome();
        REQUIRE ( teste == vfc );
    }//End section 1

}
/*
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
	setFaixaEtaria(1); */
