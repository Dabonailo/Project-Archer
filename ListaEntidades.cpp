#include "ListaEntidades.h"

ListaEntidades::ListaEntidades() :LEs()
{
}

ListaEntidades::~ListaEntidades()
{
}

void ListaEntidades::incluir(Entidade* pE)
{
	LEs.incluirElemento(pE);
}

void ListaEntidades::percorrerLista()
{
    Lista<Entidade>::Elemento<Entidade>* aux = LEs.getPrimeiro();

    while (aux != NULL)
    {
        Lista<Entidade>::Elemento<Entidade>* prox = aux->getProximo();

        aux->getInfo()->executar();

        if (Personagem* p = dynamic_cast<Personagem*>(aux->getInfo()))
        {
            if (!p->getVivo()) {
                LEs.removerElemento(p);
            }
        }

        aux = prox;
    }
}

