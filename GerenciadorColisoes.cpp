#include "GerenciadorColisoes.h"

namespace Gerenciadores
{

	GerenciadorColisoes::GerenciadorColisoes() :jogador1(NULL), jogador2(NULL), LIs(), LOs()
	{
	}

	GerenciadorColisoes::~GerenciadorColisoes()
	{
	}

	const int GerenciadorColisoes::getTamanhoLIs() const
	{
		return LIs.size();
	}

	const int GerenciadorColisoes::getTamanhoLOs() const
	{
		return LOs.size();
	}

	const bool GerenciadorColisoes::verificarColisao(Entidades::Entidade* pE1, Entidades::Entidade* pE2) const
	{
		sf::FloatRect pe1Bounds = pE1->getBounds();
		sf::FloatRect pe2Bounds = pE2->getBounds();

		if (pe1Bounds.intersects(pe2Bounds)) {
			return true;
		}
		else {
			return false;
		}
	}

	void GerenciadorColisoes::incluirJogadores(Entidades::Personagens::Jogador* pJ)
	{
		if (Entidades::Personagens::Jogador* j = dynamic_cast<Entidades::Personagens::Jogador*>(pJ)) {
			if (jogador1 == NULL) {
				jogador1 = j;
			}
			else if (jogador2 == NULL) {
				jogador2 = j;
			}
		}
	}

	void GerenciadorColisoes::incluirInimigo(Entidades::Personagens::Inimigo* pI)
	{
		if (Entidades::Personagens::Inimigo* in = dynamic_cast<Entidades::Personagens::Inimigo*>(pI)) {
			LIs.push_back(in);
		}
	}

	void GerenciadorColisoes::incluirObstaculo(Entidades::Obstaculos::Obstaculo* pO)
	{
		if (Entidades::Obstaculos::Obstaculo* ob = dynamic_cast<Entidades::Obstaculos::Obstaculo*>(pO)) {
			LOs.push_back(ob);
		}
	}

	void GerenciadorColisoes::tratarColisoesJogsInimigs()
	{
		for (std::vector<Entidades::Personagens::Inimigo*>::iterator it = LIs.begin(); it != LIs.end(); ++it) {
			if (jogador1 != NULL) {
				if (verificarColisao((*it), jogador1)) {
					(*it)->danificar(jogador1);

					if (!jogador1->getVivo()) {
						jogador1 = NULL;
						std::cout << "jogador 1 foi nocauteado" << std::endl;
					}
					if (jogador1) {
						std::cout << jogador1->getVida() << std::endl;
					}
				}
			}
			if (jogador2 != NULL) {
				if (verificarColisao((*it), jogador2)) {
					(*it)->danificar(jogador2);

					if (!jogador2->getVivo()) {
						jogador2 = NULL;
						std::cout << "jogador 2 foi nocauteado" << std::endl;
					}
					if (jogador2) {
						std::cout << jogador2->getVida() << std::endl;
					}
				}
			}
		}
	}

	void GerenciadorColisoes::tratarColisoesJogsObstacs()
	{
		for (std::list<Entidades::Obstaculos::Obstaculo*>::iterator it = LOs.begin(); it != LOs.end(); ++it) {
			if (jogador1 != NULL) {
				if (verificarColisao((*it), jogador1)) {
					(*it)->obstaculizar(jogador1);
				}
			}
			if (jogador2 != NULL) {
				if (verificarColisao((*it), jogador2)) {
					(*it)->obstaculizar(jogador2);
				}
			}
		}
	}

	void GerenciadorColisoes::executar() {
		tratarColisoesJogsInimigs();
		tratarColisoesJogsObstacs();
	}

}
