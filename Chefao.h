#pragma once
#include "Inimigo.h"
#include "Jogador.h"

namespace Entidades 
{
	namespace Personagens 
	{
		class Chefao :public Inimigo {
		private:
			bool querAtirar;

			float coolDownTiro;

		public:

			Chefao(sf::Vector2f pos = sf::Vector2f(0.f, 0.f),
				sf::Vector2f tam = sf::Vector2f(ENT_TAM_DEFAULT_X, ENT_TAM_DEFAULT_Y),
				const std::string& textura = "",
				sf::Vector2f v = sf::Vector2f(ENT_VEL_DEFAULT_X, ENT_VEL_DEFAULT_Y),
				float e = 0,
				int n = 20, 
				int nm = 1);

			~Chefao();

			void setQuerAtirar(bool a);
			bool getQuerAtirar();

			void setCooldownTiro(float cd);
			float getCooldownTiro();

			void atirar();

			void danificar(Jogador* p) override;

			void executar() override;
		};
	}
}

