#include "Fase_Primeira.h"

namespace Fases
{
	Fase_Primeira::Fase_Primeira(Entidades::Personagens::Jogador* pJ, Entidades::Personagens::Jogador* pJ2, 
        sf::Vector2f pos, sf::Vector2f tam, const std::string& textura) : 
        Fase(pJ, pJ2, pos, tam, textura), max_inimigos(1)
	{
		criarCenario();
        criarProjeteis();
	}

	Fase_Primeira::~Fase_Primeira()
	{
	}

	void Fase_Primeira::criarInimigos()
	{
		criarOnis();
        criarDragoes();
	}

    void Fase_Primeira::criarDragoes()
    {
        Entidades::Personagens::Dragao* inimigo;
        inimigo = new Entidades::Personagens::Dragao(sf::Vector2f(180.f, 150.f));
        inimigo->setListaJogadores(&lJogs);
        ListaEntFase.incluir(inimigo);
        GC.incluirInimigo(inimigo);

        inimigo = new Entidades::Personagens::Dragao(sf::Vector2f(480.f, 110.f));
        inimigo->setListaJogadores(&lJogs);
        ListaEntFase.incluir(inimigo);
        GC.incluirInimigo(inimigo);

        inimigo = new Entidades::Personagens::Dragao(sf::Vector2f(700.f, 180.f));
        inimigo->setListaJogadores(&lJogs);
        ListaEntFase.incluir(inimigo);
        GC.incluirInimigo(inimigo);

        if (rand() % 2 == 0)
        {
            inimigo = new Entidades::Personagens::Dragao(sf::Vector2f(960.f, 120.f));
            inimigo->setListaJogadores(&lJogs);
            ListaEntFase.incluir(inimigo);
            GC.incluirInimigo(inimigo);
        }

        if (rand() % 2 == 0)
        {
            inimigo = new Entidades::Personagens::Dragao(sf::Vector2f(1120.f, 250.f));
            inimigo->setListaJogadores(&lJogs);
            ListaEntFase.incluir(inimigo);
            GC.incluirInimigo(inimigo);
        }
    }
 
    void Fase_Primeira::criarBlocosMagma()
    {
        Entidades::Obstaculos::Magma_Block* p =
            new Entidades::Obstaculos::Magma_Block(
                sf::Vector2f(525.f, 525.f),
                sf::Vector2f(250.f, 35.f),
                "ginger_brand/Magma_Block.png",
                sf::Vector2f(0.f, 0.f),
                false);

        ListaEntFase.incluir(p);
        GC.incluirObstaculo(p);

        p = new Entidades::Obstaculos::Magma_Block(
            sf::Vector2f(1325.f, 475.f),
            sf::Vector2f(200.f, 35.f),
            "ginger_brand/Magma_Block.png",
            sf::Vector2f(0.f, 0.f),
            false);

        ListaEntFase.incluir(p);
        GC.incluirObstaculo(p);

        p = new Entidades::Obstaculos::Magma_Block(
            sf::Vector2f(1050.f, 325.f),
            sf::Vector2f(250.f, 35.f),
            "ginger_brand/Magma_Block.png",
            sf::Vector2f(0.f, 0.f),
            false);

        ListaEntFase.incluir(p);
        GC.incluirObstaculo(p);

		if (rand() % 2 == 0)
        {
            p = new Entidades::Obstaculos::Magma_Block(
                sf::Vector2f(200.f, 325.f),
                sf::Vector2f(150.f, 35.f),
                "ginger_brand/Magma_Block.png",
                sf::Vector2f(0.f, 0.f),
                false);

            ListaEntFase.incluir(p);
            GC.incluirObstaculo(p);
        }

        if (rand() % 2 == 0)
        {
            p = new Entidades::Obstaculos::Magma_Block(
                sf::Vector2f(100.f, 150.f),
                sf::Vector2f(200.f, 35.f),
                "ginger_brand/Magma_Block.png",
                sf::Vector2f(0.f, 0.f),
                false);

            ListaEntFase.incluir(p);
            GC.incluirObstaculo(p);
        }
    }

    

     void Fase_Primeira::criarProjeteis()
     {
         Entidades::Projetil* novoProjetilJogador = new Entidades::Projetil();

         pJogador->setProjetil(novoProjetilJogador);
         novoProjetilJogador->setPersonagem(pJogador);

         ListaEntFase.incluir(novoProjetilJogador);
         GC.incluirProjetil(novoProjetilJogador);

         if (pJogador2) {
             Entidades::Projetil* novoProjetilJogador2 = new Entidades::Projetil();

             pJogador2->setProjetil(novoProjetilJogador2);
             novoProjetilJogador2->setPersonagem(pJogador2);

             ListaEntFase.incluir(novoProjetilJogador2);
             GC.incluirProjetil(novoProjetilJogador2);
         }
     }

    void Fase_Primeira::criarObstaculos()
    {
        criarPlataformas();

        Entidades::Obstaculos::Plataforma* p;

        if(rand() % 2 == 0)
        {
                p = new Entidades::Obstaculos::Plataforma(
                    sf::Vector2f(120.f, 475.f),
                    sf::Vector2f(150.f, 35.f),
                    "ginger_brand/Plataforma.png",
                    sf::Vector2f(0.f, 0.f),
                    false);

            ListaEntFase.incluir(p);
            GC.incluirObstaculo(p);
        }

        if (rand() % 2 == 0)
        {
            p = new Entidades::Obstaculos::Plataforma(
                sf::Vector2f(1400.f, 250.f),
                sf::Vector2f(150.f, 35.f),
                "ginger_brand/Plataforma.png",
                sf::Vector2f(0.f, 0.f),
                false);


            ListaEntFase.incluir(p);
            GC.incluirObstaculo(p);
        }

        p = new Entidades::Obstaculos::Plataforma(
            sf::Vector2f(750.f, 225.f),
            sf::Vector2f(250.f, 35.f),
            "ginger_brand/Plataforma.png",
            sf::Vector2f(0.f, 0.f),
            false);


        ListaEntFase.incluir(p);
        GC.incluirObstaculo(p);
        criarBlocosMagma();
	}
}
