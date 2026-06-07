#pragma once
#include <vector>
#include <list>
#include <set>
#include "ListaEntidades.h"
#include "Jogador.h"
#include "Inimigo.h"
#include "Obstaculo.h"
#include "Projetil.h"

#define CHAO 700.f

namespace Gerenciadores
{
	class GerenciadorColisoes
	{
	private:
		Entidades::Personagens::Jogador* jogador1;
		Entidades::Personagens::Jogador* jogador2;
		std::vector<Entidades::Personagens::Inimigo*> LIs;
		std::list<Entidades::Obstaculos::Obstaculo*> LOs;
		std::set<Entidades::Projetil*> LPs;

	public:
		GerenciadorColisoes();
		~GerenciadorColisoes();

		const int getTamanhoLIs() const;
		const int getTamanhoLOs() const;

		const bool verificarColisao(Entidades::Entidade* pE1, Entidades::Entidade* pE2) const;

		void incluirJogadores(Entidades::Personagens::Jogador* pJ);
		void incluirInimigo(Entidades::Personagens::Inimigo* pI);
		void incluirObstaculo(Entidades::Obstaculos::Obstaculo* pO);
		void incluirProjetil(Entidades::Projetil* pPr);

		void tratarColisoesJogsInimigs();
		void tratarColisoesJogsObstacs();
		void tratarColisoesInimigsObstacs();
		void tratarColisaoChao(Entidades::Entidade* pEnt);
		void tratarColisaoEntsChao();

		void executar();

	};
}