#include "Inimigo.h"

namespace Entidades
{
	namespace Personagens
	{

		Inimigo::Inimigo(sf::Vector2f pos, sf::Vector2f tam, const std::string& textura, sf::Vector2f v, float e, int n, int nm)
			:Personagem(pos, tam, textura, v, e, n), cooldownMovimento(0.f), movimento(-1), lJogs(NULL), nivel_maldade(nm)
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

		void Inimigo::recebeDano(int dano)
		{
			numVidas -= dano;

			if (dano > 5)
				nivel_maldade++;
		}

		int Inimigo::getNivelMaldade()
		{
			return nivel_maldade;
		}

		void Inimigo::mover()
		{
			if (cooldownKnockback > 0.f)
				return;

			bool achou = false;

			Listas::Lista<Entidades::Entidade>::Elemento<Entidades::Entidade>* atual =
				lJogs->getPrimeiro();

			while (atual)
			{
				Jogador* pJog = dynamic_cast<Jogador*>(atual->getInfo());

				if (pJog)
				{
					if (!achou)
					{
						float dx = pJog->getPosicao().x - getPosicao().x;
						float dy = pJog->getPosicao().y - getPosicao().y;

						float dist = sqrt(dx * dx + dy * dy);

						if (dist <= RANGE_INIMIGO)
						{
							perseguir(pJog);
							achou = true;
						}
					}
				}

				atual = atual->getProximo();
			}

			if (!achou)
				movimentoAleatorio();
		}

		void Inimigo::perseguir(Jogador* pJog)
		{
			if (!pJog)
				return;

			if (pJog->getPosicao().x > getPosicao().x)
			{
				velocidade.x = INIMIGO_VELOCIDADE_X;
				body.setScale(-1.f, 1.f);
			}
			else
			{
				velocidade.x = -INIMIGO_VELOCIDADE_X;
				body.setScale(1.f, 1.f);
			}

			if (pJog->getPosicao().y < getPosicao().y - 40.f)
			{
				if (noChao)
				{
					velocidade.y = -FORCA_PULO;
					noChao = false;
				}
			}
		}
		void Inimigo::movimentoAleatorio()
		{
			if (cooldownMovimento <= 0.f) {
				movimento = rand() % 4 + 1;

				switch (movimento)
				{
				case 1:
					velocidade.x = INIMIGO_VELOCIDADE_X;
					body.setScale(-1.f, 1.f);
					setDirecao(DIREITA);
					break;

				case 2:
					velocidade.x = -INIMIGO_VELOCIDADE_X;
					body.setScale(1.f, 1.f);
					setDirecao(ESQUERDA);
					break;

				case 3:
					if (noChao)
					{
						velocidade.y = -FORCA_PULO;
						noChao = false;
					}
					break;

				case 4:
					velocidade.x = 0.f;
					break;
				}
				cooldownMovimento = 5.f;
			}
		}

	}
}