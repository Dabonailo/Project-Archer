#pragma once
#include "Ente.h"
#include "ListaEntidades.h"
#include "Jogador.h"
#include "Oni.h"
#include "Dragao.h"
#include "GerenciadorColisoes.h"
#include "Plataforma.h"
#include "Espinho.h"
#include "Projetil.h"
#include "Ninja.h"
#include "Bloco_Magma.h"

#include <vector>
#include <fstream>
#include <sstream>
#include <map>

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
		bool acabouDeCarregar;

	protected:
		virtual void criarInimigos() = 0;
		void criarOnis();
		virtual void criarObstaculos() = 0;
		void criarPlataformas();		
		virtual void criarProjeteis() = 0;
		void criarCenario();

	public:
		Fase(Entidades::Personagens::Jogador* pJ = NULL,
			Entidades::Personagens::Jogador* pJ2 = NULL,
			sf::Vector2f pos = sf::Vector2f(0.f, 0.f),
			sf::Vector2f tam = sf::Vector2f(0.f, 0.f),
			const std::string& textura = "", int _id = -1);
		~Fase();

		Listas::ListaEntidades* getListaEntFase();
		int getNumeroInimigos();

		Entidades::Personagens::Jogador* getJogador1() { return pJogador;}
		Entidades::Personagens::Jogador* getJogador2() { return pJogador2; }

		virtual void executar();

		void atualizalJogs();

		void desenhar();

		void salvarFase();

		void carregarFase();
	};
}
