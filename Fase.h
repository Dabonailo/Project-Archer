#pragma once
#include "Ente.h"
#include "ListaEntidades.h"
#include "Inimigo_facil.h"
#include "Inimigo_medio.h"
#include "GerenciadorColisoes.h"
#include "Plataforma.h"
#include "Espinho.h"
#include "Projetil.h"

namespace Fases	
{
	class Fase: public Ente
	{
	protected:
		Listas::ListaEntidades ListaEntFase;
		Listas::ListaEntidades lJogs;
		Gerenciadores::GerenciadorColisoes GC;
		Entidades::Personagens::Jogador* pJogador;

	protected:
		virtual void criarInimigos() = 0;
		void criarInimgosFaceis();
		virtual void criarObstaculos() = 0;
		void criarPlataformas();		
		virtual void criarProjeteis() = 0;
		

	public:
		Fase(Entidades::Personagens::Jogador* pJ, 
			sf::Vector2f pos = sf::Vector2f(0.f, 0.f),
			sf::Vector2f tam = sf::Vector2f(0.f, 0.f),
			const std::string& textura = "");
		~Fase();

		virtual void adicionarJogador(Entidades::Personagens::Jogador* p);

		Listas::ListaEntidades* getListaEntFase();

		virtual void executar() = 0;

		void desenhar();
	};
}
