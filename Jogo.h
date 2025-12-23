#pragma once
#include <SFML/Graphics.hpp>

#include "Jogador.h"
#include "GerenciadorGrafico.h"

class Jogo
{
private:
	Jogador jogador;
	GerenciadorGrafico GG;

public:
	Jogo();
	~Jogo();

	void executar();
};

