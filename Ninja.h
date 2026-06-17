#pragma once
#include "Inimigo.h"
#include "Jogador.h"

namespace Entidades 
{
	namespace Personagens 
	{
		class Ninja :public Inimigo {
		private:
			Projetil* projetil;

			float coolDownTiro;

		public:

			Ninja(sf::Vector2f pos = sf::Vector2f(0.f, 0.f),
				sf::Vector2f tam = sf::Vector2f(ENT_TAM_DEFAULT_X * 2.f, ENT_TAM_DEFAULT_Y * 2.f),
				const std::string& textura = "ninja.png",
				sf::Vector2f v = sf::Vector2f(ENT_VEL_DEFAULT_X, ENT_VEL_DEFAULT_Y),
				float e = 0,
				int n = 20, 
				int nm = 1);

			~Ninja();

			void setProjetil(Projetil* p);

			void setCooldownTiro(float cd);
			float getCooldownTiro();

			void atualizarCooldowns() override;

			void atirar();

			void mover() override;

			void movimentoAleatorio() override;

			void perseguir(Jogador* pjog) override;

			void danificar(Jogador* p) override;

			void executar() override;
		};
	}
}

