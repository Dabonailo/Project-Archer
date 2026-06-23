#include "Ninja.h"

namespace Entidades
{
	namespace Personagens
	{
		Ninja::Ninja(
			sf::Vector2f pos,
			sf::Vector2f tam,
			const std::string& textura,
			sf::Vector2f v, float e, int n, int nm,
			int _id):

			Inimigo(pos, tam, textura, v, e, n, nm, _id), projetil(NULL), coolDownTiro(0.f), precisao(0.f)
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
				setCooldownTiro(5.f - precisao);
			}
		}

		void Ninja::danificar(Jogador* p) 
		{
			if (p->getTempoInvulneravel() <= 0.f) {
				precisao += 0.3f;

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
			mover();
			atirar();
			gravitar();

			body.move(
				(velocidade.x + velocidadeKnockback.x) * getTempo(),
				(velocidade.y + velocidadeKnockback.y) * getTempo()
			);

			atualizarCooldowns();
			desenhar();

		}
		void Ninja::salvarDataBuffer()
		{
			Inimigo::salvarDataBuffer();

			buffer << coolDownTiro << ' '
				<< precisao
				<< std::endl;
		}
		void Ninja::salvar()
		{
			bufferInterno.str("");
			buffer.clear();
			salvarDataBuffer();
		}

		void Ninja::carregar(std::istream& in)
		{
			Inimigo::carregar(in);

			in >> coolDownTiro;
			in >> precisao;
			projetil = NULL;
		}
	}
}