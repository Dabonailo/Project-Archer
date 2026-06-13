#pragma once

#include "GerenciadorGrafico.h"
#include "Jogador.h"
#include "Menu.h"

namespace Gerenciadores 
{
	class GerenciadorEventos
	{
	private:
		static GerenciadorGrafico* pGrafico;
		Entidades::Personagens::Jogador* pJog;
		Entidades::Personagens::Jogador* pJog2;
		Menu* menu;

		static GerenciadorEventos* pEventos;
		GerenciadorEventos();

	public:
		~GerenciadorEventos();

		static GerenciadorEventos* getGerenciadorEventos();
		
		void setJogador(Entidades::Personagens::Jogador* pJ);
		void setMenu(Menu* m);

		void verificaTeclaPressionada(sf::Keyboard::Key tecla);
		void verificaTeclaSolta(sf::Keyboard::Key tecla);

		void executar();

	};
}
