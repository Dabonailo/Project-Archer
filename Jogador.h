#pragma once
#include "Personagem.h"

#define NUM_VIDAS 5
#define JOG_VELOCIDADE_DEFAULT_X 0.1f
#define JOG_VELOCIDADE_DEFAULT_Y 0.1f

class Jogador : public Personagem
{
private:

public:
	Jogador();
	~Jogador();

	void mover();

	void executar() override;
};

