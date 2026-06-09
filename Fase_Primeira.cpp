#include "Fase_Primeira.h"

namespace Fases
{
	Fase_Primeira::Fase_Primeira(sf::Vector2f pos, sf::Vector2f tam, const std::string& textura) : 
        Fase(pos, tam, textura), max_inimigos(1)
	{
        criarInimigos();
        criarObstaculos();
	}

	Fase_Primeira::~Fase_Primeira()
	{
	}

	void Fase_Primeira::criarInimigos()
	{
		criarInimgosFaceis();
        criarInimgosMedios();
	}

    void Fase_Primeira::criarInimgosFaceis()
    {
        Entidades::Personagens::Inimigo_facil* inimigo1 = new Entidades::Personagens::Inimigo_facil();
        inimigo1->setPosicao(sf::Vector2f(589.f, 300.f));
		inimigo1->setListaJogadores(&lJogs);
        ListaEntFase.incluir(inimigo1);
        GC.incluirInimigo(inimigo1);
    }

    void Fase_Primeira::criarInimgosMedios()
    {
        Entidades::Personagens::Inimigo_medio* inimigo1 = new Entidades::Personagens::Inimigo_medio(sf::Vector2f(1040.f, 150.f));
		inimigo1->setListaJogadores(&lJogs);
        ListaEntFase.incluir(inimigo1);
        GC.incluirInimigo(inimigo1);
	}

    void Fase_Primeira::criarPlataformas()
    {

        // Parede esquerda
        Entidades::Obstaculos::Plataforma* paredeEsq =
            new Entidades::Obstaculos::Plataforma(
                sf::Vector2f(-40.f, 350.f),
                sf::Vector2f(200.f, 700.f),
                "parede_tijolo.png",
                sf::Vector2f(0.f, 0.f),
                false);

        ListaEntFase.incluir(paredeEsq);
        GC.incluirObstaculo(paredeEsq);

        // Parede direita
        Entidades::Obstaculos::Plataforma* paredeDir =
            new Entidades::Obstaculos::Plataforma(
                sf::Vector2f(1270.f, 350.f),
                sf::Vector2f(200.f, 700.f),
                "parede_tijolo.png",
                sf::Vector2f(0.f, 0.f),
                false);

        ListaEntFase.incluir(paredeDir);
        GC.incluirObstaculo(paredeDir);

        // Plataforma 1
        Entidades::Obstaculos::Plataforma* p1 =
            new Entidades::Obstaculos::Plataforma(
                sf::Vector2f(250.f, 550.f),
                sf::Vector2f(250.f, 25.f),
                "ginger_brand/Plataforma.png",
                sf::Vector2f(0.f, 0.f),
                false);

        ListaEntFase.incluir(p1);
        GC.incluirObstaculo(p1);

        // Plataforma 2
        Entidades::Obstaculos::Plataforma* p2 =
            new Entidades::Obstaculos::Plataforma(
                sf::Vector2f(600.f, 450.f),
                sf::Vector2f(250.f, 25.f),
                "ginger_brand/Plataforma.png",
                sf::Vector2f(0.f, 0.f),
                false);

        ListaEntFase.incluir(p2);
        GC.incluirObstaculo(p2);

        // Plataforma 3
        Entidades::Obstaculos::Plataforma* p3 =
            new Entidades::Obstaculos::Plataforma(
                sf::Vector2f(950.f, 325.f),
                sf::Vector2f(300.f, 25.f),
                "ginger_brand/Plataforma.png",
                sf::Vector2f(0.f, 0.f),
                false);

        ListaEntFase.incluir(p3);
        GC.incluirObstaculo(p3);

        // Plataforma central inferior
        Entidades::Obstaculos::Plataforma* p4 =
            new Entidades::Obstaculos::Plataforma(
                sf::Vector2f(650.f, 570.f),
                sf::Vector2f(200.f, 25.f),
                "ginger_brand/Plataforma.png",
                sf::Vector2f(0.f, 0.f),
                false);

        ListaEntFase.incluir(p4);
        GC.incluirObstaculo(p4);

        // Plataforma superior direita
        Entidades::Obstaculos::Plataforma* p5 =
            new Entidades::Obstaculos::Plataforma(
                sf::Vector2f(1050.f, 180.f),
                sf::Vector2f(150.f, 25.f),
                "ginger_brand/Plataforma.png",
                sf::Vector2f(0.f, 0.f),
                false);

        ListaEntFase.incluir(p5);
        GC.incluirObstaculo(p5);
    }

    void Fase_Primeira::criarEspinhos()
    {
        Entidades::Obstaculos::Espinho* esp;

        esp = new Entidades::Obstaculos::Espinho(sf::Vector2f(550.f, 635.f),
            sf::Vector2f(ESPINHO_TAM_DEFAULT_X, ESPINHO_TAM_DEFAULT_Y),
            "espinhos.png",
            sf::Vector2f(0.f, 0.f),
            true);
        
        ListaEntFase.incluir(esp);
        GC.incluirObstaculo(esp);

        esp = new Entidades::Obstaculos::Espinho(sf::Vector2f(600.f, 635.f), sf::Vector2f(ESPINHO_TAM_DEFAULT_X, ESPINHO_TAM_DEFAULT_Y),
            "espinhos.png",
            sf::Vector2f(0.f, 0.f),
            true);
        ListaEntFase.incluir(esp);
        GC.incluirObstaculo(esp);

        esp = new Entidades::Obstaculos::Espinho(sf::Vector2f(650.f, 635.f), sf::Vector2f(ESPINHO_TAM_DEFAULT_X, ESPINHO_TAM_DEFAULT_Y),
            "espinhos.png",
            sf::Vector2f(0.f, 0.f),
            true);
        ListaEntFase.incluir(esp);
        GC.incluirObstaculo(esp);

        esp = new Entidades::Obstaculos::Espinho(sf::Vector2f(700.f, 635.f), sf::Vector2f(ESPINHO_TAM_DEFAULT_X, ESPINHO_TAM_DEFAULT_Y),
            "espinhos.png",
            sf::Vector2f(0.f, 0.f),
            true);
        ListaEntFase.incluir(esp);
        GC.incluirObstaculo(esp);


        // Espinhos próximos ao início
        esp = new Entidades::Obstaculos::Espinho();
        esp->setPosicao(sf::Vector2f(250.f, 635.f));
        ListaEntFase.incluir(esp);
        GC.incluirObstaculo(esp);

        esp = new Entidades::Obstaculos::Espinho();
        esp->setPosicao(sf::Vector2f(300.f, 635.f));
        ListaEntFase.incluir(esp);
        GC.incluirObstaculo(esp);


        // Espinhos próximos ao final
        esp = new Entidades::Obstaculos::Espinho();
        esp->setPosicao(sf::Vector2f(1050.f, 635.f));
        ListaEntFase.incluir(esp);
        GC.incluirObstaculo(esp);

        esp = new Entidades::Obstaculos::Espinho();
        esp->setPosicao(sf::Vector2f(1100.f, 635.f));
        ListaEntFase.incluir(esp);
        GC.incluirObstaculo(esp);
	}

    void Fase_Primeira::criarObstaculos()
    {
        criarPlataformas();
        criarEspinhos();
	}

    void Fase_Primeira::executar()
    {  
        Ente::desenhar();

        criarProjetilJogador();
        ListaEntFase.percorrerLista();
        GC.executar();
    }

}
