#pragma once
#define PLAT_TAM_DEFAULT_X 200.f
#define PLAT_TAM_DEFAULT_Y 20.f
#define PLATAFORMA_VEL 80.f
#define PLATAFORMA_DIST 140.f
#include "Obstaculo.h"
#include "Jogador.h"

namespace Entidades
{

	namespace Obstaculos 
	{
		class Plataforma : public Obstaculos::Obstaculo
		{
		private:
			bool seMove;
			sf::Vector2f posOriginal;
			int direcao;

		public:
			Plataforma(sf::Vector2f pos = sf::Vector2f(0.f, 0.f), 
				sf::Vector2f tam = sf::Vector2f(PLAT_TAM_DEFAULT_X, PLAT_TAM_DEFAULT_Y),
				const std::string& textura = "ginger_brand/Plataforma.png",
				sf::Vector2f v = sf::Vector2f(0.f, 0.f), bool d = false, float e = GRAVIDADE,
				ID _id = ID::plataforma);
			~Plataforma();
			void setSeMove(bool b) { seMove = b; }
			void executar();
			void obstaculizar(Entidades::Personagens::Personagem* p);
		};
	}
	
}