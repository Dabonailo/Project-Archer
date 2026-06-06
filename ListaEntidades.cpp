#include "ListaEntidades.h"

namespace Listas
{

    ListaEntidades::ListaEntidades() :LEs()
    {
    }

    ListaEntidades::~ListaEntidades()
    {
    }

    void ListaEntidades::incluir(Entidades::Entidade* pE)
    {
        LEs.incluirElemento(pE);
    }

    void ListaEntidades::percorrerLista()
    {
        Lista<Entidades::Entidade>::Elemento<Entidades::Entidade>* aux = LEs.getPrimeiro();

        while (aux != NULL)
        {
            Lista<Entidades::Entidade>::Elemento<Entidades::Entidade>* prox = aux->getProximo();

            aux->getInfo()->executar();

            if (Entidades::Personagens::Personagem* p = dynamic_cast<Entidades::Personagens::Personagem*>(aux->getInfo()))
            {
                if (!p->getVivo()) {
                    LEs.removerElemento(p);
                }
            }

            aux = prox;
        }
    }
    void ListaEntidades::desenharLista()
    {
        Lista<Entidades::Entidade>::Elemento<Entidades::Entidade>* aux = LEs.getPrimeiro();

        while (aux != NULL)
        {
            Lista<Entidades::Entidade>::Elemento<Entidades::Entidade>* prox = aux->getProximo();

            aux->getInfo()->desenhar();

            aux = prox;
        }
    }
}
