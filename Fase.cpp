#include "Fase.h"

namespace Fases {
	Fase::Fase(Entidades::Personagens::Jogador* pJ, Entidades::Personagens::Jogador* pJ2,
        sf::Vector2f pos, sf::Vector2f tam, const std::string& textura):
        Ente(pos == sf::Vector2f(0.f, 0.f) ? pGG->getWindowCentro() : pos,
            tam == sf::Vector2f(0.f, 0.f) ? pGG->getWindowTam() : tam, textura), ListaEntFase(), GC(), 
        pJogador(NULL), pJogador2(NULL)
    {
        body.setFillColor(sf::Color(255, 255, 255, 150));

        ListaEntFase.incluir(pJ);
        lJogs.incluir(pJ);
        GC.incluirJogadores(pJ);
        pJogador = pJ;

        if (pJ2) {
            ListaEntFase.incluir(pJ2);
            lJogs.incluir(pJ2);
            GC.incluirJogadores(pJ2);
            pJogador2 = pJ2;
        }
    }

	Fase::~Fase() {}

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
        Entidades::Personagens::Inimigo_facil* inimigo;

        if (rand() % 2 == 0)
        {
            inimigo = new Entidades::Personagens::Inimigo_facil();
            inimigo->setPosicao(sf::Vector2f(280.f, 560.f));
            inimigo->setListaJogadores(&lJogs);
            ListaEntFase.incluir(inimigo);
            GC.incluirInimigo(inimigo);
        }


        inimigo = new Entidades::Personagens::Inimigo_facil();
        inimigo->setPosicao(sf::Vector2f(560.f, 455.f));
        inimigo->setListaJogadores(&lJogs);
        ListaEntFase.incluir(inimigo);
        GC.incluirInimigo(inimigo);

        inimigo = new Entidades::Personagens::Inimigo_facil();
        inimigo->setPosicao(sf::Vector2f(875.f, 350.f));
        inimigo->setListaJogadores(&lJogs);
        ListaEntFase.incluir(inimigo);
        GC.incluirInimigo(inimigo);

        inimigo = new Entidades::Personagens::Inimigo_facil();
        inimigo->setPosicao(sf::Vector2f(490.f, 245.f));
        inimigo->setListaJogadores(&lJogs);
        ListaEntFase.incluir(inimigo);
        GC.incluirInimigo(inimigo);

        if (rand() % 2 == 0)
        {
            inimigo = new Entidades::Personagens::Inimigo_facil();
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
