#pragma once

#include "Entidade.h"

namespace Entidades
{
	namespace Personagens
	{
		class Jogador;
	}

	namespace Obstaculos
	{
		class Obstaculo : public Entidade
		{
		protected:
			bool danoso;

		public:
			Obstaculo(sf::Vector2f pos, sf::Vector2f tam, const std::string& textura, sf::Vector2f v, bool d);
			~Obstaculo();
			virtual void executar() = 0;
			virtual void obstaculizar(Personagens::Jogador* p) = 0;

		};
	}
}