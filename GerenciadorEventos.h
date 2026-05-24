#pragma once

#include "GerenciadorGrafico.h"

namespace Entidades {
	class Jogador;
}

namespace Gerenciadores 
{
	class GerenciadorEventos
	{
	private:
		static GerenciadorGrafico* pGrafico;
		Entidades::Jogador* pJog;

		static GerenciadorEventos* pEventos;
		GerenciadorEventos();

	public:
		~GerenciadorEventos();

		static GerenciadorEventos* getGerenciadorEventos();
		
		void setJogador(Entidades::Jogador* pJ);

		void verificaTeclaPressionada(sf::Keyboard::Key tecla);
		void executar();

	};
}
