#include "Fase_Primeira.h"

namespace Fases
{
	Fase_Primeira::Fase_Primeira(Entidades::Personagens::Jogador* pJ, Entidades::Personagens::Jogador* pJ2, 
        sf::Vector2f pos, sf::Vector2f tam, const std::string& textura) : 
        Fase(pJ, pJ2, pos, tam, textura), max_inimigos(1)
	{
        criarInimigos();
        criarObstaculos();
        criarProjeteis();
	}

	Fase_Primeira::~Fase_Primeira()
	{
	}

	void Fase_Primeira::criarInimigos()
	{
		criarInimgosFaceis();
        criarInimgosMedios();
	}

    void Fase_Primeira::criarInimgosMedios()
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
 
 

     void Fase_Primeira::criarEspinhos()
     {
         Entidades::Obstaculos::Espinho* esp;

         esp = new Entidades::Obstaculos::Espinho();
         esp->setPosicao(sf::Vector2f(280.f, 455.f));
         ListaEntFase.incluir(esp);
         GC.incluirObstaculo(esp);

         esp = new Entidades::Obstaculos::Espinho();
         esp->setPosicao(sf::Vector2f(315.f, 455.f));
         ListaEntFase.incluir(esp);
         GC.incluirObstaculo(esp);

         // Grupo fixo 2 (2 espinhos)
         esp = new Entidades::Obstaculos::Espinho();
         esp->setPosicao(sf::Vector2f(580.f, 315.f));
         ListaEntFase.incluir(esp);
         GC.incluirObstaculo(esp);

         esp = new Entidades::Obstaculos::Espinho();
         esp->setPosicao(sf::Vector2f(615.f, 315.f));
         ListaEntFase.incluir(esp);
         GC.incluirObstaculo(esp);

         // Grupo fixo 3 (3 espinhos)
         esp = new Entidades::Obstaculos::Espinho();
         esp->setPosicao(sf::Vector2f(885.f, 455.f));
         ListaEntFase.incluir(esp);
         GC.incluirObstaculo(esp);

         esp = new Entidades::Obstaculos::Espinho();
         esp->setPosicao(sf::Vector2f(920.f, 455.f));
         ListaEntFase.incluir(esp);
         GC.incluirObstaculo(esp);

         esp = new Entidades::Obstaculos::Espinho();
         esp->setPosicao(sf::Vector2f(955.f, 455.f));
         ListaEntFase.incluir(esp);
         GC.incluirObstaculo(esp);

         // Opção A (1 espinho)
         if (rand() % 2 == 0)
         {
             esp = new Entidades::Obstaculos::Espinho();
             esp->setPosicao(sf::Vector2f(700.f, 645.f));
             ListaEntFase.incluir(esp);
             GC.incluirObstaculo(esp);

             esp = new Entidades::Obstaculos::Espinho();
             esp->setPosicao(sf::Vector2f(735.f, 645.f));
             ListaEntFase.incluir(esp);
             GC.incluirObstaculo(esp);

             esp = new Entidades::Obstaculos::Espinho();
             esp->setPosicao(sf::Vector2f(770.f, 645.f));
             ListaEntFase.incluir(esp);
             GC.incluirObstaculo(esp);
         }

         // Opção B (2 espinhos)
         if (rand() % 2 == 0)
         {
             esp = new Entidades::Obstaculos::Espinho();
             esp->setPosicao(sf::Vector2f(1180.f, 645.f));
             ListaEntFase.incluir(esp);
             GC.incluirObstaculo(esp);
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
        criarEspinhos();
	}

    void Fase_Primeira::executar()
    {  
        Ente::desenhar();

        ListaEntFase.percorrerLista();
        GC.executar();
        atualizalJogs();
    }

}
