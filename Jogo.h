#pragma once
#include <SFML/Graphics.hpp>

#include "Jogador.h"
#include "GerenciadorGrafico.h"
#include "ListaEntidades.h"
#include "Fase_Primeira.h"

class Jogo
{
private:
	Entidades::Personagens::Jogador* pjogador;
	Gerenciadores::GerenciadorGrafico GG;
	Fases::Fase_Primeira fase1;

public:
	Jogo();
	~Jogo();

	void executar();
};

