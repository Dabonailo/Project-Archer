#include "Inimigo.h"

Inimigo::Inimigo(sf::Vector2f pos, sf::Vector2f tam, const std::string& textura, sf::Vector2f v)
	:Personagem(pos, tam, textura, v)
{
	body.setFillColor(sf::Color::Green);
}

Inimigo::~Inimigo()
{
}

void Inimigo::executar()
{
}
