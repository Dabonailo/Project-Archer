#pragma once
#include "Personagem.h"

namespace Entidades
{
	namespace Personagens
	{
		class Inimigo;
	}
}

#define NUM_VIDAS 5
#define JOG_VELOCIDADE_MAX 200.f
#define JOG_ACELERACAO 200.f
#define ATRITO 1000.f

namespace Entidades
{
	namespace Personagens
	{

		class Jogador : public Personagem
		{
		private:
			bool movDir;
			bool movEsq;
			
			bool querAtirar;

			float coolDownTiro;

		public:
			Jogador(sf::Vector2f pos = sf::Vector2f(0.f, 0.f),
				sf::Vector2f tam = sf::Vector2f(ENT_TAM_DEFAULT_X, ENT_TAM_DEFAULT_Y),
				const std::string& textura = "",
				sf::Vector2f v = sf::Vector2f(ENT_VEL_DEFAULT_X, ENT_VEL_DEFAULT_Y),
				float e = 0, int n = 100);

			~Jogador();

			void setMovDir(bool b);
			void setMovEsq(bool b);

			void setQuerAtirar(bool a);
			bool getQuerAtirar();

			void setCooldownTiro(float cd);
			float getCooldownTiro();

			void mover() override;
			void pular();

			void colidir(Inimigo* pIn);

			void executar() override;
		};
	}
}
