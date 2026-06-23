#pragma once
#include "Entidade.h"
#include "GerenciadorGrafico.h"

namespace Entidades {
	namespace Personagens {
		class Personagem;
		class Jogador;
		class Ninja;
	}
}

#define TAMANHO_PROJETIL_X 28.f
#define TAMANHO_PROJETIL_Y 7.f

#define VELOCIDADE_PROJETIL_X 700.f
#define VELOCIDADE_PROJETIL_Y 0.f

#define RESISTENCIA_DO_AR 300.f

namespace Entidades {

	class Projetil : public Entidade
	{
	private:
		bool ativo;

		Personagens::Jogador* pJogador;
		Personagens::Ninja* pNinja;

		Entidade* alvo;
		sf::Vector2f offset;

		bool cravado;
		float tempoCravado;

		int uIdDono;

	public:
		Projetil(sf::Vector2f pos = sf::Vector2f(-1000.f, 1000.f),
			sf::Vector2f tam = sf::Vector2f(TAMANHO_PROJETIL_X, TAMANHO_PROJETIL_Y),
			const std::string& textura = "Flecha.png", sf::Vector2f velocidade = sf::Vector2f(0.f, 0.f),
			float e = GRAVIDADE - 100.0,
			int _id = 10);

		~Projetil();

		void setPersonagem(Personagens::Personagem* pP);
		Personagens::Jogador* getJogador();
		Personagens::Ninja* getNinja();

		void reiniciarProjetil();

		void tratarAlvoNocauteado();

		void setAtivo(bool a);
		bool getAtivo();

		void verificaForaDaTela();

		void cravarProjetil(Entidade* e);
		void setUIdDono(int id) { uIdDono = id; }
		int getUIdDono() const { return uIdDono; }

		void mover();
		void executar() override;
		void salvarDataBuffer();
		virtual void salvar();
		void carregar(std::istream& in);
	};

}