#include "GerenciadorGrafico.h"

GerenciadorGrafico* GerenciadorGrafico::pGrafico = nullptr;


GerenciadorGrafico::GerenciadorGrafico() :
	window(new sf::RenderWindow(sf::VideoMode(500, 500), "Project Archers"))
{
	if (window == nullptr)
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
		window = nullptr;
	}
}

GerenciadorGrafico* GerenciadorGrafico::getGerenciadorGrafico()
{
	if (pGrafico == nullptr)
	{
		pGrafico = new GerenciadorGrafico();
	}

	return pGrafico;
}

sf::RenderWindow* GerenciadorGrafico::getWindow()
{
	return window;
}

void GerenciadorGrafico::limpaJanela()
{
	window->clear();
}

void GerenciadorGrafico::desenhaElemento(sf::RectangleShape corpo)
{
	window->draw(corpo);
}

void GerenciadorGrafico::desenhaElemento(const sf::Text& texto)
{
	window->draw(texto);
}

void GerenciadorGrafico::mostraElementos()
{
	window->display();
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

void GerenciadorGrafico::executar()
{
	limpaJanela();
	//desenhaElemento();
	mostraElementos();
}
