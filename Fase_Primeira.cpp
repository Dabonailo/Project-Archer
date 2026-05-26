#include "Fase_Primeira.h"

namespace Fases
{
	Fase_Primeira::Fase_Primeira() : Fase(), max_inimigos(1)
	{
        criarInimigos();
        criarObstaculos();
	}

	Fase_Primeira::~Fase_Primeira()
	{
	}

	void Fase_Primeira::adicionarJogador(Entidades::Personagens::Jogador* p)
	{
		ListaEntFase.incluir(p);
		GC.incluirJogadores(p);
	}

	void Fase_Primeira::criarInimigos()
	{
		criarInimgosFaceis();
	}

    void Fase_Primeira::criarInimgosFaceis()
    {
        Entidades::Personagens::Inimigo_facil* inimigo1 = new Entidades::Personagens::Inimigo_facil();
        inimigo1->setPosicao(sf::Vector2f(600.f, 200.f));
        ListaEntFase.incluir(inimigo1);
        GC.incluirInimigo(inimigo1);
    }

    void Fase_Primeira::criarObstaculos()
    {

        Entidades::Obstaculos::Plataforma* plataforma1 =
            new Entidades::Obstaculos::Plataforma(
                sf::Vector2f(220.f, 180.f),
                sf::Vector2f(200.f, 40.f),
                "",
                sf::Vector2f(0.f, 0.f),
                false
            );

        ListaEntFase.incluir(plataforma1);
        GC.incluirObstaculo(plataforma1);

        Entidades::Obstaculos::Plataforma* plataforma2 =
            new Entidades::Obstaculos::Plataforma(
                sf::Vector2f(370.f, 480.f),
                sf::Vector2f(220.f, 40.f),
                "",
                sf::Vector2f(0.f, 0.f),
                false
            );

        ListaEntFase.incluir(plataforma2);
        GC.incluirObstaculo(plataforma2);

        Entidades::Obstaculos::Plataforma* plataforma3 =
            new Entidades::Obstaculos::Plataforma(
                sf::Vector2f(590.f, 340.f),
                sf::Vector2f(260.f, 50.f),
                "",
                sf::Vector2f(0.f, 0.f),
                false
            );

        ListaEntFase.incluir(plataforma3);
        GC.incluirObstaculo(plataforma3);
    }

	void Fase_Primeira::executar()
	{
		ListaEntFase.percorrerLista();
		GC.executar();
	}
}
