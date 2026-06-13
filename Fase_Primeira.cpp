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

        if (rand() % 9 == 0)
        {
            inimigo = new Entidades::Personagens::Dragao(sf::Vector2f(210.f, 420.f));
            inimigo->setListaJogadores(&lJogs);
            ListaEntFase.incluir(inimigo);
            GC.incluirInimigo(inimigo);
        }

        inimigo = new Entidades::Personagens::Dragao(sf::Vector2f(595.f, 315.f));
        inimigo->setListaJogadores(&lJogs);
        ListaEntFase.incluir(inimigo);
        GC.incluirInimigo(inimigo);

        inimigo = new Entidades::Personagens::Dragao(sf::Vector2f(910.f, 210.f));
        inimigo->setListaJogadores(&lJogs);
        ListaEntFase.incluir(inimigo);
        GC.incluirInimigo(inimigo);

        inimigo = new Entidades::Personagens::Dragao(sf::Vector2f(420.f, 105.f));
        inimigo->setListaJogadores(&lJogs);
        ListaEntFase.incluir(inimigo);
        GC.incluirInimigo(inimigo);

        inimigo = new Entidades::Personagens::Dragao(sf::Vector2f(1085.f, 105.f));
        inimigo->setListaJogadores(&lJogs);
        ListaEntFase.incluir(inimigo);
        GC.incluirInimigo(inimigo);
    }
 
     

     void Fase_Primeira::criarEspinhos()
     {
         Entidades::Obstaculos::Espinho* esp;

         // Grupo 1
         esp = new Entidades::Obstaculos::Espinho();
         esp->setPosicao(sf::Vector2f(385.f, 642.f));
         ListaEntFase.incluir(esp);
         GC.incluirObstaculo(esp);

         esp = new Entidades::Obstaculos::Espinho();
         esp->setPosicao(sf::Vector2f(420.f, 642.f));
         ListaEntFase.incluir(esp);
         GC.incluirObstaculo(esp);

         // Grupo 2
         esp = new Entidades::Obstaculos::Espinho();
         esp->setPosicao(sf::Vector2f(735.f, 642.f));
         ListaEntFase.incluir(esp);
         GC.incluirObstaculo(esp);

         esp = new Entidades::Obstaculos::Espinho();
         esp->setPosicao(sf::Vector2f(770.f, 642.f));
         ListaEntFase.incluir(esp);
         GC.incluirObstaculo(esp);

         // Grupo 3
         esp = new Entidades::Obstaculos::Espinho();
         esp->setPosicao(sf::Vector2f(1120.f, 642.f));
         ListaEntFase.incluir(esp);
         GC.incluirObstaculo(esp);

         esp = new Entidades::Obstaculos::Espinho();
         esp->setPosicao(sf::Vector2f(1155.f, 642.f));
         ListaEntFase.incluir(esp);
         GC.incluirObstaculo(esp);
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
    }

}
