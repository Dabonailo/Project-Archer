#pragma once
#include "Ente.h"
#include <string>
#include <sstream>
#include <istream>

#define GRAVIDADE 1200.f
#define VEL_QUEDA_MAX 600.f

#define ENT_TAM_DEFAULT_X 50.f
#define ENT_TAM_DEFAULT_Y 50.f

#define ENT_VEL_DEFAULT_X 0.f
#define ENT_VEL_DEFAULT_Y 0.f

namespace Entidades
{

	class Entidade : public Ente
	{
	protected:

		sf::Vector2f velocidade;
		bool noChao;
		float empuxo;

		std::ostream buffer;
		std::stringbuf bufferInterno;


	public:
		Entidade(sf::Vector2f pos, sf::Vector2f tam, const std::string& textura, sf::Vector2f v, float e, int _id);

		virtual ~Entidade();

		//VELOCIDADE

		void setVelocidade(sf::Vector2f v);
		const sf::Vector2f getVelocidade() const;
		void gravitar();
		void setnoChao(bool nc);
		const bool getnoChao() const;

		//CORPO

		void movimentar(sf::Vector2f m);

		virtual void executar() = 0;
		void salvarDataBuffer();
		virtual void salvar() = 0;
		virtual void carregar(std::istream& in); 

		const std::string getBufferInterno() const { return bufferInterno.str(); }
	};

}
