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

	void GerenciadorEventos::setJogador(Entidades::Jogador* pJ) {
		pJog = pJ;
	}

	void GerenciadorEventos::verificaTeclaPressionada(sf::Keyboard::Key tecla)
	{
		if (tecla == sf::Keyboard::A) {

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
				if (evento.key.code == sf::Keyboard::Escape) {
					pGrafico->fecharJanela();
				}
			}
		}
	}
}