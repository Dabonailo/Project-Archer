#pragma once
#include "Inimigo.h"
#define INIMIGO_MEDIO_VELOCIDADE_X 50.f
#define RANGE_INIM_MEDIO_X 300.f
#define RANGE_INIM_MEDIO_Y 150.f
#define DISTANCIA_RASANTE 100.f

namespace Entidades
{
	namespace Personagens
	{
		class Inimigo_medio : public Inimigo
		{
		private:
			float altura_voo;
			float altura_default;
			bool diving;
			float delay_troca_direcao;
			int direcao;

		public:
			Inimigo_medio(sf::Vector2f pos = sf::Vector2f(0.f, 0.f),
				sf::Vector2f tam = sf::Vector2f(ENT_TAM_DEFAULT_X, ENT_TAM_DEFAULT_Y),
				const std::string& textura = "dragao.png",
				sf::Vector2f v = sf::Vector2f(ENT_VEL_DEFAULT_X, ENT_VEL_DEFAULT_Y),
				float e = GRAVIDADE, float a = 50.f);
			~Inimigo_medio();
			void danificar(Jogador* p) override;
			void mover() override;
			void executar() override;
			void perseguir(Jogador* pJog);
			void movimentoAleatorio();
		};
	}
}