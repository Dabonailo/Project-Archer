#include "Personagem.h"

Personagem::Personagem(sf::Vector2f pos, sf::Vector2f tam, const std::string& textura, sf::Vector2f v)
	: Entidade(pos, tam, textura, v), numVidas(5)
{
}

Personagem::~Personagem()
{
}

const int Personagem::getVida() const
{
	return numVidas;
}
