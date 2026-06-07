#pragma once
#include "ListaEntidades.h"
#include "Inimigo_facil.h"
#include "Inimigo_medio.h"
#include "GerenciadorColisoes.h"
#include "Plataforma.h"
#include "Espinho.h"
#include "Projetil.h"

namespace Fases	
{
	class Fase
	{
	protected:
		Listas::ListaEntidades ListaEntFase;
		Gerenciadores::GerenciadorColisoes GC;
		Entidades::Personagens::Jogador* pJogador;

	protected:
		virtual void criarInimigos() = 0;
		virtual void criarObstaculos() = 0;
		virtual void criarProjetilJogador();
		

	public:
		Fase();
		~Fase();

		virtual void adicionarJogador(Entidades::Personagens::Jogador* p);

		Listas::ListaEntidades* getListaEntFase();

		virtual void executar() = 0;

		void desenhar();
	};
}
