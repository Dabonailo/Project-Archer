#pragma once
#include "Ente.h"
#include "GerenciadorGrafico.h"

#define TAMANHO_BOTAO_DEFAUlT_X 400.f
#define TAMANHO_BOTAO_DEFAULT_Y 50.f

enum AcaoBotao
{
	ACAO_JOGAR_FASE_1,
	ACAO_JOGAR_FASE_2,
	ACAO_CARREGAR_JOGO,

	ACAO_1_JOGADOR,
	ACAO_2_JOGADORES,

	ACAO_MENU_JOGADORES,

	ACAO_SAIR,
	ACAO_MENU_FASES,

	ACAO_VOLTAR,
	ACAO_VOLTAR_MENU_JOGADORES,
	ACAO_VOLTAR_MENU_GAME_OVER,

	ACAO_RESUMIR,
	ACAO_MENU_SALVAR_PONTUACAO,
	ACAO_SALVAR_PONTUACAO,
	ACAO_MENU_RANKING,
	ACAO_SALVAR_FASE
};
namespace Menus
{
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
			const std::string& textura = "ginger_brand/Placa.png"
		);

		~Botao();

		AcaoBotao getAcao() const;

		void centralizarTexto();

		void setSelecionado(bool s);
		bool getSelecionado();

		void executar() override;
	};
}
