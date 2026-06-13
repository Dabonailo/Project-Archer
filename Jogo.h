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
	Entidades::Personagens::Jogador* pjogador2;

	Gerenciadores::GerenciadorGrafico* GG;
	Gerenciadores::GerenciadorEventos* GE;

	Fases::Fase_Primeira* fase1;
	Menu* menu;

public:
	Jogo();
	~Jogo();

	int getVidaJogador(int j);
	int getPontuacaoJogador(int j);

	void criarFasePrimeira();
	void deletarFasePrimeira();

	void executarMenu();

	void executar();
};

