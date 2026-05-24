#include "Entidade.h"

namespace Entidades
{

	Entidade::Entidade(sf::Vector2f pos, sf::Vector2f tam, const std::string& textura, sf::Vector2f v) :
		Ente(pos, tam, textura), velocidade(v), noChao(false)
	{
	}

	Entidade::~Entidade()
	{
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

	void Entidade::setnoChao(bool nc)
	{
		noChao = nc;
	}	

	void Entidade::mover(sf::Vector2f m)
	{
		body.move(m);
	}
}