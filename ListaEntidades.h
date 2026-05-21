#pragma once
#include "Entidade.h"
#include "Personagem.h"
#include "Lista.h"

class ListaEntidades
{
private:
	Lista<Entidade> LEs;

public:
	ListaEntidades();
	~ListaEntidades();

	void incluir(Entidade* pE);
	void percorrerLista();
};

