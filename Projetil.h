#pragma once
#include "Entidade.h"
#include "GerenciadorGrafico.h"

#define TAMANHO_PROJETIL_X 28.f
#define TAMANHO_PROJETIL_Y 7.f

#define VELOCIDADE_PROJETIL_X 700.f
#define VELOCIDADE_PROJETIL_Y 0.f

#define RESISTENCIA_DO_AR 300.f

namespace Entidades {

	class Projetil : public Entidade
	{
	private:
		bool ativo;
		float cooldownParado;

		Entidade* alvo;
		sf::Vector2f offset; //posicao do alvo
		bool cravado;
		float tempoCravado;

	public:
		Projetil(sf::Vector2f pos = sf::Vector2f(0.f, 0.f),
			sf::Vector2f velocidade = sf::Vector2f(0.f, 0.f),
			sf::Vector2f tam = sf::Vector2f(TAMANHO_PROJETIL_X, TAMANHO_PROJETIL_Y),
			const std::string& textura = "Flecha.png", float e = GRAVIDADE - 100.0);

		~Projetil();

		void setAtivo(bool a);
		bool getAtivo();

		void verificaForaDaTela();

		void cravarProjetil(Entidade* e);

		void mover();
		void executar() override;
	};

}