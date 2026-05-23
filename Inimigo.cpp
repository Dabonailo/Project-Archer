#include "Inimigo.h"

namespace Entidades
{
	namespace Personagens
	{

		Inimigo::Inimigo(sf::Vector2f pos, sf::Vector2f tam, const std::string& textura, sf::Vector2f v)
			:Personagem(pos, tam, textura, v)
		{
			body.setFillColor(sf::Color::Red);
		}

		Inimigo::~Inimigo()
		{
		}

		void Inimigo::executar()
		{
		}
	}
}