#include "Fase.h"

namespace Fases {
	Fase::Fase():ListaEntFase(), GC(), pJogador(NULL){}

	Fase::~Fase() {}

	void Fase::adicionarJogador(Entidades::Personagens::Jogador* p)
	{
		ListaEntFase.incluir(p);
		GC.incluirJogadores(p);
		pJogador = p;
	}

    void Fase::criarProjetilJogador()
    {
        if (pJogador->getQuerAtirar()) {
            sf::Vector2f pos = pJogador->getPosicao();
            sf::Vector2f velP;
            sf::Vector2f escala;

            if (pJogador->getDirecao() == Direcao::DIREITA) {
                pos.x += pJogador->getBody().getSize().x;
                velP = sf::Vector2f(VELOCIDADE_PROJETIL_X, VELOCIDADE_PROJETIL_Y);
                escala = sf::Vector2f(1.f, 1.f);
            }
            if (pJogador->getDirecao() == Direcao::ESQUERDA) {
                pos.x -= pJogador->getBody().getSize().x;
                velP = sf::Vector2f(-VELOCIDADE_PROJETIL_X, VELOCIDADE_PROJETIL_Y);
                escala = sf::Vector2f(-1.f, 1.f);
            }

            Entidades::Projetil* novoProjetil = new Entidades::Projetil(pos, escala, velP);

            ListaEntFase.incluir(novoProjetil);
            GC.incluirProjetil(novoProjetil);

            pJogador->setQuerAtirar(false);
        }
    }

	Listas::ListaEntidades* Fase::getListaEntFase()
	{
		return &ListaEntFase;
	}

	void Fase::desenhar() {
		ListaEntFase.desenharLista();
	}


}
