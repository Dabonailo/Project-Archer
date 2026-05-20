#include "Entidade.h"

Entidade::Entidade(sf::Vector2f pos, sf::Vector2f tam, const std::string& textura, sf::Vector2f v) :

	Ente(), body(), texturaEntidade(), velocidade(v), noChao(false)
{
	body.setSize(tam);
	body.setPosition(pos);

	if (textura != "") {
		texturaEntidade.loadFromFile(textura);
		body.setTexture(&texturaEntidade);
	}
	else {
		body.setFillColor(sf::Color::Red);
		std::cout << "textura nao carregada" << std::endl;
	}
}

Entidade::~Entidade()
{
}

void Entidade::setTamanho(sf::Vector2f tam)
{
	body.setSize(tam);
}

void Entidade::setPosicao(sf::Vector2f pos)
{
	body.setPosition(pos);
}

const sf::Vector2f Entidade::getTamanho() const
{
	return body.getSize();
}

const sf::Vector2f Entidade::getPosicao() const
{
	return body.getPosition();
}

void Entidade::setTextura(const std::string& textura)
{
	texturaEntidade.loadFromFile(textura);
	body.setTexture(&texturaEntidade);
}

void Entidade::setVelocidade(sf::Vector2f v)
{
	velocidade = v;
}

const sf::Vector2f Entidade::getVelocidade() const
{
	return velocidade;
}

void Entidade::gravitar()
{
	if (body.getPosition().y < CHAO) {
		velocidade.y += 0.0005f;
	}
	else {
		velocidade.y = 0.f;
	}
	if (body.getPosition().y + body.getSize().y >= CHAO) {
		body.setPosition(body.getPosition().x, CHAO - body.getSize().y);
		noChao = true;
	}
}

const sf::RectangleShape Entidade::getBody() const
{
	return body;
}

const sf::FloatRect Entidade::getBounds() const
{
	return body.getGlobalBounds();
}

void Entidade::mover(sf::Vector2f m)
{
	body.move(m);
}
