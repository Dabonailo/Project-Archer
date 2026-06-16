#pragma once
#include "Ente.h"
#include "ListaEntidades.h"
#include "Jogador.h"
#include "Inimigo_facil.h"
#include "Inimigo_medio.h"
#include "GerenciadorColisoes.h"
#include "Plataforma.h"
#include "Espinho.h"
#include "Projetil.h"
#include "Ninja.h"
#include "Magma_block.h"

#include <vector>

namespace Fases	
{
	class Fase: public Ente
	{
	protected:
		Listas::ListaEntidades ListaEntFase;
		Listas::ListaEntidades lJogs;
		Gerenciadores::GerenciadorColisoes GC;
		Entidades::Personagens::Jogador* pJogador;
		Entidades::Personagens::Jogador* pJogador2;

	protected:
		virtual void criarInimigos() = 0;
		void criarOnis();
		virtual void criarObstaculos() = 0;
		void criarPlataformas();		
		virtual void criarProjeteis() = 0;
		void criarCenario();

	public:
		Fase(Entidades::Personagens::Jogador* pJ, 
			Entidades::Personagens::Jogador* pJ2 = NULL,
			sf::Vector2f pos = sf::Vector2f(0.f, 0.f),
			sf::Vector2f tam = sf::Vector2f(0.f, 0.f),
			const std::string& textura = "");
		~Fase();

		Listas::ListaEntidades* getListaEntFase();

		virtual void executar();

		void atualizalJogs();

		void desenhar();
	};
}
