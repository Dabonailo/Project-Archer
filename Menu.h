#pragma once

#include "Ente.h"
#include "Botao.h"
#include "GerenciadorGrafico.h"
#include <vector>
#include "direcao.h"

class Jogo;

enum tipoMenu
{
	NO_JOGO,
	MENU_PRINCIPAL,
	MENU_PAUSA,
	MENU_FASES,
	MENU_OPCOES
};

class Menu :public Ente {
private:
	Jogo* pJogo;

	tipoMenu menuAtual;
	std::vector<Botao*> vecBotao;
	std::vector<Botao*>::iterator botaoSelecionado;
	
	std::vector<sf::Text> vecTexto;

	sf::Font fonte;

public:
	Menu(
		sf::Vector2f pos = sf::Vector2f(0.f, 0.f),
		sf::Vector2f tam = sf::Vector2f(0.f, 0.f),
		const std::string& texturaFundo = "ginger_brand/FundoMenu2.png" // mudar depois
	);

	~Menu();

	void setJogo(Jogo* pJ);

	void mudarMenu(tipoMenu menu);
	tipoMenu getTipoMenu();

	void limparvecBotao();
	void limparvecTexto();

	void adicionarTexto(sf::String s = "Inserir texto", sf::Vector2f pos = sf::Vector2f(0.f, 0.f), unsigned int tam = 30);

	void criarMenuPrincipal();
	void criarMenuPausa();

	void selecionarBotoes(Direcao d);
	void executarBotao();

	void executar() override;
};