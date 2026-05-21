#include "Fase_Primeira.h"

Fase_Primeira::Fase_Primeira() : Fase(), max_inimigos(1)
{
}

Fase_Primeira::~Fase_Primeira()
{
}

void Fase_Primeira::adicionarJogador(Jogador* p)
{
	ListaEntFase.incluir(p);
	GC.incluirJogadores(p);
}

void Fase_Primeira::criarInimigos()
{
	Inimigo_facil* inimigo1 = new Inimigo_facil();
	inimigo1->setPosicao(sf::Vector2f(200.f, 200.f));
	ListaEntFase.incluir(inimigo1);
	GC.incluirInimigo(inimigo1);
}

void Fase_Primeira::executar()
{
	if (GC.getTamanhoLIs() < max_inimigos) {
		criarInimigos();
	}
	ListaEntFase.percorrerLista();
	GC.executar();
}
