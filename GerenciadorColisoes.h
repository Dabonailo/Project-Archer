#pragma once
#include <vector>
#include "ListaEntidades.h"
#include "Jogador.h"
#include "Inimigo.h"

namespace Gerenciadores
{
	class GerenciadorColisoes
	{
	private:
		Entidades::Personagens::Jogador* jogador1;
		Entidades::Personagens::Jogador* jogador2;
		std::vector<Entidades::Personagens::Inimigo*> LIs;

	public:
		GerenciadorColisoes();
		~GerenciadorColisoes();

		const int getTamanhoLIs() const;

		const bool verificarColisao(Entidades::Entidade* pE1, Entidades::Entidade* pE2) const;

		void incluirJogadores(Entidades::Personagens::Jogador* pJ);
		void incluirInimigo(Entidades::Personagens::Inimigo* pI);

		void tratarColisoesJogsInimigs();

		void executar();

	};
}