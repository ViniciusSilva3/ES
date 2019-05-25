// Copyright [2018] <Vinicius>
#define CATCH_CONFIG_MAIN
#include "funcoes.h"
#include "evento.hpp"
//#include "catch.hpp"
  TEST_CASE( "Classe Eventos" ){
    SECTION( "Teste do Construtor da classe" ){
        evento Ev1;
        int vf;
        std::string teste = "asd", vfc;
        Ev1 = evento();
        vf = Ev1.getTipo();
        REQUIRE ( vf == 1 );
        vfc = Ev1.getDataInicio();
        REQUIRE ( vfc == teste );
        vfc = Ev1.getDataFim();
        REQUIRE ( vfc == teste );
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

    SECTION( "Teste dos metodos SET ") {
        evento Ev1;
        int teste;
        std::string str1 = "Brasilia";
        std::string str2 = "DF";
        std::string str3 = "Iron Maiden";
        std::string str4 = "10/01/1910";
        std::string strT;
        Ev1 = evento();
        Ev1.setTipo(10);
        teste = Ev1.getTipo();
        REQUIRE( teste == 10 );
        Ev1.setDataInicio("10/01/1910");
        strT = Ev1.getDataInicio();
        REQUIRE( strT == str4 );
        Ev1.setDataFim("10/01/1910");
        strT = Ev1.getDataFim();
        REQUIRE( strT == str4 );
        Ev1.setCodigo(2);
        teste = Ev1.getCodigo();
        REQUIRE( teste == 2 );
        Ev1.setHorario(21);
        teste = Ev1.getHorario();
        REQUIRE( teste == 21 );
        Ev1.setPrecoIngresso(200);
        teste = Ev1.getPrecoIngresso();
        REQUIRE( teste == 200 );
        Ev1.setNumSala(11);
        teste = Ev1.getNumSala();
        REQUIRE( teste == 11 );
        Ev1.setQuantIngresso(50000);
        teste = Ev1.getQuantIngresso();
        REQUIRE( teste == 50000 );
        Ev1.setFaixaEtaria(12);
        teste = Ev1.getFaixaEtaria();
        REQUIRE( teste == 12 );
        Ev1.setCidade("Brasilia");
        strT = Ev1.getCidade();
        REQUIRE( strT == str1 );
        Ev1.setEstado("DF");
        strT = Ev1.getEstado();
        REQUIRE( strT == str2 );
        Ev1.setNome("Iron Maiden");
        strT = Ev1.getNome();
        REQUIRE( strT == str3 );
    } // fim da secao 2
} // fim teste case

