#pragma once
#include "Inimigo.h"

namespace Entidades
{
	namespace Personagens
	{

		class Inimigo_facil : public Inimigo //mudar o nome da classe assim que o tema do jogo for escolhido
		{
		private:
			float raio;

		public:
			Inimigo_facil(sf::Vector2f pos = sf::Vector2f(0.f, 0.f),
				sf::Vector2f tam = sf::Vector2f(ENT_TAM_DEFAULT_X, ENT_TAM_DEFAULT_Y),
				const std::string& textura = "",
				sf::Vector2f v = sf::Vector2f(ENT_VEL_DEFAULT_X, ENT_VEL_DEFAULT_Y));

			~Inimigo_facil();

			void danificar(Jogador* p) override;
			void mover() override;
			void executar() override;

		};

	}
}
