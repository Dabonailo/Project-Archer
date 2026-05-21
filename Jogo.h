#pragma once
#include <SFML/Graphics.hpp>

#include "Jogador.h"
#include "GerenciadorGrafico.h"
#include "ListaEntidades.h"
#include "Fase_Primeira.h"

class Jogo
{
private:
	Jogador* pjogador;
	GerenciadorGrafico GG;
	Fase_Primeira fase1;

public:
	Jogo();
	~Jogo();

	void executar();
};

