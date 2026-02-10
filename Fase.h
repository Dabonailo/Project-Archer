#pragma once
#include "ListaEntidades.h"
#include "Inimigo.h"

class Fase
{
protected:
	ListaEntidades ListaEntFase;

protected:
	virtual void criarInimigos() = 0;
	virtual void criarObstaculos() = 0;

public:
	Fase():ListaEntFase(true){}
	~Fase(){}

	ListaEntidades* getListaEntFase() { return &ListaEntFase; }

	virtual void executar() = 0;
};

