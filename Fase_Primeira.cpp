#include "Fase_Primeira.h"

Fase_Primeira::Fase_Primeira() : Fase(), max_inimigos(1)
{
}

Fase_Primeira::~Fase_Primeira()
{
}

void Fase_Primeira::adicionarJogador(Jogador* p)
{
	ListaEntFase.adicionarElemento(p);
}

void Fase_Primeira::criarInimigos()
{
	Inimigo_facil* inimigo1 = new Inimigo_facil();
	inimigo1->setPosicao(sf::Vector2f(200.f, 200.f));
	ListaEntFase.adicionarElemento(inimigo1);
}

void Fase_Primeira::executar()
{
	if (GC.getTamanhoLIs() < 1) {
		criarInimigos();
		GC.setEntidades(ListaEntFase);
	}
	ListaEntFase.percorrerLista(*this);
}
