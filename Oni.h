#pragma once
#include "Inimigo.h"


namespace Entidades
{
	namespace Personagens
	{

		class Oni : public Inimigo //mudar o nome da classe assim que o tema do jogo for escolhido
		{
		private:
			sf::Vector2f forcaEmpurro;


		public:
			Oni(sf::Vector2f pos = sf::Vector2f(0.f, 0.f),
				sf::Vector2f tam = sf::Vector2f(ENT_TAM_DEFAULT_X*1.5, ENT_TAM_DEFAULT_Y * 1.5),
				const std::string& textura = "Oni_spray.png",
				sf::Vector2f v = sf::Vector2f(ENT_VEL_DEFAULT_X, ENT_VEL_DEFAULT_Y),
				float e = 0, int n = 20, int nm = 1,
				int _id = 4);

			~Oni();

			void danificar(Jogador* p) override;   
			void atualizarCooldowns() override;
			void executar() override;
			void salvarDataBuffer();
			virtual void salvar();
			void carregar(std::istream& in);

		};

	}
}
