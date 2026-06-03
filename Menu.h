#pragma once

#include "Ente.h"
#include "Botao.h"
#include "GerenciadorGrafico.h"
#include <vector>

class Menu :public Ente {
private:
	std::vector<Botao*> vecBotao;
	sf::Text titulo;

public:
	Menu(
		sf::Vector2f pos = sf::Vector2f(0.f, 0.f),
		sf::Vector2f tam = sf::Vector2f(0.f, 0.f),
		const std::string& texturaFundo = "ginger_brand/FundoMenu2.png" // mudar depois
	);

	~Menu();

	void adicionarBotoes();

	void executarMenuPrincipal();
};