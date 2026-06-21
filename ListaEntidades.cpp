#include "ListaEntidades.h"
#include <fstream>

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

    void ListaEntidades::remover(Entidades::Entidade* e)
    {
        LEs.removerElemento(e);
	}

    void ListaEntidades::percorrerLista()
    {
        Lista<Entidades::Entidade>::Elemento<Entidades::Entidade>* aux = LEs.getPrimeiro();

        while (aux != NULL)
        {
            Lista<Entidades::Entidade>::Elemento<Entidades::Entidade>* prox = aux->getProximo();

            bool remover = false; // <<-- mover/definir aqui por iteração

            aux->getInfo()->executar();

            if (Entidades::Personagens::Personagem* p = dynamic_cast<Entidades::Personagens::Personagem*>(aux->getInfo()))
            {
                if (!p->getVivo()) {
                    remover = true;
                }
            }

            if (remover) {
                LEs.removerElemento(aux->getInfo());
            }

            aux = prox;
        }
    }

    void ListaEntidades::salvarEntidades(int idFase, bool doisJogadores)
    {
        std::ofstream arquivo("Salvamentos/Save.txt");

        if (!arquivo.is_open())
        {
            std::cout << "Erro ao abrir Save.txt" << std::endl;
            return;
        }

        // -------------------------
        // Cabeçalho do save
        // -------------------------

        arquivo << idFase << " "
            << (doisJogadores ? 1 : 0)
            << std::endl;

        // -------------------------
        // Entidades
        // -------------------------

        Lista<Entidades::Entidade>::Elemento<Entidades::Entidade>* atual =
            LEs.getPrimeiro();

        while (atual)
        {
            Entidades::Entidade* pEnt = atual->getInfo();

            if (pEnt)
            {
                pEnt->salvar();

                arquivo << pEnt->getBufferInterno();
            }

            atual = atual->getProximo();
        }

        arquivo.close();
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
