#include "GerenciadorColisoes.h"

GerenciadorColisoes::GerenciadorColisoes():jogador(nullptr), LIs()
{
}

GerenciadorColisoes::~GerenciadorColisoes()
{
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


