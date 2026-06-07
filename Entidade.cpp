#include "Entidade.h"

namespace Entidades
{

	Entidade::Entidade(sf::Vector2f pos, sf::Vector2f tam, const std::string& textura, sf::Vector2f v, float e) :
		Ente(pos, tam, textura), velocidade(v), noChao(false), empuxo(e)
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
		if (!noChao)
		{
			velocidade.y += (GRAVIDADE - empuxo)* getTempo();
		}
		if (velocidade.y > VEL_QUEDA_MAX)
			velocidade.y = VEL_QUEDA_MAX;
	}

	void Entidade::setnoChao(bool nc)
	{
		noChao = nc;
	}	

	const bool Entidade::getnoChao() const
	{
		return noChao;
	}

	void Entidade::mover(sf::Vector2f m)
	{
		body.move(m);
	}

}