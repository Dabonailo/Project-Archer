#pragma once
#include "Inimigo.h"

#define INIMIGO_FACIL_VELOCIDADE_X 50.f

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
				const std::string& textura = "Junk_spray.png",
				sf::Vector2f v = sf::Vector2f(ENT_VEL_DEFAULT_X, ENT_VEL_DEFAULT_Y),
				float e = 0);

			~Inimigo_facil();

			void danificar(Jogador* p) override;
			void mover() override;
			void movimentoAleatorio();
			void perseguir(Jogador* pJog);
			void executar() override;

		};

	}
}
