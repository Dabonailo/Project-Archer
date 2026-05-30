#include "Espinho.h"

namespace Entidades
{
	namespace Obstaculos
	{
		Espinho::Espinho(sf::Vector2f pos, sf::Vector2f tam, const std::string& textura, sf::Vector2f v, bool d, short int dano) 
			: Obstaculo(pos, tam, textura, v, d), danosidade(dano)
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
			desenhar();
		}
	}
}