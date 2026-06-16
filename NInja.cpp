#include "Ninja.h"

namespace Entidades
{
	namespace Personagens
	{
		Ninja::Ninja(
			sf::Vector2f pos,
			sf::Vector2f tam,
			const std::string& textura,
			sf::Vector2f v, float e, int n, int nm):

			Inimigo(pos, tam, textura, v, e, n, nm), querAtirar(false), coolDownTiro(0.f)
		{
		}

		Ninja::~Ninja()
		{
		}

		void Ninja::setQuerAtirar(bool a) {
			querAtirar = a;
		}

		bool Ninja::getQuerAtirar() {
			return querAtirar;
		}

		void Ninja::setCooldownTiro(float cd)
		{
			coolDownTiro = cd;
		}

		float Ninja::getCooldownTiro()
		{
			return coolDownTiro;
		}

		void Ninja::atirar()
		{
			if (coolDownTiro > 0) {
				return;
			}

			if (rand() % 3 == 1) {
				setQuerAtirar(true);
				setCooldownTiro(3.f);
			}
		}

		void Ninja::mover()
		{
		}

		void Ninja::movimentoAleatorio()
		{
		}

		void Ninja::perseguir(Jogador* pjog)
		{
		}

		void Ninja::danificar(Jogador* p) //mudar o danificar
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

		void Ninja::executar() 
		{
			desenhar();
		}

	}
}