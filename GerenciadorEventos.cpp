#include "GerenciadorEventos.h"

namespace Gerenciadores {

	GerenciadorEventos* GerenciadorEventos::pEventos = NULL;
	GerenciadorGrafico* GerenciadorEventos::pGrafico = GerenciadorGrafico::getGerenciadorGrafico();

	GerenciadorEventos::GerenciadorEventos() :pJog(NULL)
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
		pJog = pJ;
	}

	void GerenciadorEventos::setMenu(Menu* m)
	{
		menu = m;
	}

	void GerenciadorEventos::verificaTeclaPressionada(sf::Keyboard::Key tecla)
	{
		if (pJog) {
			if (tecla == sf::Keyboard::D)
				pJog->setMovDir(true);

			if (tecla == sf::Keyboard::A)
				pJog->setMovEsq(true);

			if (tecla == sf::Keyboard::Space) {
				pJog->pular();
			}
			
			if (tecla == sf::Keyboard::Escape) {
				menu->mudarMenu(MENU_PAUSA);
			}
		}

		if (menu && menu->getTipoMenu() == MENU_PRINCIPAL || menu->getTipoMenu() == MENU_PAUSA) {
			if (tecla == sf::Keyboard::W || tecla == sf::Keyboard::PageUp) {
				menu->selecionarBotoes(CIMA);
			}
			if (tecla == sf::Keyboard::S || tecla == sf::Keyboard::PageDown) {
				menu->selecionarBotoes(BAIXO);
			}
			if (tecla == sf::Keyboard::Enter) {
				menu->executarBotao();
			}
		}
	}

	void GerenciadorEventos::verificaTeclaSolta(sf::Keyboard::Key tecla)
	{
		if (tecla == sf::Keyboard::D)
			pJog->setMovDir(false);

		if (tecla == sf::Keyboard::A)
			pJog->setMovEsq(false);	
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
		}
	}
}