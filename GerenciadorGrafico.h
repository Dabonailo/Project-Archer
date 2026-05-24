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

		static GerenciadorGrafico* pGrafico;
		GerenciadorGrafico();

	public:
		~GerenciadorGrafico();

		static GerenciadorGrafico* getGerenciadorGrafico();
		sf::RenderWindow* getWindow();

		void fecharJanela();
		const bool verificaJanelaAberta();

		void desenharEnte(Ente* pE);
	};
}
