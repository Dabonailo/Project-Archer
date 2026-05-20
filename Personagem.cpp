#include "Personagem.h"

Personagem::Personagem(sf::Vector2f pos, sf::Vector2f tam, const std::string& textura, sf::Vector2f v)
	: Entidade(pos, tam, textura, v), numVidas(5), velocidadeKnockback(sf::Vector2f(0.f,0.f)), cooldownKnockback(0.f),
	esquerda(false), direita(false)
{
}

Personagem::~Personagem()
{
}

const int Personagem::getVida() const
{
	return numVidas;
}

void Personagem::aplicarKnockback(sf::Vector2f forca)
{
	velocidadeKnockback += forca;

	cooldownKnockback = 25.f;
}
