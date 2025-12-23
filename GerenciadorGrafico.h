#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

class GerenciadorGrafico
{
private:
	sf::RenderWindow* window;

	static GerenciadorGrafico* pGrafico;

public:
	GerenciadorGrafico();
	~GerenciadorGrafico();

	static GerenciadorGrafico* getGerenciadorGrafico();
	sf::RenderWindow* getWindow();

	void limpaJanela();

	void desenhaElemento(sf::RectangleShape corpo);
	void desenhaElemento(const sf::Text& texto);

	void mostraElementos();
	void fecharJanela();
	const bool verificaJanelaAberta();

	void executar();
};

