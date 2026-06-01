#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

#include "Ente.h"
namespace Gerenciadores
{
	class GerenciadorGrafico
	{
	private:
		sf::RenderWindow* window;

		sf::Clock relogio;
		float tempo;

		static GerenciadorGrafico* pGrafico;
		GerenciadorGrafico();

	public:
		~GerenciadorGrafico();

		static GerenciadorGrafico* getGerenciadorGrafico();
		sf::RenderWindow* getWindow();
		sf::Vector2f getWindowTam();

		float getTempo();
		void resetarRelogio();

		void fecharJanela();
		const bool verificaJanelaAberta();

		void desenharEnte(Ente* pE);
	};
}
