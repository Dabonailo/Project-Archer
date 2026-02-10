#pragma once
#include <SFML/Graphics.hpp>

#include "Jogador.h"
#include "GerenciadorGrafico.h"
#include "ListaEntidades.h"
#include "Fase_Primeira.h"

class Jogo
{
private:
	Jogador jogador;
	GerenciadorGrafico GG;
	Fase_Primeira fase1;
	ListaEntidades ListaEntFixa;

public:
	Jogo();
	~Jogo();

	void executar();
};

