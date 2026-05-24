#pragma once

#include "GerenciadorGrafico.h"
#include "Jogador.h"

namespace Gerenciadores 
{
	class GerenciadorEventos
	{
	private:
		static GerenciadorGrafico* pGrafico;
		Entidades::Personagens::Jogador* pJog;

		static GerenciadorEventos* pEventos;
		GerenciadorEventos();

	public:
		~GerenciadorEventos();

		static GerenciadorEventos* getGerenciadorEventos();
		
		void setJogador(Entidades::Personagens::Jogador* pJ);

		void verificaTeclaPressionada(sf::Keyboard::Key tecla);
		void executar();

	};
}
