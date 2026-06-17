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

			Inimigo(pos, tam, textura, v, e, n, nm), projetil(NULL), coolDownTiro(0.f)
		{
		}

		Ninja::~Ninja()
		{
		}

		void Ninja::setProjetil(Projetil* p)
		{
			projetil = p;
			projetil->setCor(sf::Color(0, 255, 220));
		}

		void Ninja::setCooldownTiro(float cd)
		{
			coolDownTiro = cd;
		}

		float Ninja::getCooldownTiro()
		{
			return coolDownTiro;
		}

		void Ninja::atualizarCooldowns()
		{
			velocidadeKnockback *= 0.995f;

			if (cooldownKnockback > 0.f)
				cooldownKnockback -= getTempo();

			if (cooldownMovimento > 0.f) {
				cooldownMovimento -= getTempo();
			}

			if (tempoInvulneravel > 0.f) {
				tempoInvulneravel -= getTempo();
			}

			if (coolDownTiro > 0.f) {
				coolDownTiro -= getTempo();
			}
		}

		void Ninja::atirar()
		{
			if (coolDownTiro > 0) {
				return;
			}

			if (rand() % 3 == 1) {
				projetil->setAtivo(true);
				projetil->reiniciarProjetil();
				setCooldownTiro(5.f);
			}
		}

		void Ninja::mover()
		{
		}

		void Ninja::movimentoAleatorio()
		{
			if (cooldownMovimento <= 0.f) {
				movimento = rand() % 4 + 1;

				switch (movimento)
				{
				case 1:
					velocidade.x = 50.f;
					body.setScale(1.f, 1.f);
					setDirecao(DIREITA);
					break;

				case 2:
					velocidade.x = -50.f;
					body.setScale(-1.f, 1.f);
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

		void Ninja::perseguir(Jogador* pjog)
		{
		}

		void Ninja::danificar(Jogador* p) //mudar o danificar
		{
			if (p->getTempoInvulneravel() <= 0.f) {

				p->recebeDano(5 + nivel_maldade);
				p->aplicarCongelamento(5.f, 0.5f);

				if (p->getBounds().left < getBounds().left) {

					p->aplicarKnockback(sf::Vector2f(-(KNOCKBACK_X * 3), 0.f));
					p->setVelocidade(sf::Vector2f(0.f, 0.f));
				}
				else {

					p->aplicarKnockback(sf::Vector2f(KNOCKBACK_X * 3, 0.f));
					p->setVelocidade(sf::Vector2f(0.f, 0.f));
				}

				p->setTempoInvulneravel(2.f);
			}
		}

		void Ninja::executar() 
		{
			movimentoAleatorio();
			atirar();
			gravitar();

			body.move(
				(velocidade.x + velocidadeKnockback.x) * getTempo(),
				(velocidade.y + velocidadeKnockback.y) * getTempo()
			);

			atualizarCooldowns();
			desenhar();

		}

	}
}