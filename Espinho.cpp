#include "Espinho.h"

namespace Entidades
{
	namespace Obstaculos
	{
		Espinho::Espinho(sf::Vector2f pos, sf::Vector2f tam, const std::string& textura, sf::Vector2f v, bool d, short int dano, float e, ID _id)
			: Obstaculo(pos, tam, textura, v, d, e), danosidade(dano), cooldown(1000)
		{
			body.setFillColor(sf::Color::White);
		}
		Espinho::~Espinho()
		{
		}
		const short int Espinho::getDanosidade() const
		{
			return danosidade;
		}
		void Espinho::obstaculizar(Entidades::Personagens::Personagem* p)
		{
			if (!p)
				return;

			else if (danoso) {

				if (p->getTempoInvulneravel() <= 0.f) {
					p->recebeDano(danosidade);

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
		}
		void Espinho::executar()
		{
			gravitar();
			
			if (cooldown <= 0)
			{
				int i = rand() % 3;
				if (i == 0)
				{
					danosidade = ESPINHO_DANO_DEFAULT;
					body.setFillColor(sf::Color::White);
				}
				else if (i == 1)
				{
					danosidade = ESPINHO_DANO_DEFAULT * 2;
					body.setFillColor(sf::Color::Yellow);
				}
				else
				{
					danosidade = ESPINHO_DANO_DEFAULT * 3;
					body.setFillColor(sf::Color::Red);
				}
				cooldown = 1000;
			}
			else
				cooldown--;

			desenhar();
		}
	}
}