#include "Inimigo_medio.h"

namespace Entidades
{
	namespace Personagens
	{
		Inimigo_medio::Inimigo_medio(
			sf::Vector2f pos,
			sf::Vector2f tam,
			const std::string& textura,
			sf::Vector2f v, float e, float a, int n, int nm)
			:Inimigo(sf::Vector2f(pos.x, pos.y - a), tam, textura, v, e, n, nm), altura_voo(a), diving(false), altura_default(pos.y - a), direcao(1), delay_troca_direcao(3.f)
		{
			//body.setFillColor(sf::Color::Red);
			std::cout
				<< "CRIADO: "
				<< body.getPosition().x
				<< " "
				<< body.getPosition().y
				<< " velY="
				<< velocidade.y
				<< std::endl;
		}
		Inimigo_medio::~Inimigo_medio()
		{
		}
		void Inimigo_medio::danificar(Jogador* p)
		{
			if (p->getTempoInvulneravel() <= 0.f) {
				p->recebeDano(10*nivel_maldade);
				if (p->getBounds().left < getBounds().left) {
					p->aplicarKnockback(sf::Vector2f(-KNOCKBACK_X, 0.f));
					p->setVelocidade(sf::Vector2f(0.f, -KNOCKBACK_Y));
				}
				else {
					p->aplicarKnockback(sf::Vector2f(KNOCKBACK_X, 0.f));
					p->setVelocidade(sf::Vector2f(0.f, -KNOCKBACK_Y));
				}
				p->setTempoInvulneravel(2.f);
			}
		}
		
		void Inimigo_medio::mover()
		{
			bool achou = false;

			Listas::Lista<Entidades::Entidade>::Elemento<Entidades::Entidade>* atual =
				lJogs->getPrimeiro();

			while (atual && !achou)
			{
				Jogador* pJog =
					dynamic_cast<Jogador*>(atual->getInfo());

				if (pJog)
				{
					float dx = pJog->getPosicao().x - getPosicao().x;
					float dy = pJog->getPosicao().y - getPosicao().y;

					if (dx < 0.f)
						dx = -dx;

					if (dy < 0.f)
						dy = -dy;

					if (dx <= RANGE_INIM_MEDIO_X &&
						dy <= RANGE_INIM_MEDIO_Y)
					{
						perseguir(pJog);
						achou = true;
					}
				}

				atual = atual->getProximo();
			}

			if (!achou)
			{
				diving = false;
				movimentoAleatorio();
			}
		}

		void Inimigo_medio::perseguir(Jogador* pJog)
		{
			if (!pJog)
				return;

			float dx = pJog->getPosicao().x - getPosicao().x;

			if (dx > 0.f)
			{
				velocidade.x = INIMIGO_MEDIO_VELOCIDADE_X;
				body.setScale(1.f, 1.f);
			}
			else
			{
				velocidade.x = -INIMIGO_MEDIO_VELOCIDADE_X;
				body.setScale(-1.f, 1.f);
				dx = -dx;
			}

			if (dx <= DISTANCIA_RASANTE)
			{
				diving = true;
			}

			if (diving)
			{
				velocidade.y = 0.25f;

				if (getPosicao().y > altura_default + 100.f)
				{
					diving = false;
				}
			}
			else
			{
				if (getPosicao().y > altura_default)
				{
					velocidade.y = -0.15f;
				}
				else if (getPosicao().y < altura_default)
				{
					velocidade.y = 0.15f;
				}
				else
				{
					velocidade.y = 0.f;
				}
			}
		}
		void Inimigo_medio::movimentoAleatorio()
		{
			velocidade.x = direcao * INIMIGO_MEDIO_VELOCIDADE_X;

			if (direcao > 0)
				body.setScale(1.f, 1.f);
			else
				body.setScale(-1.f, 1.f);

			delay_troca_direcao -= getTempo();

			if (delay_troca_direcao <= 0.f)
			{
				direcao *= -1;
				delay_troca_direcao = 3.f;
			}

			velocidade.y = 0.f;
		}



		void Inimigo_medio::executar()
		{	
			/*std::cout << "PosX: " << getPosicao().x
				<< " Dir: " << direcao
				<< std::endl;*/
			mover();
			gravitar();
			desenhar();

			body.move(velocidade.x * getTempo(), velocidade.y * getTempo());
		}
	}
}