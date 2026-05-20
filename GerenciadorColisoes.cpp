#include "GerenciadorColisoes.h"

GerenciadorColisoes::GerenciadorColisoes():jogador1(NULL), jogador2(NULL), LIs()
{
}

GerenciadorColisoes::~GerenciadorColisoes()
{
}

void GerenciadorColisoes::setEntidades(ListaEntidades& l)
{
	l.percorrerLista(*this);
}

const bool GerenciadorColisoes::verificarColisao(Entidade* pE1, Entidade* pE2) const
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

void GerenciadorColisoes::incluirInimigo(Inimigo* in)
{
	LIs.push_back(in);
}

void GerenciadorColisoes::tratarColisoesJogsInimigs()
{
	for (std::vector<Inimigo*>::iterator it = LIs.begin(); it != LIs.end(); ++it) {
		if (jogador1 != NULL) {
			if (verificarColisao((*it), jogador1)) {
				(*it)->danificar(jogador1);
				std::cout << jogador1->getVida();
			}
		}
	}
}

void GerenciadorColisoes::executar() {
	tratarColisoesJogsInimigs();
}


