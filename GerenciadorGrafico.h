#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

#include "ListaEntidades.h"

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

	void desenhaElemento(Entidade* e);
	void desenhaTexto(const sf::Text& texto);

	void mostraElementos();
	void fecharJanela();
	const bool verificaJanelaAberta();

	void executar(ListaEntidades* listaFA, ListaEntidades* listaFI);
};

