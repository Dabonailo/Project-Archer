#include "Jogador.h"

Jogador::Jogador(sf::Vector2f pos, sf::Vector2f tam, const std::string& textura, sf::Vector2f v)
	:Personagem(pos, tam, textura, v)
{
	texturaEntidade.loadFromFile(textura);
	body.setTexture(&texturaEntidade);
}

Jogador::~Jogador()
{
}

void Jogador::mover()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		body.move(0.f, -JOG_VELOCIDADE_DEFAULT_Y);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		body.move(0.f, JOG_VELOCIDADE_DEFAULT_Y);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		body.move(JOG_VELOCIDADE_DEFAULT_X, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		body.move(-JOG_VELOCIDADE_DEFAULT_X, 0.f);
	}
}

void Jogador::executar()
{
	mover();
}
