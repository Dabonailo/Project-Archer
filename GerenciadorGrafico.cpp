#include "GerenciadorGrafico.h"

namespace Gerenciadores
{
	GerenciadorGrafico* GerenciadorGrafico::pGrafico = NULL;

	GerenciadorGrafico::GerenciadorGrafico() :
		window(new sf::RenderWindow(sf::VideoMode(1250, 750), "Project Archers")), relogio(), tempo(0.f)
	{
		if (window == NULL)
		{
			std::cout << "Erro ao criar janela!";
			exit(1);
		}
	}

	GerenciadorGrafico::~GerenciadorGrafico()
	{
		if (window)
		{
			delete(window);
			window = NULL;
		}
	}

	GerenciadorGrafico* GerenciadorGrafico::getGerenciadorGrafico()
	{
		if (pGrafico == NULL) {
			pGrafico = new GerenciadorGrafico();
		}
		return pGrafico;
	}

	sf::RenderWindow* GerenciadorGrafico::getWindow()
	{
		return window;
	}

	sf::Vector2f GerenciadorGrafico::getWindowTam()
	{
		return sf::Vector2f(getWindow()->getSize().x, getWindow()->getSize().y);
	}

	float GerenciadorGrafico::getTempo()
	{
		return tempo;
	}

	void GerenciadorGrafico::resetarRelogio()
	{
		tempo = relogio.getElapsedTime().asSeconds();
		relogio.restart();
	}

	void GerenciadorGrafico::fecharJanela()
	{
		window->close();
	}

	const bool GerenciadorGrafico::verificaJanelaAberta()
	{
		if (window->isOpen())
			return true;

		return false;
	}

	void GerenciadorGrafico::desenharEnte(Ente* pE)
	{
		window->draw(pE->getBody());
	}

	void GerenciadorGrafico::desenharAtaque(const sf::RectangleShape* ataque)
	{
		window->draw(*ataque);
		std::cout << "desenhou ataque" << std::endl;
	}

}