#include "Inimigo_facil.h"

Inimigo_facil::Inimigo_facil(
	sf::Vector2f pos, 
	sf::Vector2f tam,
	const std::string& textura,
	sf::Vector2f v)

	:Inimigo(pos, tam, textura, vel), raio(0.f)
{
}

Inimigo_facil::~Inimigo_facil()
{
}

void Inimigo_facil::danificar(Jogador* p)
{
	p->operator--();
}

void Inimigo_facil::executar(){}
