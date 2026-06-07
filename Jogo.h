#pragma once
#include <SFML/Graphics.hpp>

#include "Jogador.h"
#include "GerenciadorGrafico.h"
#include "GerenciadorEventos.h"
#include "ListaEntidades.h"
#include "Fase_Primeira.h"
#include "Menu.h"

class Jogo
{
private:
	Entidades::Personagens::Jogador* pjogador;
	Gerenciadores::GerenciadorGrafico* GG;
	Gerenciadores::GerenciadorEventos* GE;
	Fases::Fase_Primeira* fase1;
	Menu* menu;

public:
	Jogo();
	~Jogo();

	void criarFasePrimeira();
	void deletarFasePrimeira();

	void executarMenu();

	void executar();
};

