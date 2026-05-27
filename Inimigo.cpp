#include "Inimigo.h"

namespace Entidades
{
	namespace Personagens
	{

		Inimigo::Inimigo(sf::Vector2f pos, sf::Vector2f tam, const std::string& textura, sf::Vector2f v)
			:Personagem(pos, tam, textura, v), cooldownMovimento(0.f), movimento(-1)
		{
			body.setFillColor(sf::Color::Red);
		}

		Inimigo::~Inimigo()
		{
		}

		void Inimigo::setCooldownMovimento(float c)
		{
			cooldownMovimento = c;
		}

		float Inimigo::getCooldownMovimento()
		{
			return cooldownMovimento;
		}

		void Inimigo::setMovimento(int m)
		{
			movimento = m;
		}

		int Inimigo::getMovimento()
		{
			return movimento;
		}

		void Inimigo::executar()
		{
		}
	}
}