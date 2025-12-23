#pragma once

#include <SFML/Graphics.hpp>

#include "GerenciadorGrafico.h"

#include <string>

#include <iostream>

class Ente
{
protected:

	static GerenciadorGrafico* pGG;

public:
	Ente(){}
	~Ente(){}

	virtual void executar() = 0;

	static void setGG(GerenciadorGrafico* pG) {
		pGG = pG;
	}
};

