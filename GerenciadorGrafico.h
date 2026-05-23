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

	public:
		GerenciadorGrafico();
		~GerenciadorGrafico();

		sf::RenderWindow* getWindow();

		void fecharJanela();
		const bool verificaJanelaAberta();

		void desenharEnte(Ente* pE);
	};
}
