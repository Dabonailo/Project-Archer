#include "ListaEntidades.h"

ListaEntidades::ListaEntidades(bool deleta) :pPrimeiro(nullptr), pUltimo(nullptr), deletaElementos(deleta)
{
}

ListaEntidades::~ListaEntidades()
{
	Elemento* aux = pPrimeiro;
	while (aux) {
		Elemento* prox = aux->pProx;

		if (deletaElementos)
			delete aux->elemento;

		delete aux;
		aux = prox;
	}
}

void ListaEntidades::adicionarElemento(Entidade* e)
{
	if (e) {
		Elemento* NovoElemento = new Elemento(e);

		if (pPrimeiro == nullptr) {
			pPrimeiro = NovoElemento;
			pUltimo = NovoElemento;
		}

		else {
			Elemento* aux = pPrimeiro;
			while (aux->pProx != nullptr) {
				aux = aux->pProx;
			}
			aux->pProx = NovoElemento;
			pUltimo = NovoElemento;
		}
	}
}

void ListaEntidades::removerElemento(Entidade* e)
{
	if (pPrimeiro->elemento == pUltimo->elemento && pPrimeiro->elemento == e) {
		delete pPrimeiro;
		delete pUltimo;
		pPrimeiro = nullptr;
		pUltimo = nullptr;
	}
	else if (pPrimeiro->elemento == e) {
		Elemento* aux = pPrimeiro->pProx;
		delete pPrimeiro;
		pPrimeiro = aux;
	}
	else if (pUltimo->elemento == e) {
		Elemento* aux = pPrimeiro;
		while (aux->pProx != pUltimo) {
			aux = aux->pProx;
		}
		aux->pProx = nullptr;
		delete pUltimo;
		pUltimo = aux;
	}
	else {
		Elemento* aux = pPrimeiro;
		while (aux->pProx->elemento != e) {
			aux = aux->pProx;
		}
		Elemento* temp = aux->pProx;
		aux->pProx = temp->pProx;
		delete temp;
	}
}

void ListaEntidades::limparLista()
{
	if (pPrimeiro == pUltimo) {
		delete pPrimeiro;
		delete pUltimo;
		pPrimeiro = nullptr;
		pUltimo = nullptr;
	}

	else if (pPrimeiro) {
		Elemento* aux = pPrimeiro->pProx;
		while (aux != nullptr) {
			delete pPrimeiro;
			pPrimeiro = aux;
			aux = aux->pProx;
		}
		delete pPrimeiro;
		pPrimeiro = nullptr;
		pUltimo = nullptr;
	}
}

ListaEntidades::Elemento* ListaEntidades::getPrimeiro()
{
	return pPrimeiro;
}

