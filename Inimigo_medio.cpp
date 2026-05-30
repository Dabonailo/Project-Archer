#include "Inimigo_medio.h"

namespace Entidades
{
	namespace Personagens
	{
		Inimigo_medio::Inimigo_medio(
			sf::Vector2f pos,
			sf::Vector2f tam,
			const std::string& textura,
			sf::Vector2f v)
			:Inimigo(pos, tam, textura, v), altura_voo(0.f)
		{
			body.setFillColor(sf::Color::Red);
		}
		Inimigo_medio::~Inimigo_medio()
		{
		}
		void Inimigo_medio::danificar(Jogador* p)
		{
			if (p->getTempoInvulneravel() <= 0.f) {
				p->recebeDano(1);
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
		void Inimigo_medio::mover() {
			if (cooldownMovimento <= 0.f) {
				movimento = rand() % 4 + 1;
				switch(movimento)
				{
				case 1:
					velocidade.x = INIMIGO_MEDIO_VELOCIDADE_X;
					break;
				case 2:
					velocidade.x = -INIMIGO_MEDIO_VELOCIDADE_X;
					break;
				case 3:
					if (noChao)
					{
						velocidade.y = -FORCA_PULO;
						noChao = false;
					}
					break;
				default:
					break;
				}
				cooldownMovimento = 1.5f;
			}
		}

		void Inimigo_medio::executar()
		{
			mover();
			gravitar();
			desenhar();
		}
	}
}