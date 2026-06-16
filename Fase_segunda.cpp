#include "Fase_segunda.h"

namespace Fases {

	Fases::Fase_segunda::Fase_segunda(Entidades::Personagens::Jogador* pJ, Entidades::Personagens::Jogador* pJ2,
		sf::Vector2f pos, sf::Vector2f tam, const std::string& textura): Fase(pJ, pJ2, pos, tam, textura), maxchefoes(5)
	{
        criarInimigos();
        criarProjeteis();
	}

	Fase_segunda::~Fase_segunda()
	{
	}

	void Fase_segunda::criarInimigos()
	{
        criarInimgosFaceis();
        criarNinjas();
	}

	void Fase_segunda::criarNinjas()
	{
        Entidades::Personagens::Ninja* ninja = new Entidades::Personagens::Ninja();
        ninja->setPosicao(sf::Vector2f(440.f, 680.f));
        ninja->setListaJogadores(&lJogs);
        ListaEntFase.incluir(ninja);
        GC.incluirInimigo(ninja);
	}

    void Fase_segunda::criarObstaculos()
    {
    }

	void Fase_segunda::criarEspinhos() 
    {
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
    }
}