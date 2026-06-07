#include "Personagem.h"

namespace Entidades
{
	namespace Personagens
	{

		Personagem::Personagem(sf::Vector2f pos, sf::Vector2f tam, const std::string& textura, sf::Vector2f v)
			: Entidade(pos, tam, textura, v), numVidas(5),
			velocidadeKnockback(sf::Vector2f(0.f, 0.f)),
			cooldownKnockback(0.f),
			esquerda(false),
			direita(true),
			tempoInvulneravel(0.f),
			tempoNoChao(0.f)
		{
		}

		Personagem::~Personagem()
		{
		}

		const int Personagem::getVida() const
		{
			return numVidas;
		}

		const bool Personagem::getVivo() const
		{
			if (getVida() > 0) {
				return true;
			}
			else {
				return false;
			}
		}

		void Personagem::aplicarKnockback(sf::Vector2f forca)
		{
			velocidadeKnockback += forca;
			cooldownKnockback = 1.2f;
		}
	
		void Personagem::recebeDano(int dano)
		{
			numVidas -= dano;
			if (getVida() >= 0) {
				std::cout << "vida: " << getVida() << std::endl;
			}
		}

		const float Personagem::getTempoInvulneravel() const
		{
			return tempoInvulneravel;
		}

		void Personagem::setTempoInvulneravel(float t)
		{
			tempoInvulneravel = t;
		}

		void Personagem::setDirecao(Direcao d)
		{
			if (d == Direcao::ESQUERDA) {
				esquerda = true;
				direita = false;
			}
			else if (d == Direcao::DIREITA) {
				direita = true;
				esquerda = false;
			}
		}

		Direcao Personagem::getDirecao()
		{
			if (direita) {
				return DIREITA;
			}
			if (esquerda) {
				return ESQUERDA;
			}
			else {
				return DIREITA;
			}
		}
	}
}