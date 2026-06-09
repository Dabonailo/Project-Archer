#include "Obstaculo.h"

namespace Entidades
{
	namespace Obstaculos
	{
		Obstaculo::Obstaculo(sf::Vector2f pos, sf::Vector2f tam, const std::string& textura, sf::Vector2f v, bool d, float e)
			: Entidade(pos, tam, textura, v, e), danoso(d)
		{
			//body.setFillColor(sf::Color::Yellow);
		}
		Obstaculo::~Obstaculo()
		{
		}
	}
}