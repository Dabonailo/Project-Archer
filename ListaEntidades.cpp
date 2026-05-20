#include "ListaEntidades.h"

ListaEntidades::ListaEntidades() :pPrimeiro(NULL), pUltimo(NULL)
{
}

ListaEntidades::~ListaEntidades()
{
	limparLista();
}

void ListaEntidades::adicionarElemento(Entidade* e)
{
	if (e) {
		Elemento* NovoElemento = new Elemento(e);

		if (pPrimeiro == NULL) {
			pPrimeiro = NovoElemento;
			pUltimo = NovoElemento;
		}

		else {
			Elemento* aux = pPrimeiro;
			while (aux->pProx != NULL) {
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
		pPrimeiro = NULL;
		pUltimo = NULL;
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
		aux->pProx = NULL;
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
		pPrimeiro = NULL;
		pUltimo = NULL;
	}

	else if (pPrimeiro) {
		Elemento* aux = pPrimeiro->pProx;
		while (aux != NULL) {
			delete pPrimeiro;
			pPrimeiro = aux;
			aux = aux->pProx;
		}
		delete pPrimeiro;
		pPrimeiro = NULL;
		pUltimo = NULL;
	}
}

ListaEntidades::Elemento* ListaEntidades::getPrimeiro()
{
	return pPrimeiro;
}

