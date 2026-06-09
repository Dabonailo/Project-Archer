#pragma once
#include "Entidade.h"

#define TAMANHO_PROJETIL_X 40.f
#define TAMANHO_PROJETIL_Y 10.f

#define VELOCIDADE_PROJETIL_X 1300.f
#define VELOCIDADE_PROJETIL_Y 0.F

#define RESISTENCIA_DO_AR 300.f

namespace Entidades {

	class Projetil : public Entidade
	{
	private:
		bool ativo;

	public:
		Projetil(sf::Vector2f pos = sf::Vector2f(0.f, 0.f),
			sf::Vector2f escala = sf::Vector2f(1.f, 1.f),
			sf::Vector2f velocidade = sf::Vector2f(0.f, 0.f),
			sf::Vector2f tam = sf::Vector2f(TAMANHO_PROJETIL_X, TAMANHO_PROJETIL_Y),
			const std::string& textura = "Flecha.png", float e = GRAVIDADE - 100.0);

		~Projetil();

		void setAtivo(bool a);
		bool getAtivo();

		void mover();
		void executar() override;
	};

}