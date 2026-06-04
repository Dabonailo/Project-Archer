#pragma once

#include "Ente.h"
#include "Botao.h"
#include "GerenciadorGrafico.h"
#include <vector>
#include "direcao.h"

enum tipoMenu
{
	MENU_PRINCIPAL,
	MENU_FASES,
	MENU_OPCOES
};

class Menu :public Ente {
private:
	tipoMenu menuAtual;
	std::vector<Botao*> vecBotao;
	std::vector<Botao*>::iterator botaoSelecionado;
	sf::Text titulo;

public:
	Menu(
		sf::Vector2f pos = sf::Vector2f(0.f, 0.f),
		sf::Vector2f tam = sf::Vector2f(0.f, 0.f),
		const std::string& texturaFundo = "ginger_brand/FundoMenu2.png" // mudar depois
	);

	~Menu();

	void mudarMenu(tipoMenu menu);

	void limparvecBotao();

	void criarMenuPrincipal();

	void selecionarBotoes(Direcao d);

	void executar() override;
};