#pragma once

#include <SFML/Graphics.hpp>

#include <string>

#include <iostream>

class GerenciadorGrafico;

class Ente
{
protected:

	static GerenciadorGrafico* pGG;

public:
	Ente(){}
	virtual ~Ente(){}

	virtual void executar() = 0;

	static void setGG(GerenciadorGrafico* pG) {
		pGG = pG;
	}
};

