#pragma once
#include "Personagem.h"
#include "GerenciadorGrafico.h"

#define NUM_VIDAS 5
#define JOG_VELOCIDADE_DEFAULT_X 0.1f
#define JOG_VELOCIDADE_DEFAULT_Y 0.1f

namespace Entidades
{
	namespace Personagens
	{

		class Jogador : public Personagem
		{
		private:

			float tempoInvulneravel;

		public:
			Jogador(sf::Vector2f pos = sf::Vector2f(0.f, 0.f),
				sf::Vector2f tam = sf::Vector2f(ENT_TAM_DEFAULT_X, ENT_TAM_DEFAULT_Y),
				const std::string& textura = "",
				sf::Vector2f v = sf::Vector2f(ENT_VEL_DEFAULT_X, ENT_VEL_DEFAULT_Y));

			~Jogador();

			const float getTempoInvulneravel() const;
			void setTempoInvulneravel(float t);

			void mover() override;

			void executar() override;
		};
	}
}
