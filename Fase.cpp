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
        Entidades::Personagens::Oni* inimigo;

        inimigo = new Entidades::Personagens::Oni();
        inimigo->setPosicao(sf::Vector2f(440.f, 680.f));
        inimigo->setListaJogadores(&lJogs);
        ListaEntFase.incluir(inimigo);
        GC.incluirInimigo(inimigo);

        inimigo = new Entidades::Personagens::Oni();
        inimigo->setPosicao(sf::Vector2f(350.f, 420.f));
        inimigo->setListaJogadores(&lJogs);
        ListaEntFase.incluir(inimigo);
        GC.incluirInimigo(inimigo);

        inimigo = new Entidades::Personagens::Oni();
        inimigo->setPosicao(sf::Vector2f(630.f, 680.f));
        inimigo->setListaJogadores(&lJogs);
        ListaEntFase.incluir(inimigo);
        GC.incluirInimigo(inimigo);

        if (rand() % 2 == 0)
        {
            inimigo = new Entidades::Personagens::Oni();
            inimigo->setPosicao(sf::Vector2f(910.f, 350.f));
            inimigo->setListaJogadores(&lJogs);
            ListaEntFase.incluir(inimigo);
            GC.incluirInimigo(inimigo);
        }
        
        if (rand() % 2 == 0)
        {
            inimigo = new Entidades::Personagens::Oni();
            inimigo->setPosicao(sf::Vector2f(1120.f, 680.f));
            inimigo->setListaJogadores(&lJogs);
            ListaEntFase.incluir(inimigo);
            GC.incluirInimigo(inimigo);
        }
    }

    void Fase::criarPlataformas()
    {
        // Plataforma fixa 1
        Entidades::Obstaculos::Plataforma* p =
            new Entidades::Obstaculos::Plataforma(
                sf::Vector2f(280.f, 490.f),
                sf::Vector2f(210.f, 35.f),
                "ginger_brand/Plataforma.png",
                sf::Vector2f(0.f, 0.f),
                false);

        ListaEntFase.incluir(p);
        GC.incluirObstaculo(p);

        // Plataforma fixa 2
        p = new Entidades::Obstaculos::Plataforma(
            sf::Vector2f(560.f, 350.f),
            sf::Vector2f(245.f, 35.f),
            "ginger_brand/Plataforma.png",
            sf::Vector2f(0.f, 0.f),
            false);

        ListaEntFase.incluir(p);
        GC.incluirObstaculo(p);

        // Plataforma fixa 3
        p = new Entidades::Obstaculos::Plataforma(
            sf::Vector2f(900.f, 490.f),
            sf::Vector2f(210.f, 35.f),
            "ginger_brand/Plataforma.png",
            sf::Vector2f(0.f, 0.f),
            false);

        ListaEntFase.incluir(p);
        GC.incluirObstaculo(p);

		if (rand() % 2 == 0)
        {

            p = new Entidades::Obstaculos::Plataforma(
                sf::Vector2f(175.f, 245.f),
                sf::Vector2f(210.f, 35.f),
                "ginger_brand/Plataforma.png",
                sf::Vector2f(0.f, 0.f),
                false);

            ListaEntFase.incluir(p);
            GC.incluirObstaculo(p);
        }

        // Opção B
        if (rand() % 2 == 0)
        {
            p = new Entidades::Obstaculos::Plataforma(
                sf::Vector2f(1030.f, 280.f),
                sf::Vector2f(175.f, 35.f),
                "ginger_brand/Plataforma.png",
                sf::Vector2f(0.f, 0.f),
                false);

            ListaEntFase.incluir(p);
            GC.incluirObstaculo(p);

        }
    }

    void Fase::atualizalJogs()
    {
        auto* atual = lJogs.getPrimeiro();

        while (atual)
        {
            auto* proximo = atual->getProximo();

            Entidades::Personagens::Jogador* pJog =
                dynamic_cast<Entidades::Personagens::Jogador*>(atual->getInfo());

            if (pJog && !pJog->getVivo())
            {
                lJogs.remover(atual->getInfo());
            }

            atual = proximo;
        }
    }
}
