#include "Projetil.h"

Entidades::Projetil::Projetil(sf::Vector2f pos, 
	sf::Vector2f escala, 
	sf::Vector2f velocidade,
	sf::Vector2f tam,  
	const std::string& textura) :
		Entidade(pos, tam, textura, velocidade), ativo(true)
{
	body.setScale(escala);
}

Entidades::Projetil::~Projetil()
{
}

void Entidades::Projetil::setAtivo(bool a)
{
	ativo = a;
}

bool Entidades::Projetil::getAtivo()
{
	return ativo;
}

void Entidades::Projetil::mover()
{
	body.move(velocidade.x * getTempo(), velocidade.y * getTempo());

	if (velocidade.x > 0.f)
	{
		velocidade.x -= RESISTENCIA_DO_AR * getTempo();
		if (velocidade.x < 0.f) velocidade.x = 0.f;
	}
	else if (velocidade.x < 0.f)
	{
		velocidade.x += RESISTENCIA_DO_AR * getTempo();
		if (velocidade.x > 0.f) velocidade.x = 0.f;
	}
}

void Entidades::Projetil::executar()
{
	desenhar();
	gravitar();
	mover();
}
