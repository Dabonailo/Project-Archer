#include "Fase_segunda.h"

namespace Fases {

	Fases::Fase_segunda::Fase_segunda(Entidades::Personagens::Jogador* pJ, Entidades::Personagens::Jogador* pJ2,
		sf::Vector2f pos, sf::Vector2f tam, const std::string& textura, int _id, bool carregando) :

        Fase(pJ, pJ2, pos, tam, textura, _id),
        maxChefoes(rand()%5),
        vecNinja()
    {
        if (carregando)
        {
            carregarFase();
        }
        else
        {
            criarCenario();
            criarProjeteis();
        }
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
        Entidades::Personagens::Ninja* ninja = new Entidades::Personagens::Ninja(sf::Vector2f(1400.f, 660.f));
        ninja->setListaJogadores(&lJogs);
        ListaEntFase.incluir(ninja);
        GC.incluirInimigo(ninja);
        vecNinja.push_back(ninja);

        ninja = new Entidades::Personagens::Ninja(sf::Vector2f(1150.f, 660.f));
        ninja->setListaJogadores(&lJogs);
        ListaEntFase.incluir(ninja);
        GC.incluirInimigo(ninja);
        vecNinja.push_back(ninja);

        ninja = new Entidades::Personagens::Ninja(sf::Vector2f(1075.f, 500.f));
        ninja->setListaJogadores(&lJogs);
        ListaEntFase.incluir(ninja);
        GC.incluirInimigo(ninja);
        vecNinja.push_back(ninja);

        if(maxChefoes > 2)
        {
            ninja = new Entidades::Personagens::Ninja(sf::Vector2f(700.f, 820.f));
            ninja->setListaJogadores(&lJogs);
            ListaEntFase.incluir(ninja);
            GC.incluirInimigo(ninja);
            vecNinja.push_back(ninja);
        }

        if (maxChefoes > 3)
        {
           ninja = new Entidades::Personagens::Ninja(sf::Vector2f(1200.f, 820.f));
            ninja->setListaJogadores(&lJogs);
            ListaEntFase.incluir(ninja);
            GC.incluirInimigo(ninja);
            vecNinja.push_back(ninja);
        }
	}

    void Fase_segunda::criarObstaculos()
    {

        Entidades::Obstaculos::Plataforma* p;

        criarPlataformas();
        p = new Entidades::Obstaculos::Plataforma(
            sf::Vector2f(600.f, 575.f),
            sf::Vector2f(150.f, 35.f),
            "ginger_brand/Plataforma.png",
            sf::Vector2f(0.f, 0.f),
            false);

		p->setSeMove(true);

        ListaEntFase.incluir(p);
        GC.incluirObstaculo(p);
		criarEspinhos();

        p = new Entidades::Obstaculos::Plataforma(
            sf::Vector2f(850.f, 725.f),
            sf::Vector2f(150.f, 35.f),
            "ginger_brand/Plataforma.png",
            sf::Vector2f(0.f, 0.f),
            false);

        p->setSeMove(true);

        ListaEntFase.incluir(p);
        GC.incluirObstaculo(p);
        criarEspinhos();
    }

    void Fase_segunda::criarEspinhos()
    {
        Entidades::Obstaculos::Espinho* esp;

        esp = new Entidades::Obstaculos::Espinho(sf::Vector2f(280.f, 717.f), sf::Vector2f(75.f,35.f));
        ListaEntFase.incluir(esp);
        GC.incluirObstaculo(esp);

        esp = new Entidades::Obstaculos::Espinho(sf::Vector2f(1250.f, 692.f), sf::Vector2f(75.f, 35.f));
        ListaEntFase.incluir(esp);
        GC.incluirObstaculo(esp);

        esp = new Entidades::Obstaculos::Espinho(sf::Vector2f(900.f, 542.f), sf::Vector2f(75.f, 35.f));
        ListaEntFase.incluir(esp);
        GC.incluirObstaculo(esp);


        if (rand() % 2 == 0)
        {
            esp = new Entidades::Obstaculos::Espinho(sf::Vector2f(975.f, 857.f), sf::Vector2f(75.f, 35.f));
            ListaEntFase.incluir(esp);
            GC.incluirObstaculo(esp);
        }

        if (rand() % 2 == 0)
        {
            esp = new Entidades::Obstaculos::Espinho(sf::Vector2f(425.f, 857.f), sf::Vector2f(75.f, 35.f));
            ListaEntFase.incluir(esp);
            GC.incluirObstaculo(esp);
        }
    }

	

    void Fase_segunda::criarProjeteis()
    {
        Entidades::Projetil* novoProjetilJogador = new Entidades::Projetil();

        pJogador->setProjetil(novoProjetilJogador);
        novoProjetilJogador->setPersonagem(pJogador);
		novoProjetilJogador->setUIdDono(pJogador->getUid());

        ListaEntFase.incluir(novoProjetilJogador);
        GC.incluirProjetil(novoProjetilJogador);

        if (pJogador2) {
            Entidades::Projetil* novoProjetilJogador2 = new Entidades::Projetil();

            pJogador2->setProjetil(novoProjetilJogador2);
            novoProjetilJogador2->setPersonagem(pJogador2);
			novoProjetilJogador2->setUIdDono(pJogador2->getUid());

            ListaEntFase.incluir(novoProjetilJogador2);
            GC.incluirProjetil(novoProjetilJogador2);
        }

        for (std::vector<Entidades::Personagens::Ninja*>::iterator it = vecNinja.begin(); it != vecNinja.end(); ++it) {
            Entidades::Projetil* novoProjetilNinja = new Entidades::Projetil();

            (*it)->setProjetil(novoProjetilNinja);
            novoProjetilNinja->setPersonagem(*it);
			novoProjetilNinja->setUIdDono((*it)->getUid());

            ListaEntFase.incluir(novoProjetilNinja);
            GC.incluirProjetil(novoProjetilNinja);
        }
    }
}