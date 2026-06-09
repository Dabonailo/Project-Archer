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
            bool remover = false;

            Lista<Entidades::Entidade>::Elemento<Entidades::Entidade>* prox = aux->getProximo();

            aux->getInfo()->executar();

            if (Entidades::Personagens::Personagem* p = dynamic_cast<Entidades::Personagens::Personagem*>(aux->getInfo()))
            {
                if (!p->getVivo()) {
                    remover = true;
                }
            }

            if (Entidades::Projetil* pr = dynamic_cast<Entidades::Projetil*>(aux->getInfo())) {
                if (!pr->getAtivo()) {
                    remover = true;
                }
            }

            if (remover) {
                LEs.removerElemento(aux->getInfo());
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
