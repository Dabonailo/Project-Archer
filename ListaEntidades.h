#pragma once
#include "Entidade.h"

class ListaEntidades
{
private:
	class Elemento {
	public:
		Elemento* pProx;
		Entidade* elemento;

	public:
		Elemento(Entidade* e): pProx(NULL), elemento(e){}
		~Elemento() {
			elemento = NULL;
			pProx = NULL;
		}
	};

	Elemento* pPrimeiro;
	Elemento* pUltimo;

public:
	ListaEntidades();
	~ListaEntidades();

	void adicionarElemento(Entidade* e);
	void removerElemento(Entidade* e);
	void limparLista();

	template <typename Func>
	void percorrerLista(Func& func) {

		for (Elemento* aux = pPrimeiro; aux != NULL; aux = aux->pProx) {

			if (aux->elemento)
				func(aux->elemento);
		}
	}

	Elemento* getPrimeiro();
};

