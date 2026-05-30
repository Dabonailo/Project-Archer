#pragma once

#include "Personagem.h"

namespace Entidades
{

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
			virtual void obstaculizar(Entidades::Personagens::Personagem* p) = 0;

		};
	}
}