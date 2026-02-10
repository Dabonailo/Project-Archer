#include "Fase_Primeira.h"

Fase_Primeira::Fase_Primeira() : Fase(), max_inimigos(5)
{
}

Fase_Primeira::~Fase_Primeira()
{
}

void Fase_Primeira::criarInimigos()
{
	Inimigo* inimigo1 = new Inimigo();
	inimigo1->setPosicao(sf::Vector2f(200.f, 200.f));
	ListaEntFase.adicionarElemento(inimigo1);
}

void Fase_Primeira::executar()
{

	criarInimigos();
}
