#include "Personagem.h"

namespace Entidades
{
	namespace Personagens
	{

		Personagem::Personagem(sf::Vector2f pos, sf::Vector2f tam, const std::string& textura, sf::Vector2f v)
			: Entidade(pos, tam, textura, v), numVidas(5),
			velocidadeKnockback(sf::Vector2f(0.f, 0.f)),
			cooldownKnockback(0.f),
			direcao(1.f, 1.f)
		{
		}

		Personagem::~Personagem()
		{
		}

		const int Personagem::getVida() const
		{
			return numVidas;
		}

		const bool Personagem::getVivo() const
		{
			if (getVida() > 0) {
				return true;
			}
			else {
				return false;
			}
		}

		void Personagem::aplicarKnockback(sf::Vector2f forca)
		{
			velocidadeKnockback += forca;

			cooldownKnockback = 25.f;
		}
	}
}