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
		Elemento(Entidade* e): pProx(nullptr), elemento(e){}
		~Elemento() {
			elemento = nullptr;
			pProx = nullptr;
		}
	};

	Elemento* pPrimeiro;
	Elemento* pUltimo;
	bool deletaElementos;

public:
	ListaEntidades(bool deleta = false);
	~ListaEntidades();

	void adicionarElemento(Entidade* e);
	void removerElemento(Entidade* e);
	void limparLista();

	template <typename Func>
	void percorrerLista(Func func) {

		for (Elemento* aux = pPrimeiro; aux != nullptr; aux = aux->pProx) {

			if (aux->elemento)
				func(aux->elemento);
		}
	}

	Elemento* getPrimeiro();
};

