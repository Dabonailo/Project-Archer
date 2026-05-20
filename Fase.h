#pragma once
#include "ListaEntidades.h"
#include "Inimigo_facil.h"
#include "GerenciadorColisoes.h"

class Fase
{
protected:
	ListaEntidades ListaEntFase;
	GerenciadorColisoes GC;

protected:
	virtual void adicionarJogador(Jogador* p) = 0;
	virtual void criarInimigos() = 0;
	virtual void criarObstaculos() = 0;

public:
	Fase():ListaEntFase(), GC(){}
	~Fase(){}

	ListaEntidades* getListaEntFase() { return &ListaEntFase; }

	virtual void executar() = 0;
};

