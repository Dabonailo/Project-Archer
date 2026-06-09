#include "Fase.h"

namespace Fases {
	Fase::Fase(sf::Vector2f pos, sf::Vector2f tam, const std::string& textura):
        Ente(pos == sf::Vector2f(0.f, 0.f) ? pGG->getWindowCentro() : pos,
            tam == sf::Vector2f(0.f, 0.f) ? pGG->getWindowTam() : tam, textura), ListaEntFase(), GC(), pJogador(NULL)
    {
        body.setFillColor(sf::Color(255, 255, 255, 150));
    }

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

            if (pJogador->getDirecao() == Direcao::DIREITA) {
                pos.x += pJogador->getBody().getSize().x;
                velP = sf::Vector2f(VELOCIDADE_PROJETIL_X, VELOCIDADE_PROJETIL_Y);
            }
            if (pJogador->getDirecao() == Direcao::ESQUERDA) {
                pos.x -= pJogador->getBody().getSize().x;
                velP = sf::Vector2f(-VELOCIDADE_PROJETIL_X, VELOCIDADE_PROJETIL_Y);
            }

            Entidades::Projetil* novoProjetil = new Entidades::Projetil(pos, velP);

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
        Ente::desenhar();
		ListaEntFase.desenharLista();
	}


}
