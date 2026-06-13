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
		lJogs.incluir(p);
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

    void Fase::criarInimgosFaceis()
    {
        Entidades::Personagens::Oni* inimigo;

        if (rand() % 2 == 0)
        {
            inimigo = new Entidades::Personagens::Oni();
            inimigo->setPosicao(sf::Vector2f(280.f, 560.f));
            inimigo->setListaJogadores(&lJogs);
            ListaEntFase.incluir(inimigo);
            GC.incluirInimigo(inimigo);
        }


        inimigo = new Entidades::Personagens::Oni();
        inimigo->setPosicao(sf::Vector2f(560.f, 455.f));
        inimigo->setListaJogadores(&lJogs);
        ListaEntFase.incluir(inimigo);
        GC.incluirInimigo(inimigo);

        inimigo = new Entidades::Personagens::Oni();
        inimigo->setPosicao(sf::Vector2f(875.f, 350.f));
        inimigo->setListaJogadores(&lJogs);
        ListaEntFase.incluir(inimigo);
        GC.incluirInimigo(inimigo);

        inimigo = new Entidades::Personagens::Oni();
        inimigo->setPosicao(sf::Vector2f(490.f, 245.f));
        inimigo->setListaJogadores(&lJogs);
        ListaEntFase.incluir(inimigo);
        GC.incluirInimigo(inimigo);

        if (rand() % 2 == 0)
        {
            inimigo = new Entidades::Personagens::Oni();
            inimigo->setPosicao(sf::Vector2f(1015.f, 175.f));
            inimigo->setListaJogadores(&lJogs);
            ListaEntFase.incluir(inimigo);
            GC.incluirInimigo(inimigo);
        }
    }

    void Fase::criarPlataformas()
    {
        // Parede esquerda
        Entidades::Obstaculos::Plataforma* p =
            new Entidades::Obstaculos::Plataforma(
                sf::Vector2f(-40.f, 350.f),
                sf::Vector2f(200.f, 700.f),
                "parede_tijolo.png",
                sf::Vector2f(0.f, 0.f),
                false);

        ListaEntFase.incluir(p);
        GC.incluirObstaculo(p);

        // Parede direita
        p = new Entidades::Obstaculos::Plataforma(
            sf::Vector2f(1270.f, 350.f),
            sf::Vector2f(200.f, 700.f),
            "parede_tijolo.png",
            sf::Vector2f(0.f, 0.f),
            false);

        ListaEntFase.incluir(p);
        GC.incluirObstaculo(p);

        // Plataforma 1
        p = new Entidades::Obstaculos::Plataforma(
            sf::Vector2f(280.f, 595.f),
            sf::Vector2f(245.f, 35.f),
            "ginger_brand/Plataforma.png",
            sf::Vector2f(0.f, 0.f),
            false);

        ListaEntFase.incluir(p);
        GC.incluirObstaculo(p);

        // Plataforma 2
        p = new Entidades::Obstaculos::Plataforma(
            sf::Vector2f(595.f, 490.f),
            sf::Vector2f(280.f, 35.f),
            "ginger_brand/Plataforma.png",
            sf::Vector2f(0.f, 0.f),
            false);

        ListaEntFase.incluir(p);
        GC.incluirObstaculo(p);

        // Plataforma 3
        p = new Entidades::Obstaculos::Plataforma(
            sf::Vector2f(910.f, 385.f),
            sf::Vector2f(280.f, 35.f),
            "ginger_brand/Plataforma.png",
            sf::Vector2f(0.f, 0.f),
            false);

        ListaEntFase.incluir(p);
        GC.incluirObstaculo(p);

        // Plataforma 4
        p = new Entidades::Obstaculos::Plataforma(
            sf::Vector2f(490.f, 280.f),
            sf::Vector2f(210.f, 35.f),
            "ginger_brand/Plataforma.png",
            sf::Vector2f(0.f, 0.f),
            false);

        ListaEntFase.incluir(p);
        GC.incluirObstaculo(p);

        // Plataforma 5
        p = new Entidades::Obstaculos::Plataforma(
            sf::Vector2f(1015.f, 210.f),
            sf::Vector2f(210.f, 35.f),
            "ginger_brand/Plataforma.png",
            sf::Vector2f(0.f, 0.f),
            false);

        ListaEntFase.incluir(p);
        GC.incluirObstaculo(p);

        // Plataforma central alta
        p = new Entidades::Obstaculos::Plataforma(
            sf::Vector2f(735.f, 105.f),
            sf::Vector2f(280.f, 35.f),
            "ginger_brand/Plataforma.png",
            sf::Vector2f(0.f, 0.f),
            false);

        ListaEntFase.incluir(p);
        GC.incluirObstaculo(p);
    }
}
