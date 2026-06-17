#include "Fase_segunda.h"

namespace Fases {

	Fases::Fase_segunda::Fase_segunda(Entidades::Personagens::Jogador* pJ, Entidades::Personagens::Jogador* pJ2,
		sf::Vector2f pos, sf::Vector2f tam, const std::string& textura): Fase(pJ, pJ2, pos, tam, textura), 
        maxchefoes(5), vecNinja()
	{
        criarCenario();
        criarProjeteis();
	}

	Fase_segunda::~Fase_segunda()
	{
	}

	void Fase_segunda::criarInimigos()
	{
        criarOnis();
        criarNinjas();
	}

	void Fase_segunda::criarNinjas()
	{
        Entidades::Personagens::Ninja* ninja = new Entidades::Personagens::Ninja(sf::Vector2f(440.f, 680.f));
        ninja->setListaJogadores(&lJogs);
        ListaEntFase.incluir(ninja);
        GC.incluirInimigo(ninja);
        vecNinja.push_back(ninja);
	}

    void Fase_segunda::criarObstaculos()
    {
        criarPlataformas();
		criarEspinhos();
    }

    void Fase_segunda::criarEspinhos()
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

	

    void Fase_segunda::criarProjeteis()
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

        for (std::vector<Entidades::Personagens::Ninja*>::iterator it = vecNinja.begin(); it != vecNinja.end(); ++it) {
            Entidades::Projetil* novoProjetilNinja = new Entidades::Projetil();

            (*it)->setProjetil(novoProjetilNinja);
            novoProjetilNinja->setPersonagem(*it);

            ListaEntFase.incluir(novoProjetilNinja);
            GC.incluirProjetil(novoProjetilNinja);
        }
    }
}