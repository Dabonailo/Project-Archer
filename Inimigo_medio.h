#pragma once
#include "Inimigo.h"
#define INIMIGO_MEDIO_VELOCIDADE_X 100.f

namespace Entidades
{
	namespace Personagens
	{
		class Inimigo_medio : public Inimigo
		{
		private:
			float altura_voo;
		public:
			Inimigo_medio(sf::Vector2f pos = sf::Vector2f(0.f, 0.f),
				sf::Vector2f tam = sf::Vector2f(ENT_TAM_DEFAULT_X, ENT_TAM_DEFAULT_Y),
				const std::string& textura = "",
				sf::Vector2f v = sf::Vector2f(ENT_VEL_DEFAULT_X, ENT_VEL_DEFAULT_Y));
			~Inimigo_medio();
			void danificar(Jogador* p) override;
			void mover() override;
			void executar() override;
		};
	}
}