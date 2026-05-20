#pragma once
#include "Ente.h"

#define CHAO 350.f //lembrar de tirar

#define ENT_TAM_DEFAULT_X 100.f
#define ENT_TAM_DEFAULT_Y 100.f

#define ENT_VEL_DEFAULT_X 0.f
#define ENT_VEL_DEFAULT_Y 0.f

class Entidade : public Ente
{
protected:

	sf::RectangleShape body;
	sf::Texture texturaEntidade;
	sf::Vector2f velocidade;
	bool noChao;

public:
	Entidade(sf::Vector2f pos, sf::Vector2f tam, const std::string& textura, sf::Vector2f v);

	virtual ~Entidade();

	//TAMANHO E POSICAO

	void setTamanho(sf::Vector2f tam);
	void setPosicao(sf::Vector2f pos);

	const sf::Vector2f getTamanho() const;
	const sf::Vector2f getPosicao() const;

	//TEXTURA

	void setTextura(const std::string& textura);

	//VELOCIDADE

	void setVelocidade(sf::Vector2f v);
	const sf::Vector2f getVelocidade() const;
	void gravitar();

	//CORPO

	const sf::RectangleShape getBody() const;

	const sf::FloatRect getBounds() const;

	void mover(sf::Vector2f m);

	virtual void executar() = 0;

};

