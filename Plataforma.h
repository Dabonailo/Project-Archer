#pragma once
#define PLAT_TAM_DEFAULT_X 200.f
#define PLAT_TAM_DEFAULT_Y 20.f
#include "Obstaculo.h"
#include "Jogador.h"

namespace Entidades
{

	namespace Obstaculos 
	{
		class Plataforma : public Obstaculos::Obstaculo
		{
		private:
			int altura;

		public:
			Plataforma(sf::Vector2f pos = sf::Vector2f(0.f, 0.f), 
				sf::Vector2f tam = sf::Vector2f(PLAT_TAM_DEFAULT_X, PLAT_TAM_DEFAULT_Y),
				const std::string& textura = "",
				sf::Vector2f v = sf::Vector2f(0.f, 0.f), bool d = false);
			~Plataforma();
			void executar();
			void obstaculizar(Entidades::Entidade* p);
		};
	}
	
}