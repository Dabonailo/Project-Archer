#include "GerenciadorColisoes.h"

namespace Gerenciadores
{

	GerenciadorColisoes::GerenciadorColisoes() :jogador1(NULL), jogador2(NULL), LIs(), LOs(), LPs()
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

	void GerenciadorColisoes::incluirProjetil(Entidades::Projetil* pPr)
	{
		if (Entidades::Projetil* pr = dynamic_cast<Entidades::Projetil*>(pPr)) {
			LPs.insert(pPr);
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
				}
			}
			if (jogador2 != NULL) {
				if (verificarColisao((*it), jogador2)) {
					(*it)->danificar(jogador2);

					if (!jogador2->getVivo()) {
						jogador2 = NULL;
						std::cout << "jogador 2 foi nocauteado" << std::endl;
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

	void GerenciadorColisoes::tratarColisoesInimigsObstacs()
	{
		for (std::vector<Entidades::Personagens::Inimigo*>::iterator itI = LIs.begin(); itI != LIs.end(); ++itI) {
			for (std::list<Entidades::Obstaculos::Obstaculo*>::iterator itO = LOs.begin(); itO != LOs.end(); ++itO) {
				if (verificarColisao((*itI), (*itO))) {
					(*itO)->obstaculizar(*itI);
				}
			}
		}
	}

	void GerenciadorColisoes::tratarColisaoChao(Entidades::Entidade* pEnt)
	{
		if (!pEnt)
			return;

		float metadeAltura = pEnt->getTamanho().y / 2.f;
		float bottom = pEnt->getPosicao().y + metadeAltura;

		// CORREÇÃO: Só colide com o chão se o personagem NÃO estiver subindo (vel.y >= 0)
		if (bottom >= CHAO && pEnt->getVelocidade().y >= 0.f)
		{
			pEnt->setPosicao(sf::Vector2f(
				pEnt->getPosicao().x,
				CHAO - metadeAltura
			));

			sf::Vector2f vel = pEnt->getVelocidade();
			vel.y = 0.f;
			pEnt->setVelocidade(vel);

			pEnt->setnoChao(true);

			if (Entidades::Projetil* pPr = dynamic_cast<Entidades::Projetil*>(pEnt)) {
				pPr->setAtivo(false);
			}
		}
	}

	void GerenciadorColisoes::tratarColisaoEntsChao()
	{
		if (jogador1 != NULL) {
			jogador1->setnoChao(false);
			tratarColisaoChao(jogador1);
		}
		if (jogador2 != NULL) {
			jogador2->setnoChao(false);
			tratarColisaoChao(jogador2);
		}
		for (std::vector<Entidades::Personagens::Inimigo*>::iterator it = LIs.begin(); it != LIs.end(); ++it) {
			(*it)->setnoChao(false);
			tratarColisaoChao(*it);
		}
		for (std::set<Entidades::Projetil*>::iterator it = LPs.begin(); it != LPs.end(); ++it) {
			(*it)->setnoChao(false);
			tratarColisaoChao(*it);
		}
	}

	void GerenciadorColisoes::tratarColisaoObstacProjetil()
	{
		for (std::list<Entidades::Obstaculos::Obstaculo*>::iterator itO = LOs.begin(); itO != LOs.end(); ++itO) {
			for (std::set<Entidades::Projetil*>::iterator itP = LPs.begin(); itP != LPs.end(); ++itP) {
				if (verificarColisao((*itO), (*itP)) && (*itP)->getAtivo()) {
					(*itP)->cravarProjetil((*itO));
				}
			}
		}
	}

	void GerenciadorColisoes::tratarColisaoInimigsProjetil()
	{
		for (std::vector<Entidades::Personagens::Inimigo*>::iterator itI = LIs.begin(); itI != LIs.end(); ) {
			bool removerinimigo = false;

			for (std::set<Entidades::Projetil*>::iterator itP = LPs.begin(); itP != LPs.end(); ++itP) {
				if (verificarColisao((*itI), (*itP)) && (*itP)->getAtivo()) {
					(*itP)->cravarProjetil((*itI));
					jogador1->colidir((*itI));
					if (!(*itI)->getVivo()) {
						removerinimigo = true;
						break;
					}
				}
			}
			if (removerinimigo) {
				itI = LIs.erase(itI);
			}
			else {
				++itI;
			}
		}
	}

	void GerenciadorColisoes::executar() {
		tratarColisaoEntsChao();
		tratarColisoesJogsInimigs();
		tratarColisoesJogsObstacs();
		tratarColisoesInimigsObstacs();	
		tratarColisaoObstacProjetil();
		tratarColisaoInimigsProjetil();
	}

}
