#pragma once
#include "Ente.h"

#define CHAO 350.f //lembrar de tirar

#define ENT_TAM_DEFAULT_X 100.f
#define ENT_TAM_DEFAULT_Y 100.f

#define ENT_VEL_DEFAULT_X 0.f
#define ENT_VEL_DEFAULT_Y 0.f

namespace Entidades
{

	class Entidade : public Ente
	{
	protected:

		sf::Vector2f velocidade;
		bool noChao;

	public:
		Entidade(sf::Vector2f pos, sf::Vector2f tam, const std::string& textura, sf::Vector2f v);

		virtual ~Entidade();

		//VELOCIDADE

		void setVelocidade(sf::Vector2f v);
		const sf::Vector2f getVelocidade() const;
		void gravitar();

		//CORPO

		void mover(sf::Vector2f m);

		virtual void executar() = 0;

	};

}
