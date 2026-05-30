#include "Inimigo.h"

namespace Entidades
{
	namespace Personagens
	{

		Inimigo::Inimigo(sf::Vector2f pos, sf::Vector2f tam, const std::string& textura, sf::Vector2f v)
			:Personagem(pos, tam, textura, v), cooldownMovimento(0.f), movimento(-1)
		{
		}

		Inimigo::~Inimigo()
		{
		}

		void Inimigo::setCooldownMovimento(float c)
		{
			cooldownMovimento = c;
		}

		float Inimigo::getCooldownMovimento()
		{
			return cooldownMovimento;
		}

		void Inimigo::setMovimento(int m)
		{
			movimento = m;
		}

		int Inimigo::getMovimento()
		{
			return movimento;
		}

		void Inimigo::mover()
		{
			movimentoAleatorio();
		}

		void Inimigo::movimentoAleatorio()
		{
			int direcao = rand() % 4;
			switch (direcao)
			{
			case 0: // cima
				velocidade = sf::Vector2f(0.f, -0.1f);
				break;
			case 1: // baixo
				velocidade = sf::Vector2f(0.f, 0.1f);
				break;
			case 2: // esquerda
				velocidade = sf::Vector2f(-0.1f, 0.f);
				break;
			case 3: // direita
				velocidade = sf::Vector2f(0.1f, 0.f);
				break;
			default:
				break;
			}
			gravitar();
		}

		void Inimigo::executar()
		{
		}
	}
}