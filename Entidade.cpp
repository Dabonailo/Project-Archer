#include "Entidade.h"

namespace Entidades
{

	Entidade::Entidade(sf::Vector2f pos, sf::Vector2f tam, const std::string& textura, sf::Vector2f v, float e, int _id) :
		Ente(pos, tam, textura, _id), velocidade(v), noChao(false), empuxo(e), buffer(&bufferInterno)
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

	void Entidade::movimentar(sf::Vector2f m)
	{
		body.move(m);
	}

	void Entidade::salvarDataBuffer()
	{
		bufferInterno.str("");

		buffer << id << ' '
			<< getPosicao().x << ' '
			<< getPosicao().y << ' '

			<< getTamanho().x << ' '
			<< getTamanho().y << ' '

			<< velocidade.x << ' '
			<< velocidade.y << ' '

			<< noChao << ' '
			<< empuxo << ' ';
	}

	void Entidade::carregar(std::istream& in)
	{
		float x, y;
		float tamX, tamY;
		float velX, velY;

		in >> x;
		in >> y;

		in >> tamX;
		in >> tamY;

		in >> velX;
		in >> velY;

		in >> noChao;
		in >> empuxo;

		setTamanho(sf::Vector2f(tamX, tamY));
		setPosicao(sf::Vector2f(x, y));

		velocidade = sf::Vector2f(velX, velY);
	}

}