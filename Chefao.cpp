#include "Chefao.h"

namespace Entidades
{
	namespace Personagens
	{
		Chefao::Chefao(
			sf::Vector2f pos,
			sf::Vector2f tam,
			const std::string& textura,
			sf::Vector2f v, float e):

			Inimigo(pos, tam, textura, v, e), querAtirar(false), coolDownTiro(0.f)
		{
		}

		Chefao::~Chefao()
		{
		}

		void Chefao::setQuerAtirar(bool a) {
			querAtirar = a;
		}

		bool Chefao::getQuerAtirar() {
			return querAtirar;
		}

		void Chefao::setCooldownTiro(float cd)
		{
			coolDownTiro = cd;
		}

		float Chefao::getCooldownTiro()
		{
			return coolDownTiro;
		}

		void Chefao::atirar()
		{
			if (coolDownTiro > 0) {
				return;
			}

			if (rand() % 3 == 1) {
				setQuerAtirar(true);
				setCooldownTiro(3.f);
			}
		}

		void Chefao::danificar(Jogador* p) 
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

		void Chefao::executar() 
		{
			desenhar();
		}

	}
}