#pragma once
#include "ListaEntidades.h"
#include "Inimigo_facil.h"
#include "GerenciadorColisoes.h"



namespace Fases
{

	class Fase
	{
	protected:
		Listas::ListaEntidades ListaEntFase;
		Gerenciadores::GerenciadorColisoes GC;

	protected:
		virtual void adicionarJogador(Entidades::Personagens::Jogador* p) = 0;
		virtual void criarInimigos() = 0;
		virtual void criarObstaculos() = 0;
		

	public:
		Fase() :ListaEntFase(), GC() {}
		~Fase() {}

		Listas::ListaEntidades* getListaEntFase() { return &ListaEntFase; }

		virtual void executar() = 0;
	};
}
