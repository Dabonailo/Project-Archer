#include "GerenciadorEventos.h"

namespace Gerenciadores {

	GerenciadorEventos* GerenciadorEventos::pEventos = NULL;
	GerenciadorGrafico* GerenciadorEventos::pGrafico = GerenciadorGrafico::getGerenciadorGrafico();

	GerenciadorEventos::GerenciadorEventos() :pJog(NULL), pJog2(NULL), menu(NULL)
	{
	}

	GerenciadorEventos::~GerenciadorEventos()
	{
	}

	GerenciadorEventos* GerenciadorEventos::getGerenciadorEventos()
	{
		if (pEventos == NULL) {
			pEventos = new GerenciadorEventos();
		}
		return pEventos;
	}

	void GerenciadorEventos::setJogador(Entidades::Personagens::Jogador* pJ) {
		if (!pJog) {
			pJog = pJ;
		}
		else if (!pJog2) {
			pJog2 = pJ;
		}
	}

	void GerenciadorEventos::deletarJogadores()
	{
		pJog = NULL;
		pJog2 = NULL;
	}

	void GerenciadorEventos::setMenu(Menu* m)
	{
		menu = m;
	}

	void GerenciadorEventos::verificaTeclaPressionada(sf::Keyboard::Key tecla)
	{
		if (pJog && pJog->getVivo()) {
			if (tecla == sf::Keyboard::D) {
				pJog->setMovDir(true);
				pJog->setDirecao(DIREITA);
			}

			if (tecla == sf::Keyboard::A) {
				pJog->setMovEsq(true);
				pJog->setDirecao(ESQUERDA);
			}

			if (tecla == sf::Keyboard::W) {
				pJog->pular();
			}

			if (tecla == sf::Keyboard::Q) {
				if (pJog->getCooldownTiro() <= 0.f && !pJog->getProjetilAtivo()) {
					pJog->atirar();
					pJog->setCooldownTiro(1.f);
				}
			}

			if (tecla == sf::Keyboard::Escape) {
				menu->mudarMenu(MENU_PAUSA);
			}
		}

		if (pJog2 && pJog2->getVivo()) {
			if (tecla == sf::Keyboard::Right) {
				pJog2->setMovDir(true);
				pJog2->setDirecao(DIREITA);
			}

			if (tecla == sf::Keyboard::Left) {
				pJog2->setMovEsq(true);
				pJog2->setDirecao(ESQUERDA);
			}

			if (tecla == sf::Keyboard::Up) {
				pJog2->pular();
			}

			if (tecla == sf::Keyboard::Space) {
				if (pJog2->getCooldownTiro() <= 0.f && !pJog->getProjetilAtivo()) {
					pJog2->atirar();
					pJog2->setCooldownTiro(1.f);
				}
			}

			if (tecla == sf::Keyboard::Escape) {
				menu->mudarMenu(MENU_PAUSA);
			}
		}

		if (menu && menu->getTipoMenu() == MENU_PRINCIPAL ||
			menu->getTipoMenu() == MENU_PAUSA ||
			menu->getTipoMenu() == MENU_FASES ||
			menu->getTipoMenu() == MENU_GAME_OVER ||
			menu->getTipoMenu() == MENU_JOGADORES ||
			menu->getTipoMenu() == MENU_SALVAR_PONTUACAO ||
			menu->getTipoMenu() == MENU_RANKING
			)
		{
			if (tecla == sf::Keyboard::Up) {
				menu->selecionarBotoes(CIMA);
			}
			if (tecla == sf::Keyboard::Down) {
				menu->selecionarBotoes(BAIXO);
			}
			if (tecla == sf::Keyboard::Enter) {
				menu->executarBotao();
			}
		}
	}

	void GerenciadorEventos::verificaTeclaSolta(sf::Keyboard::Key tecla)
	{
		if (pJog)
		{
			if (tecla == sf::Keyboard::D)
				pJog->setMovDir(false);

			if (tecla == sf::Keyboard::A)
				pJog->setMovEsq(false);
		}

		if (pJog2)
		{
			if (tecla == sf::Keyboard::Right)
				pJog2->setMovDir(false);

			if (tecla == sf::Keyboard::Left)
				pJog2->setMovEsq(false);
		}
	}

	void GerenciadorEventos::executar() {
		sf::Event evento;
		while (pGrafico->getWindow()->pollEvent(evento))
		{
			if (evento.type == sf::Event::Closed)
				pGrafico->fecharJanela();

			else if (evento.type == sf::Event::KeyPressed)
			{
				verificaTeclaPressionada(evento.key.code);
			}

			else if (evento.type == sf::Event::KeyReleased)
			{
				verificaTeclaSolta(evento.key.code);
			}

			else if(evento.type == sf::Event::TextEntered)
			{
				if (menu && menu->getTipoMenu() == MENU_SALVAR_PONTUACAO)
					menu->digitarNome(evento.text.unicode);
			}
		}
	}
}