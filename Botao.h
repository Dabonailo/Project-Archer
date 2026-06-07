#pragma once
#include "Ente.h"
#include "GerenciadorGrafico.h"

#define TAMANHO_BOTAO_DEFAUlT_X 400.f
#define TAMANHO_BOTAO_DEFAULT_Y 50.f

enum AcaoBotao
{
	ACAO_JOGAR_FASE_1,
	ACAO_JOGAR_FASE_2,
	ACAO_SAIR,
	ACAO_MENU_FASES,
	ACAO_VOLTAR,
	ACAO_RESUMIR
};

class Botao : public Ente
{
private:
	sf::Text texto;
	sf::Font fonte;

	AcaoBotao acao;
	bool selecionado;

	float tempoAnimacao;

public:
	Botao(
		AcaoBotao a = ACAO_JOGAR_FASE_1,
		const sf::String& str = sf::String("Inserir Texto"),
		sf::Vector2f pos = sf::Vector2f(0.f, 0.f),
		sf::Vector2f tam = sf::Vector2f(TAMANHO_BOTAO_DEFAUlT_X, TAMANHO_BOTAO_DEFAULT_Y),
		const std::string& textura = "ginger_brand/Plataforma.png"
	);

	~Botao();

	AcaoBotao getAcao() const;
	
	void centralizarTexto();

	void setSelecionado(bool s);
	bool getSelecionado();

	void executar() override;
};

