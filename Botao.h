#pragma once
#include "Ente.h"
#include "GerenciadorGrafico.h"

#define TAMANHO_BOTAO_DEFAUlT_X 100.f
#define TAMANHO_BOTAO_DEFAULT_Y 50.f

enum AcaoBotao
{
	ACAO_JOGAR,
	ACAO_SAIR,
	ACAO_MENU_FASES,
	ACAO_VOLTAR
};

class Botao : public Ente
{
private:
	sf::Text texto;
	sf::Font fonte;

	AcaoBotao acao;

public:
	Botao(
		AcaoBotao a = ACAO_JOGAR,
		const sf::String& str = sf::String("Inserir Texto"),
		sf::Vector2f pos = sf::Vector2f(0.f, 0.f),
		sf::Vector2f tam = sf::Vector2f(TAMANHO_BOTAO_DEFAUlT_X, TAMANHO_BOTAO_DEFAULT_Y),
		const std::string& textura = "ginger_brand/Plataforma.png"
	);

	~Botao();

	AcaoBotao getAcao() const;

	void executar() override;
};

