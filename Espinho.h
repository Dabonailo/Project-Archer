#pragma once
#include "Obstaculo.h"
#define ESPINHO_DANO_DEFAULT 1
#define ESPINHO_TAM_DEFAULT_X 50.f
#define ESPINHO_TAM_DEFAULT_Y 50.f

namespace Entidades
{
	namespace Obstaculos
	{
		class Espinho : public Obstaculo
		{
		private:
			short int danosidade;
			
		public:
			Espinho(sf::Vector2f pos = sf::Vector2f(0.f, 0.f),
				sf::Vector2f tam = sf::Vector2f(ESPINHO_TAM_DEFAULT_X, ESPINHO_TAM_DEFAULT_Y),
				const std::string& textura = "",
				sf::Vector2f v = sf::Vector2f(0.f, 0.f), bool d = true, short int dano = ESPINHO_DANO_DEFAULT);
			~Espinho();
			const short int getDanosidade() const;
			void executar() override;
			void obstaculizar(Entidades::Personagens::Personagem* p) override;
		};
	}
}