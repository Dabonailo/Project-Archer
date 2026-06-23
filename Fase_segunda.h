#pragma once
#include "Fase.h"

namespace Fases {

	class Fase_segunda:public Fase
	{
	private:
		const int maxChefoes;

		std::vector<Entidades::Personagens::Ninja*> vecNinja;

	public:
		Fase_segunda(Entidades::Personagens::Jogador* pJ, Entidades::Personagens::Jogador* pJ2,
			sf::Vector2f pos = sf::Vector2f(0.f, 0.f),
			sf::Vector2f tam = sf::Vector2f(0.f, 0.f),
			const std::string& textura = "Hanamura_fase2.png",
			int _id = 2, bool carregando = false);

		~Fase_segunda();

		void criarInimigos() override;

		void criarNinjas();

		void criarObstaculos() override;

		void criarEspinhos();

		void criarProjeteis() override;

	};

}